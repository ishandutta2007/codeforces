#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[5000005];
int nt,n,m,t,h[1000005],dfn[1000005],low[1000005],st[1000005],tp,cnt;
int vis[1000005],g[1000005],gt;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void tarjan(int u)
{
	dfn[u]=++cnt;
	low[u]=dfn[u];
	st[++tp]=u;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!vis[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		gt++;
		st[tp+1]=0;
		while(st[tp+1]!=u)
		{
			vis[st[tp]]=1;
			g[st[tp]]=gt;
			tp--;
		}
	}
}
int main()
{
	scanf("%d",&nt);
	while(nt--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(u==v) continue;
			add(u,v);
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i])
				tarjan(i);
		if(gt==1) printf("No\n");
		else
		{
			printf("Yes\n");
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(g[i]==1) cnt++;
			printf("%d %d\n",cnt,n-cnt);
			for(int i=1;i<=n;i++)
				if(g[i]==1) printf("%d ",i);
			printf("\n");
			for(int i=1;i<=n;i++)
				if(g[i]!=1) printf("%d ",i);
			printf("\n");
		}
		for(int i=1;i<=n;i++)
			g[i]=vis[i]=h[i]=dfn[i]=low[i]=0;
		gt=tp=cnt=t=0;
	}
	return 0;
}