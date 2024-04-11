#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
int main(){
	ll t=0,n,m,p;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];t+=a[i];
	}
	for(ll i=1;i<=n;i++){
		p=0;
		if(m-n+1<a[i])p+=a[i]+n-m-1;
		if(a[i]+m-t-1>=0)p+=m-t+a[i]-1;
		cout<<p<<' ';
	}
	return 0;
}