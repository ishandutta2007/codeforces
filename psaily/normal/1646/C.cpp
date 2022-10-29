#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int Mod=1e9+7;
const int N=1e6+50;
ll Fac[N];
ll f[N];
void solve() {
	ll n;
	scanf("%lld",&n);
	int res=100;
	FOR(i,0,(1<<12)-1) {
		ll x=n;
		int c=0;
		FOR(j,0,11) if((1<<j)&i) x-=f[j],++c;
		if(x<0) continue;
		while(x) ++c,x^=x&-x;
		res=min(res,c);
	}
	printf("%d\n",res);
}
int main() {
	ll n=1e12;
	Fac[0]=1;
	FOR(i,1,14) {
		Fac[i]=Fac[i-1]*i;
	}
	FOR(i,0,11) f[i]=Fac[i+3];
    int T;
    scanf("%d",&T);
    while(T--) solve();
    
    return 0;
}