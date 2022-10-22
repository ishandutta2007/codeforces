#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll jc(ll p,ll k){
	if(!k)return 1;
	ll t=jc(p,k/2);
	t=t*t%1000000007;
	if(k%2==1)t=t*p%1000000007;
	return t;
}
int main(){
	ll n,m,ans=1;
	cin>>n>>m;
	ll t=n;
	for(ll i=2;i*i<=t;i++){
		if(n%i==0){
			ll i2=0,i1=i;
			while(n%i==0){
				n/=i;
			}
			while(i1<=m){
				i2=i2+m/i1;
				if(m/i1<i)break;
				i1*=i;
			}
			ans=ans*jc(i,i2)%1000000007;
		}
	}
	if(n>1){
		ll i=n;
		if(n%i==0){
			ll i2=0,i1=i;
			while(n%i==0){
				n/=i;
			}
			while(i1<=m){
				i2=i2+m/i1;
				if(m/i1<i)break;
				i1*=i;
			}
			ans=ans*jc(i,i2)%1000000007;
		}
	}
	cout<<ans;
	return 0;
}