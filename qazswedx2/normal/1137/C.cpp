#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[5000005];
struct edge1
{
	int u,v;
}e1[5000005];
int n,m,d,h[5000005],t=0,val[5000005],g[5000005],vis[5000005],gt=0;
int st[5000005],tp=0,dfn[5000005],low[5000005],cnt=0,in[5000005];
int q[5000005],head,tail,f[5000005],tt;
char s[105];
void add(int u,int v)
{
	//printf("<%d,%d>\n",u,v);
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
	e1[t].u=u;
	e1[t].v=v;
}
void tarjan(int u)
{
	st[++tp]=u;
	low[u]=dfn[u]=++cnt;
	vis[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(!vis[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]==1)
			low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		gt++;
		st[tp+1]=0;
		while(st[tp+1]!=u)
		{
			g[st[tp]]=gt;
			vis[st[tp]]=2;
			tp--;
		}
	}
}
#define id(x,y) (x-1)*d+y
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		for(int j=1;j<=d;j++)
			add(id(u,j),id(v,j%d+1));
	}
	for(int i=1;i<=n*d;i++)
		if(!vis[i])
			tarjan(i);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=d;j++)
			if(s[j]=='1'&&vis[g[id(i,j)]]==0)
			{
				vis[g[id(i,j)]]=1;
				val[g[id(i,j)]]++;
			}
		for(int j=1;j<=d;j++)
			if(s[j]=='1')
				vis[g[id(i,j)]]=0;
	}
	memset(h,0,sizeof(h));
	memset(f,0xcf,sizeof(f));
	tt=t;
	t=0;
	//printf("-------------------\n");
	for(int i=1;i<=tt;i++)
	{
		int u=e1[i].u,v=e1[i].v;
		if(g[u]!=g[v]) add(g[u],g[v]),in[g[v]]++;
	}
	head=0,tail=0;
	for(int i=1;i<=gt;i++)
		if(!in[i])
			q[++tail]=i;
	f[g[1]]=val[g[1]];
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			in[v]--;
			f[v]=max(f[v],f[u]+val[v]);
			if(!in[v]) q[++tail]=v;
		}
	}
	/*printf("g[1]=%d,f=%d\n",g[1],f[g[1]]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=d;j++)
			printf("%d ",g[id(i,j)]);
		printf("\n");
	}
	for(int i=1;i<=gt;i++)
		printf("%d ",f[i]);*/
	int ans=0;
	for(int i=1;i<=gt;i++)
		ans=max(ans,f[i]);
	printf("%d",ans);
	return 0;
}
//sdjfksjdkfjskdfds