#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
struct edge
{
	int v,nxt;
}e[500005];
int n,m,h[505],tot,vis[505],visp[505],pre[505],q[505],head,tail;
int dis[505][505];
void add(int u,int v)
{
	e[++tot].v=v;
	e[tot].nxt=h[u];
	h[u]=tot;
}
int tmp[505];
void bfs(int s,int *dis)
{
	memset(visp,0,sizeof(visp));
	visp[s]=1;
	dis[s]=0;
	pre[s]=0;
	head=0,tail=1;
	q[1]=s;
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(visp[v]) continue;
			visp[v]=1;
			dis[v]=dis[u]+1;
			pre[v]=u;
			q[++tail]=v;
		}
	}
}
int solve(int S,int T)
{
	int nw=T;
	while(nw)
	{
		vis[nw]=1;
		nw=pre[nw];
	}
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int u=q[i];
		if(vis[u]) continue;
	//	printf("S=%d,T=%d,u=%d\n",S,T,u);
		int ct=0;
		for(int j=h[u];j;j=e[j].nxt)
		{
			int v=e[j].v;
		//	printf("dis=%d,%d,v=%d,%d\n",dis[S][u],dis[T][u],dis[S][v],dis[T][v]);
			if(dis[S][v]+1==dis[S][u]&&dis[T][v]+1==dis[T][u])
				ct++;
		}
		ans=1ll*ans*ct%mod;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
		bfs(i,dis[i]);
	for(int i=1;i<=n;i++)
	{
		bfs(i,tmp);
		for(int j=1;j<=n;j++)
		{
			memset(vis,0,sizeof(vis));
			printf("%d ",solve(i,j));
		}
		printf("\n");
	}
	return 0;
}