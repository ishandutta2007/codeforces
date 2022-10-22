#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pb push_back()
#define all(a) a.begin(),a.end()
using namespace std;
ll a[400005];
ll gcd(ll x,ll y){
	ll r;
	while(y){
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}
int main(){
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	ll t=a[1];
	for(ll i=2;i<=n;i++){
		if(a[i]%t!=0){
			t=gcd(t,a[i]);
		}
	}
	ll ans=0;
	for(ll i=1;i*i<=t;i++){
		if(t%i==0){
			if(i*i!=t){
				ans=ans+2;
			}else ans=ans+1;
		}
	}
	cout<<ans;
	return 0;
}