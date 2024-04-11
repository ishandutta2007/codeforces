#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b-1);i>=a;i--)
#define ll long long
using namespace std;
ll gcd(ll x,ll y){
	if(y==0)return x;
	return gcd(y,x%y);
}
int main()
{
	ll n,m,q,d,a,b,x,y,k1,k2;
	cin>>n>>m>>q;
	d=gcd(n,m);
	n=n/d;m=m/d;
	rep(i,0,q){
		cin>>a>>x>>b>>y;
		if(a==1){
			k1=x/n;
			if(x%n)k1++;
		}
		else{
			k1=x/m;
			if(x%m)k1++;
		}
		if(b==1){
			k2=y/n;
			if(y%n)k2++;
		}
		else{
			k2=y/m;
			if(y%m)k2++;
		}
		if(k1==k2)cout<<"YES\n";
		else cout<<"NO\n";
	}
 }