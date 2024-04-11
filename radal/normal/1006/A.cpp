#include <iostream>
using namespace std;
//struct node{
//	char val;
//	node* p;
//};
/*
struct stack{
	node* top=NULL;
	int s=0;
	char topp(){
		if (s>0)
		return top->val;
		else
		return NULL;
	}
	void push(char x){
		node* a=new node;
		a->val=x;
		a->p=top;
		top=a;
		s++;
	}
	void pop(){
		if (s>1){
			top=top->p;
		}
		else{
			top=NULL;
		}
		s--;
	}
};*/

int main(){
	int n;
	cin>>n;
	//stack st;
	for (int i=0; i<n; i++){
		long int x;
		cin>>x;
		if (x%2 == 0){
			x--;
		}
		cout<<x<<' ';

	}
	
}