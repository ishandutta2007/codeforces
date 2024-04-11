//AFO countdown:6 Days
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int n,m,sum[M],d[M];
int c[M],low[M],dfn[M],z[M],cnt,top,ti,vis[M];
vector<pair<int,int> >e[M];

void tarjan(int u)
{
	low[u]=dfn[u]=++ti,vis[u]=1,z[++top]=u;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i].x;
		if (!dfn[to])tarjan(to),low[u]=min(low[u],low[to]);
		else if (vis[to])low[u]=min(low[u],low[to]);
	}
	if (dfn[u]==low[u])
	{
		cnt++;
		while(u!=z[top])
			c[z[top]]=cnt,vis[z[top]]=0,top--;
		c[u]=cnt,vis[u]=0,top--;
	}
}

void dfs(int u)
{
	vis[u]=1;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i].x,w=e[u][i].y;
		if (c[to]!=c[u])continue;
		if (!vis[to])sum[to]=sum[u]+w,dfs(to);
		else d[c[u]]=__gcd(d[c[u]],sum[u]-sum[to]+w);
	}
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		e[u].pb(mp(v,w));
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i])tarjan(i);
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++)
		if (!vis[i])dfs(i);
	WT
	{
		int v=c[read()],s=read(),m=read();
//		cout<<d[v]<<' ';
		if (s%__gcd(d[v],m)==0)YES
		else NO
	}
	return 0;
}