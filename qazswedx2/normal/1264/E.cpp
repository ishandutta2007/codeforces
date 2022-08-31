#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define inf 1000000000
struct edge
{
	int v,w,c,nxt;
}e[2000005];
int n,m,h[100005],tot=1,s,t,dis[100005],vis[100005],pt,p[100005],las[100005][2];
int q[5000005],head,tail,g[105][105],f[105][105];
int add(int u,int v,int w,int c)
{
	//printf("%d %d %d,%d\n",u,v,w,c);
	e[++tot].v=v;
	e[tot].w=w;
	e[tot].c=c;
	e[tot].nxt=h[u];
	h[u]=tot;
	e[++tot].v=u;
	e[tot].w=0;
	e[tot].c=-c;
	e[tot].nxt=h[v];
	h[v]=tot;
	return tot-1;
}
bool spfa()
{
	for(int i=1;i<=pt+2;i++)
		vis[i]=0,dis[i]=inf;
	vis[s]=1;
	dis[s]=0;
	head=0,tail=1;
	q[1]=s;
	p[s]=1e9;
	while(head<tail)
	{
		head++;
		int u=q[head];
		vis[u]=0;
		//printf("u=%d,dis=%d\n",u,dis[u]);
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w,c=e[i].c;
			if(!w||dis[v]<=dis[u]+c) continue;
			dis[v]=dis[u]+c;
			p[v]=min(p[u],w);
			las[v][1]=i;
			las[v][0]=u;
			if(!vis[v])
			{
				q[++tail]=v;
				vis[v]=1;
			}
		}
	}
	return dis[t]!=inf;
}
void ek()
{
	while(spfa())
	{
		for(int i=t;i!=s;i=las[i][0])
		{
		//	printf("i=%d\n",i);
			e[las[i][1]].w-=p[t];
			e[las[i][1]^1].w+=p[t];
		}
	}
}
int main()
{
	//freopen("cf1264.in","r",stdin);
	scanf("%d%d",&n,&m);
	s=n+n*(n-1)/2-m+1;
	t=s+1;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u][v]=1;
		g[v][u]=-1;
		add(s,u,1,0);
	}
	pt=n;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(!g[i][j])
			{
				//printf("i=%d,j=%d\n",i,j);
				pt++;
				add(s,pt,1,0);
				f[i][j]=add(pt,i,1,0);
				f[j][i]=add(pt,j,1,0);
			}
	//printf("--");
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			add(i,t,1,j*2-1);
	ek();
	//printf("pt=%d,t=%d,tot=%d\n",pt,t,tot);
	//for(int i=2;i<=tot;i++)
	//	printf("u=%d,v=%d,w=%d,c=%d\n",e[i^1].v,e[i].v,e[i].w,e[i].c);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) printf("0");
			else if(g[i][j]==1) printf("1");
			else if(g[i][j]==-1) printf("0");
			else if(e[f[i][j]].w) printf("0");
			else printf("1");
		}
		printf("\n");
	}
	return 0;
}