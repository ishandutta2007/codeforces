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
int main(){
	int t;
	cin >> t;
	for (int i=0; i<t; i++){
		int n,x,a,b;
		cin>>n>>x>>a>>b;
		if (b>a){
			swap(b,a);
		}
		while(b>1 and x>0){
			b--;
			x--;
		}
		while (a<n and x>0){
			a++;
			x--;
		}
		cout<<a-b<<endl;
	}
}