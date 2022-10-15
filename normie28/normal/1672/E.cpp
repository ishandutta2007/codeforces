#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
int l,r,mid;
int main()
{
	cin>>n;
	l=1; r=1e7; // binsearch for text length (w/ space)
	while(l<r) {
		mid=(l+r)/2;
		cout<<"? "<<mid<<endl;
		cin>>u;
		if (u==1) r=mid; else l=mid+1;
	}
	a=l;
	// magic!
	for (i=2;i<=n;i++) {
		cout<<"? "<<l/i<<endl;
		cin>>u;
		if (u) a=min(a,u*(l/i));
	}
	cout<<"! "<<a<<endl;
}
// a;