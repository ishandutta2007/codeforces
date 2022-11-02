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
	int n,m,t=0;
	cin >> n >> m;
	int l[n],r[n],ans[m];
	for (int i=0; i<n; i++){
		cin>>l[i]>>r[i];
	}
	for (int i=1; i<=m; i++){
		int T=0;
		for (int j=0; j<n; j++){
			if (in(l[j],r[j],i)){
				T++;

			}
		}
		if (T==0){
			ans[t]=i;
			t++;
		}
	}
	cout<<t<<endl;
	for (int i=0; i<t; i++){
		cout<<ans[i]<<' ';
	}
}