#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		long long p,q,b;scanf("%lld%lld%lld",&p,&q,&b);
		ll g=gcd(p,q);
		p/=g,q/=g;
		g=gcd(q,b);
		while(g>1){
			while(q%g==0)q/=g;
			g=gcd(q,b);
		}
		if(q>1)puts("Infinite");
		else puts("Finite");
	}
}