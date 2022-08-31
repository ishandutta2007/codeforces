#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[1000005];
int tt,n,m,h[500005],t,vis[500005],f[500005],ct,tans[500005],tot;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u)
{
	ct++;
	vis[u]=1;
	int fl=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(f[v]) fl=1;
	}
	if(!fl)
	{
		tans[++tot]=u;
		f[u]=1;
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(!vis[v]) dfs(v);
	}
}
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			h[i]=vis[i]=f[i]=0;
		t=ct=tot=0;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dfs(1);
		if(ct<n) printf("NO\n");
		else
		{
			printf("YES\n%d\n",tot);
			for(int i=1;i<=tot;i++)
				printf("%d ",tans[i]);
			printf("\n");
		}
	}
	return 0;
}