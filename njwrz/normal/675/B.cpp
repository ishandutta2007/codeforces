#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ma=0,mi=1000000;
void f(ll a1,ll a2){
	ma=max(ma,a1+a2);
	mi=min(mi,a1+a2);
}
int main(){
	ll n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	f(a,b);f(a,c);f(b,d);f(c,d);
	if(ma-mi>=n)cout<<0;else cout<<(n-ma+mi)*n;
	return 0;
}