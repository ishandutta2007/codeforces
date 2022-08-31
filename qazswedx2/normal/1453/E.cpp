#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int tt,n,h[200005],t,ans,d[200005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep)
{
	d[u]=1e9;
	int mx=0,sd=0,ct=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
		d[u]=min(d[u],d[v]);
		if(d[v]>mx)
		{
			sd=mx;
			mx=d[v];
		}
		else if(d[v]>sd)
			sd=d[v];
		ct++;
	}
	if(d[u]==1e9) d[u]=dep;
	if(u!=1)
		ans=max(ans,mx-dep+1);
	else ans=max(ans,max(sd+1,mx));
}
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		t=0;
		for(int i=1;i<=n;i++)
			h[i]=d[i]=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		ans=0;
		dfs(1,0,0);
		printf("%d\n",ans);
	}
	return 0;
}