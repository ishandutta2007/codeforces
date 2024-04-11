#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[500005],e2[500005];
int n,m,s,h[200005],f[200005],vis[200005],h2[200005],t,t2;
ll g[200005],tans=0,mx=0,a[200005];
int q[200005],head,tail,te[200005][2];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void add2(int u,int v)
{
	//printf("u=%d,v=%d\n",u,v);
	e2[++t2].v=v;
	e2[t2].nxt=h2[u];
	h2[u]=t2;
}
/*void dfs(int u)
{
	vis[u]=1;
	tans+=a[u];
	mx=max(mx,g[u]);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		dfs(v);
	}
}*/
void dfs(int u,int fa)
{
	//printf("u=%d,fa=%d\n",u,fa);
	g[u]=0;
	for(int i=h2[u];i;i=e2[i].nxt)
	{
		int v=e2[i].v;
		if(v==fa) continue;
		dfs(v,u);
		g[u]=max(g[u],g[v]);
	}
	g[u]+=a[u];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		f[u]++,f[v]++;
		add(u,v);
		add(v,u);
		te[i][0]=u,te[i][1]=v;
	}
	scanf("%d",&s);
	head=0,tail=0;
	for(int i=1;i<=n;i++)
		if(f[i]<=1)
			q[++tail]=i,vis[i]=1;
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			f[v]--;
			//g[v]=max(g[v],g[u]+a[u]);
			if(f[v]<=1&&!vis[v])
			{
				q[++tail]=v;
				vis[v]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			a[n+1]+=a[i];
			//printf("%I64d\n",a[n+1]);
		}
	//for(int i=1;i<=n;i++)
	//	printf("%d",vis[i]);
	//printf("\n");
	for(int i=1;i<=m;i++)
	{
		int u=te[i][0],v=te[i][1];
		//printf("---u=%d,v=%d\n",u,v);
		if(!vis[u]) u=n+1;
		if(!vis[v]) v=n+1;
		if(!vis[u]&&!vis[v]) continue;
		add2(u,v),add2(v,u);
	}
	if(!vis[s]) s=n+1;
	dfs(s,0);
	tans=g[s];
	dfs(n+1,0);
	tans=max(tans,g[n+1]);
	//for(int i=1;i<=n+1;i++)
	//	printf("%I64d ",a[i]);
	printf("%I64d",tans);
	return 0;
}