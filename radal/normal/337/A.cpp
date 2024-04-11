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
bool in(int l, int r, int n){
	if (n>=l and n<=r)
	return 1;
	return 0;
}
int main(){
	int n,m;
	cin >> n >> m;
	int a[m];
	for (int i=0; i<m; i++){
		cin>>a[i];
	}
	msort(0,m,a);
	//cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<' '<<a[3];
	int ans=a[m-1]-a[0];
	for (int i=0; i<m-n+1; i++){
		if (ans>a[i+n-1]-a[i]){
			ans=a[i+n-1]-a[i];
			//cout<<a[i+n-1]<<a[i]<<endl;
		}
	}
	cout << ans;
}