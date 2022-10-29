#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
#define fi first
#define se second

const int Mod=998244353;
ll Fast(ll x,int b) {
	ll t=1;
	for(; b; b>>=1,x=x*x%Mod) {
		if(b&1) t=t*x%Mod;
	}
	return t;
}
const int N=1e6+50;
const int Base=233;

ll f[N];
void solve() {
	int n,C;
	scanf("%d%d",&n,&C);
	FOR(i,1,C) f[i]=0;
	FOR(i,1,n) {
		int c,d,h;
		scanf("%d%d%d",&c,&d,&h);
		f[c]=max(f[c],1ll*d*h);
	}
	FOR(i,1,C) {
		for(int j=i+i; j<=C; j+=i) {
			f[j]=max(f[j],f[i]*(j/i));
		}
	}
	FOR(i,1,C) f[i]=max(f[i],f[i-1]);
	int m;
	scanf("%d",&m);
	FOR(i,1,m) {
		ll d,h;
		scanf("%lld%lld",&d,&h);
		ll v=1ll*d*h;
		int r=upper_bound(f+1,f+C+1,v)-f;
		if(r>C) r=-1;
		printf("%d%c",r," \n"[i==m]);
	}
}
int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}