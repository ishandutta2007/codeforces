#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll a,b,x,y;
	cin>>a>>b>>x>>y;
	ll gcd=__gcd(x,y);
	x/=gcd;y/=gcd;
	ll ta=a/x,tb=b/y;
	ll t=min(ta,tb);
	cout<<t*x<<' '<<t*y;
	return 0;
}