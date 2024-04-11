#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[2000005],e2[2000005];
int n,m,h[500005],h2[500005],t,t2,vis1[1000005],vis2[1000005],f[1000005],tans[1000005];
int q[1000005],head,tail;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
	f[v]++;
}
void add2(int u,int v)
{
	e2[++t2].v=v;
	e2[t2].nxt=h2[u];
	h2[u]=t2;
}
void dfs1(int u)
{
	vis1[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(vis1[v]) continue;
		dfs1(v);
	}
}
void dfs2(int u)
{
	vis2[u]=1;
	for(int i=h2[u];i;i=e2[i].nxt)
	{
		int v=e2[i].v;
		if(vis2[v]) continue;
		dfs2(v);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add2(v,u);
		//vis[max(u,v)]=1;
	}
	for(int i=1;i<=n;i++)
		if(!f[i])
			q[++tail]=i;
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			f[v]--;
			if(!f[v]) q[++tail]=v;
		}
	}
	if(head!=n)
	{
		printf("-1");
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis1[i]&&!vis2[i])
		{
			tans[i]=1;
			ans++;
		}
		if(!vis1[i]) dfs1(i);
		if(!vis2[i]) dfs2(i);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		if(tans[i]) printf("A");
		else printf("E");
	return 0;
}