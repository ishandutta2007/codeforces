#include <bits/stdc++.h>
#define ll long long int
using namespace std;

/*void msort(int l,int r,int* a){
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
};*/
const int N=2e5;
ll a[N];
int main(){
	ll t;
	cin >> t;
	for (ll i=0; i<t; i++){
		ll n,r,p=0,ans=0;
		cin >> n >> r;
		for (ll i=0; i<n; i++){
			cin >> a[i];
		}
		sort(a,a+n);
		for (ll i=0; i<n; i++){
			if (!i || (i && a[i] != a[i-1])){
				a[p] = a[i];
				p++;
			}
		}
		for (ll i=0; i<p; i++){
			ll x =a[i]/r;
			if (a[i]%r) x++;
			ans = max(ans,min(p-i,x));
			//cout << x << ' '<<ans <<' '<<a[i]<<endl;
		}
		cout<<ans<<endl;
	}
}