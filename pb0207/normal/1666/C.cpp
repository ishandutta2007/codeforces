#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
typedef long long ll;
ll x[3],y[3];
int main() {
	FOR(i,0,2) scanf("%lld%lld",&x[i],&y[i]);
	ll a=x[0]+x[1]+x[2];
	a-=max(x[0],max(x[1],x[2]))+min(x[0],min(x[1],x[2]));
	ll b=y[0]+y[1]+y[2];
	b-=max(y[0],max(y[1],y[2]))+min(y[0],min(y[1],y[2]));
	int c=0;
	FOR(i,0,2) {
		if(x[i]!=a) ++c;
		if(y[i]!=b) ++c;
	}
	printf("%d\n",c);
	FOR(i,0,2) {
		if(x[i]!=a) printf("%lld %lld %lld %lld\n",x[i],y[i],a,y[i]);
		if(y[i]!=b) printf("%lld %lld %lld %lld\n",a,y[i],a,b);
	}
	return 0;
}