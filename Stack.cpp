#include <iostream>
using namespace std;

template <typename T>
struct Stack {
	struct Node {
		Node(Node* pNext, T data) {
			this->pNext = pNext;
			this->data = data;
		}
		Node* pNext;
		T data;
	};
	Stack();
	int size();
	void insert(int,T);
	void erase(int);
	int search(T);
	void Write();
	void push(T);
	void pop();
	T top();
	Node* head;
	int Size;
};

template <typename T>
Stack<T>::Stack() {
	Size = 0;
	head = NULL;
}
template <typename T>
void Stack<T>::insert(int pos, T value) {
	if (pos == 0) {
		head = new Node((head==NULL)?NULL:head, value);
	}
	else {
		Node* temp = head;
		int ind = 0;
		while (ind+1 != pos) {
			temp = temp->pNext;
			ind++;
		}
		Node* node = new Node(temp->pNext, value);
		temp->pNext = node;
	}
	Size++;

}

template <typename T>
void Stack<T>::erase(int pos){
	if (pos == 0){
		Node* temp = head;
		head = head->pNext;
		delete temp;
	}
	else {
		int ind = 0;
		Node* temp = head;
		while(ind+1!=pos){
			temp = temp->pNext;
			ind++;
		}
		Node* t = temp->pNext;
		temp->pNext = t->pNext;
		delete t;
	}
	Size--;

}

template <typename T>
int Stack<T>::size() {
	return Size;
}

template <typename T>
void Stack<T>::Write() {
	Node* temp = head;
	while(temp!=NULL){
		cout << temp->data << " ";
		temp = temp->pNext;
	}
	cout << endl;
}

template <typename T>
int Stack<T>::search(T value){
	Node* temp = head;
	int ind = 0;
	while(temp!=NULL){
		if(temp->data == value){
			return ind;
		}
		ind++;
		temp = temp->pNext;
	}
	return -1;
}

template <typename T>
void Stack<T>::push(T value){
	this->insert(this->Size,value);
}

template <typename T>
void Stack<T>::pop(){
	this->erase(this->Size-1);
}

template <typename T>
T Stack<T>::top(){
	Node* temp = head;
	while(temp->pNext!=NULL){
		temp = temp->pNext;
	} 
	return temp->data;
}



int main()
{
	Stack<int> s;
	s.push(10);
	s.push(5);
	s.push(3);
	cout << s.top() << endl;
	s.pop();
	s.pop();
	cout << s.top() << endl;
	s.push(15);
	s.Write();
	cout << s.size() << endl;
	cout << s.search(10) << endl;
}
