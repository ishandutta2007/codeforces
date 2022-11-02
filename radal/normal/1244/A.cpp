#include <iostream>
using namespace std;
struct node{
	int val;
	node* p;
};

struct stack{
	node* top=NULL;
	int s=0;
	int topp(){
		if (s>0)
		return top->val;
		else
		return NULL;
	}
	void push(int x){
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
bool in(int l, int r, int n){
	if (n>=l and n<=r)
	return 1;
	return 0;
}
int main(){
	int q;
	cin >> q;
	for (int i=0; i<q; i++){
		int a,b,c,d,k;
		int t1=0,t2=0;
		cin>>a>>b>>c>>d>>k;
		while (a>0){
			a -= c;
			t1++;
		}
		while (b>0){
			b -= d;
			t2++;
		}
		if (t1+t2<=k){
			cout<<t1<<' '<<t2<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
}