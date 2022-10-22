#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],b[200005],t[200005];
int main(){
	ll n,m,ans=0,l,r;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=m;i++){
		cin>>l>>r;
		b[l]++;b[r+1]--;
	}
	ll p=0;
	for(ll i=1;i<=n;i++){
		p+=b[i];
		t[i]=p;
	}
	sort(a+1,a+n+1);
	sort(t+1,t+n+1);
	for(ll i=1;i<=n;i++)ans=ans+t[i]*a[i];
	cout<<ans;
	return 0;
}