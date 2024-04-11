#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,int e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n;
vector<int>G[MN];
ll f[MN],g[MN],h[MN];
void DFS(int u,int pa){
	f[u]=1,g[u]=1,h[u]=1;
	for(int v:G[u])if(v!=pa){
		DFS(v,u);
		ll tot0=f[v]+h[v]-g[v],tot1=f[v]+h[v];
		f[u]=f[u]*(tot0+tot1)%mod;
		g[u]=g[u]*tot0%mod;
		h[u]=h[u]*(tot0+f[v])%mod;
	}
//	printf("%d : (%lld, %lld, %lld)\n",u,f[u],g[u],h[u]);
}
int main(){
	scanf("%d",&n);
	F(i,2,n){int x,y;scanf("%d%d",&x,&y);G[x].pb(y),G[y].pb(x);}
	DFS(1,0);
	printf("%lld\n",((f[1]+h[1]-g[1]-1)%mod+mod)%mod);
	return 0;
}