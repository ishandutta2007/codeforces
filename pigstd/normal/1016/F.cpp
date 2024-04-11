#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=3e5+10;
int n,m,dis[M],fa[M],cnt,fff;
int sz[M],k[M],vis[M],d[M],smax[M];
vector<pair<int,int> >e[M];

void dfs1(int u,int f)
{
	fa[u]=f;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i].x,w=e[u][i].y;
		if (to==f)continue;
		dis[to]=dis[u]+w,dfs1(to,u);
	}
}

void dfs2(int u)
{
	sz[u]=1;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i].x,w=e[u][i].y;
		if (vis[to]||to==fa[u])continue;
		k[u]=w,dfs2(to),sz[u]+=sz[to];
	}
	if (sz[u]>=3)fff=1;
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		e[u].pb(mp(v,w)),e[v].pb(mp(u,w));
	}
	dfs1(1,0);int p=n;
	while(p)vis[p]=1,d[++cnt]=p,p=fa[p];
	for (int i=1;i<=cnt;i++)dfs2(d[i]);
	if (fff)
	{
		for (int i=1;i<=m;i++)
			cout<<dis[n]<<endl;
		return 0;
	}
	int maxn=0;smax[cnt+1]=-1e18;smax[cnt]=dis[d[cnt]]+k[d[cnt]];
	for (int i=cnt-1;i>=1;i--)
	{
		maxn=max(maxn,dis[n]-dis[d[i]]+k[d[i]]+smax[i+2]);
		if (sz[d[i]]>1||sz[d[i+1]]>1)
			maxn=max(maxn,dis[n]-dis[d[i]]+k[d[i]]+smax[i+1]);
		smax[i]=max(smax[i+1],dis[d[i]]+k[d[i]]);
	}
	for (int i=1;i<=m;i++)
	{
		int x=read();
		cout<<min(dis[n],maxn+x)<<endl;
	}
	return 0;
}