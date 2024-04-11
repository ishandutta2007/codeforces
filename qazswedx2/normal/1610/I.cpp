#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[2000005];
int n,h[500005],t,vis[500005],dp[500005],f[500005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	f[u]=fa;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		dp[u]^=dp[v];
	}
	dp[u]++;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	int ans=0,ct=0;
	for(int i=1;i<=n;i++)
	{
		int u=i;
		while(u&&!vis[u])
		{
			vis[u]=1;
			ct++;
			ans^=dp[u]-1;
			if(u!=1) ans^=dp[u];
			u=f[u];
		}
		int nw=ans^((ct+1)%2);
		if(nw) printf("1");
		else printf("2");
	}
	return 0;
}