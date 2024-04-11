#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 5005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n;
vector<int>g[MN];
ll f[MN][MN],ans;
int siz[MN],faz[MN];
void calc(int u,int fz,int V,int U){
	if(f[u][U]==-1)f[U][u]=f[u][U]=siz[u]*(n-siz[V])+max(f[fz][U],f[u][V]);
	for(auto v:g[u])if(v!=fz)calc(v,u,V,U);
}
void DFS(int u,int fz){
	faz[u]=fz;
	siz[u]=1;
	for(auto v:g[u])if(v!=fz){
		DFS(v,u);
		siz[u]+=siz[v];
		f[u][v]=f[v][u]=siz[v]*(n-siz[v]);
		calc(v,u,v,u);
	}
}
ll DP(int u,int v){
	if(f[u][v]!=-1)return f[u][v];
	return f[v][u]=f[u][v]=siz[u]*siz[v]+max(DP(faz[u],v),DP(u,faz[v]));
}
int main(){int x,y;
	scanf("%d",&n);
	F(i,2,n)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
	memset(f,-1,sizeof f);
	DFS(1,0);
	F(i,1,n-1)F(j,i+1,n)ans=max(ans,DP(i,j));
	printf("%lld\n",ans);
	return 0;
}