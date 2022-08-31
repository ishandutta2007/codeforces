#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,w,nxt;
}e[500005];
int h[100005],t=1,S,T,dis[100005],vis[100005],q[100005],cur[100005],head,tail;
int n,a[100005],b[100005],c[100005],ct;
void add(int u,int v,int w)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
	e[++t].v=u;
	e[t].w=0;
	e[t].nxt=h[v];
	h[v]=t;
}
bool bfs()
{
	for(int i=1;i<=T;i++)
		dis[i]=vis[i]=0;
	dis[S]=0;
	vis[S]=1;
	head=0,tail=1;
	q[1]=S;
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(vis[v]||!e[i].w) continue;
			vis[v]=1;
			dis[v]=dis[u]+1;
			q[++tail]=v;
		}
	}
	return vis[T];
}
int dfs(int u,int flow)
{
	if(u==T) return flow;
	int nw,ans=0;
	for(int i=cur[u];i;i=e[i].nxt)
	{
		cur[u]=i;
		int v=e[i].v,w=e[i].w;
		if(dis[v]!=dis[u]+1||!w) continue;
		nw=dfs(v,min(flow-ans,w));
		ans+=nw;
		e[i].w-=nw;
		e[i^1].w+=nw;
	}
	return ans;
}
int dinic()
{
	int ans=0;
	while(bfs())
	{
		for(int i=1;i<=T;i++)
			cur[i]=h[i];
		ans+=dfs(S,1e9);
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	S=n+1,T=n+2;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]>0) add(S,i,b[i]),sum+=b[i];
		else add(i,T,-b[i]);
	}
	for(int i=1;i<=n;i++)
	{
		ct=0;
		for(int j=i-1;j;j--)
			if(a[i]%a[j]==0)
			{
				int fl=1;
				for(int k=1;k<=ct;k++)
					if(c[k]%a[j]==0)
						fl=0;
				if(fl)
				{
					ct++;
					c[ct]=a[j];
					add(i,j,1e9);
				}
			}
	}
	printf("%d\n",sum-dinic());
	return 0;
}