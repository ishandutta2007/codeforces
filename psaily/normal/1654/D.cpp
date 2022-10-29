#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second

const int N=1e6+50;
const int Mod=998244353;

ll Fast(ll x,int b) {
	ll t=1;
	for(; b; b>>=1,x=x*x%Mod) {
		if(b&1) t=t*x%Mod;
	}
	return t;
}
int gcd(int x,int y) {
	return y?gcd(y,x%y):x;
}
struct node {
	int x,a,b;
};
vector<node> E[N];
vector<int> G[N];
int A[N],B[N];
void dfs(int x,int fr) {
	for(auto e: E[x]) {
		int y=e.x;
		if(y==fr) continue;
		int v=e.a;
		for(auto w: G[e.a]) {
			while(v%w==0) v/=w,--A[w],B[w]=min(B[w],A[w]);
		}
		v=e.b;
		for(auto w: G[e.b]) {
			while(v%w==0) v/=w,++A[w];
		}
		dfs(y,x);
		v=e.a;
		for(auto w: G[e.a]) {
			while(v%w==0) v/=w,++A[w];
		}
		v=e.b;
		for(auto w: G[e.b]) {
			while(v%w==0) v/=w,--A[w];
		}
	}
}
ll res;
ll inv[N];
void rdfs(int x,int fr,ll v) {
	res=(res+v)%Mod;
	for(auto e: E[x]) {
		int y=e.x;
		if(y==fr) continue;
		rdfs(y,x,v*inv[e.a]%Mod*e.b%Mod);
	}
}
void solve() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) E[i].clear();
	FOR(i,2,n) {
		int x,y,a,b;
		scanf("%d%d%d%d",&x,&y,&a,&b);
		int g=gcd(a,b);
		a/=g;b/=g;
		E[x].push_back((node){y,a,b});
		E[y].push_back((node){x,b,a});
	}
	FOR(i,1,n) A[i]=B[i]=0;
	dfs(1,0);
	res=0;
	ll v=1;
	FOR(i,1,n) v=v*Fast(i,-B[i])%Mod;
	rdfs(1,0,v);
	printf("%lld\n",res);
}
int main() {
	int n=2e5;
	FOR(i,2,n) if(G[i].size()==0) {
		for(int j=i; j<=n; j+=i) {
			G[j].push_back(i);
		}
	}
	FOR(i,1,n) inv[i]=Fast(i,Mod-2);
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}