#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],n,mini=10000000000000;
vector <ll> v;
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		mini=min(mini,a[i]);
	}
	for(ll i=1;i<=n;i++){
		if(a[i]==mini){
			v.push_back(i);
		}
	}
	v.push_back(v[0]+n);
	ll ans=0;
	for(ll i=0;i<v.size()-1;i++){
		ans=max(ans,v[i+1]-v[i]-1);
	}
	cout<<ans+mini*n;
	return 0;
}