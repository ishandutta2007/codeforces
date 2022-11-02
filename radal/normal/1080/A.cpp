#include <iostream>
#include <cmath>
using namespace std;
/*
void msort(int l,int r){
	if (r-l==1){
		return;
	}
	int mid = (l+r)/2;
	msort(l, mid);
	msort(mid, r);
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
			if (a[p1]>a[p2]){
				tt++;
				cout<<a[p1]<<a[p2]<<endl;
		}
		}
	}
	for (int i=l; i<r; i++){
		a[i]=b[i];
	}
}*/
int LCD (int a,int b){
	if (b>a){
		swap(a,b);
	}
	if (b == 0){
		return a;
	}
	else{
		return LCD(b,a%b);
	}
}
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
	long long int n,k,r,g,b,t=0;
	cin >> n >>k;
	r=2*n;
	g=5*n;
	b=8*n;
	if (r<=k){
		t+=1;
	}
	else{
		if (r%k == 0){
			t+=r/k;
		}
		else{
			t+=r/k+1;
		}
	}
	if (b<=k){
		t+=1;
	}
	else{
		if (b%k == 0){
			t+=b/k;
		}
		else{
			t+=b/k+1;
		}
	}
	if (g<=k){
		t+=1;
	}
	else{
		if (g%k == 0){
			t+=g/k;
		}
		else{
			t+=g/k+1;
		}
	}
	cout<<t;
}