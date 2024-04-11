#include <iostream>
using namespace std;
void msort(int l,int r,int* a){
	int b[10000];
	if (r-l==1){
		return;
	}
	int mid = (l+r)/2;
	msort(l, mid, a);
	msort(mid, r, a);
	int p1,p2;
	p1 = l;
	p2 = mid;
	for (int i=l; i<r; i++){
		if (p2>=r || (a[p1]<a[p2] and p1<mid)){
			b[i] = a[p1];
			p1++;
		}
		else{
			b[i] = a[p2];
			p2++;
		}
	}
	for (int i=l; i<r; i++){
		a[i]=b[i];
	}
}
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
bool in(int* a, int x, int n){
	for (int i=0; i<n; i++){
		if (a[i] == x){
			return 1;
		}
	}
	return 0;
}
int main(){
	int t;
	cin>>t;
	for (int i=0; i<t; i++){
		int n;
		cin>>n;
		int a[n],b[n];
		for (int i=0; i<n; i++){
			cin>>a[i];
		}
		for (int i=0; i<n; i++){
			cin>>b[i];
		}
		bool p=0,ne=0;
		string ans="YES";
		for (int i=0; i<n; i++){
			if (a[i]<b[i] and p == 0){
				ans="NO";
			}
			if (a[i]>b[i] and ne == 0){
				ans = "NO";
			}
			if (a[i] == 1){
				p=1;
			}
			if (a[i] == -1){
				ne=1;
			}
		}
		cout<<ans<<endl;
	}
}