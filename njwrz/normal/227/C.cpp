#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll m;
ll dfs(ll p){
	if(p<1000){
		ll re=1;
		for(ll i=0;i<p;i++){
			re*=3;re%=m;
		}
		return re;
	}
	ll t=dfs(p/1000),re=1;
	for(ll i=0;i<1000;i++){
		re*=t;re%=m;
	}
	for(ll i=0;i<p%1000;i++){
		re*=3;re%=m;
	}
	return re;
}
int main(){
	ll n;
	cin>>n>>m;
	cout<<(dfs(n)-1+m)%m<<'\n';
	return 0;
}