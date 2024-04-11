#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,w,nxt;
}e[2000005];
int n,m,a[300005][2],h[300005],t,f[300005],g[300005],size[300005];
int b[300005],c[300005],cf[300005],vis[300005];
char s[300005];
void add(int u,int v,int w)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int fl)
{
//	printf("dfs:u=%d,fa=%d,fl=%d\n",u,fa,fl);
	c[u]=fl;
	vis[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		b[v]=b[u]^e[i].w;
		dfs(v,u,fl);
	}
}
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	f[x]=y;
	g[y]+=g[x];
	size[y]+=size[x];
	cf[y]|=cf[x];
}
int getans(int x)
{
	if(cf[x]) return g[x];
	return min(g[x],size[x]-g[x]);
}
int main()
{
	memset(b,0xff,sizeof(b));
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=m;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int x;
			scanf("%d",&x);
			if(!a[x][0]) a[x][0]=i;
			else a[x][1]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!a[i][0]) continue;
		if(!a[i][1])
		{
			b[a[i][0]]=!(s[i]-'0');
			continue;
		}
		add(a[i][0],a[i][1],!(s[i]-'0'));
		add(a[i][1],a[i][0],!(s[i]-'0'));
	}
	for(int i=1;i<=m;i++)
		if(b[i]!=-1)
			dfs(i,0,1);
	for(int i=1;i<=m;i++)
		if(b[i]==-1)
		{
			b[i]=0;
			dfs(i,0,0);
		}
	//for(int i=1;i<=m;i++)
	//	printf("%d ",b[i]);
	//printf("\n");
	for(int i=1;i<=m;i++)
		f[i]=i,g[i]=b[i],cf[i]=0,size[i]=1;
	int tans=0;
	for(int i=1;i<=n;i++)
	{
		if(!a[i][0]) 
		{
			printf("%d\n",tans);
			continue;
		}
		if(!a[i][1])
		{
			int u=find(a[i][0]);
			tans-=getans(u);
			cf[u]=1;
			tans+=getans(u);
			printf("%d\n",tans);
			continue;
		}
		int u=find(a[i][0]),v=find(a[i][1]);
		if(u!=v)
		{
			tans-=getans(u);
			tans-=getans(v);
			link(u,v);
			tans+=getans(v);
		}
		printf("%d\n",tans);
	}
	return 0;
}