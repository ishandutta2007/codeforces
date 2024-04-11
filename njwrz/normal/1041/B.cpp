#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll x,ll y){
	ll r;
	while(y!=0){
		r=x%y;
		x=y;y=r;
	}
	return x;
}
int main(){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll t=gcd(c,d);
	c/=t;d/=t;
	if(a/c>b/d)cout<<b/d;else cout<<a/c;
	return 0;
}