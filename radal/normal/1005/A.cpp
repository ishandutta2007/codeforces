#include <iostream>
using namespace std;
struct node{
	char val;
	node* p;
};

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
};
int b[1000];
int main(){
	int n,t=0,j=0;
	cin>>n;
	int a[n];
	stack st;
	for (int i=0; i<n; i++){
		cin>>a[i];
		if (a[i]==1){
			t+=1;
			if (i!=0){
				b[j] = a[i-1]; 
				j++;
			}
		}
	}
	cout<<t<<endl;
	b[j] = a[n-1];
	for (int i=0; i<=j; i++){
		cout<<b[i]<<' ';
	}
	
}