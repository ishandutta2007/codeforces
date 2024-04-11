#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,w,nxt;
}e[2000005];
int n,m,dis[500005],h[500005],t,vis[500005],q[500005],f[500005],head,tail;
void add(int u,int v,int w)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
}
int main()
{
	scanf("%d%d",&n,&m);
	//for(int i=1;i<=n;i++)
	//	f[i]=1;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(v,u,w);
	}
	head=0,tail=1;
	q[1]=n;
	dis[n]=0;
	vis[n]=3;
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=(1<<e[i].w);
			if(vis[v]&w) continue;
			vis[v]|=w;
			if(dis[v]<dis[u]+1)
			{
				dis[v]=dis[u]+1;
				f[v]=e[i].w;
			}
			if(vis[v]==3) q[++tail]=v;
		}
	}
	for(int i=1;i<=n;i++)
		if(vis[i]==1) f[i]=1;
		else if(vis[i]==2) f[i]=0;
	if(vis[1]==3) printf("%d\n",dis[1]);
	else printf("-1\n");
	for(int i=1;i<=n;i++)
		printf("%d",f[i]);
	return 0;
}