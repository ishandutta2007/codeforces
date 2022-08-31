#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,w,nxt;
}e[5000005];
int T,n,a[100005],ra[100005],h[200005],tot=1,s,t,vis[200005],dis[200005],q[200005],cur[200005],head,tail;
int m=5e4,sn=230;
void add(int u,int v,int w)
{
	e[++tot].v=v;
	e[tot].w=w;
	e[tot].nxt=h[u];
	h[u]=tot;
	e[++tot].v=u;
	e[tot].w=0;
	e[tot].nxt=h[v];
	h[v]=tot;
}
int bfs()
{
	for(int i=1;i<=t;i++)
		vis[i]=0,dis[i]=1e9;
	head=0,tail=1;
	q[1]=s;
	vis[s]=1,dis[s]=0;
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
			if(!w||vis[v]) continue;
			vis[v]=1;
			dis[v]=dis[u]+1;
			q[++tail]=v;
		}
	}
	return vis[t];
}
int dfs(int u,int flow)
{
	if(u==t) return flow;
	int nw,ans=0;
	for(int i=cur[u];i;i=e[i].nxt)
	{
		int v=e[i].v,w=e[i].w;
		cur[u]=i;
		if(!w||dis[v]!=dis[u]+1) continue;
		nw=dfs(v,min(flow-ans,w));
		e[i].w-=nw;
		e[i^1].w+=nw;
		ans+=nw;
		if(ans==flow) return ans;
	}
	if(!ans) cur[u]=0;
	return ans;
}
int dinic()
{
	int ans=0;
	while(bfs())
	{
		for(int i=1;i<=t;i++)
			cur[i]=h[i];
		ans+=dfs(s,1e9);
	}
	return ans;
}
void link(int u,int v)
{
	add(u,v+2*n,1);
	add(u,v+n+2*n,1);
	add(u+n,v+n+2*n,1);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		tot=1;
		scanf("%d",&n);
		s=4*n+1,t=4*n+2; 
		for(int i=0;i<=t+1;i++)
			h[i]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			ra[a[i]]=i;
		for(int i=1;i<=n;i++)
			if(a[i]<=sn)
			{
				for(int j=i+1;j<=n;j++)
					if(a[j]%a[i]==0)
						link(i,j);
			}
			else
			{
				for(int j=2*a[i];j<=m;j+=a[i])
					if(ra[j])
						link(i,ra[j]);
			}
		for(int i=1;i<=n;i++)
			add(i,i+n+2*n,1);
		for(int i=1;i<=2*n;i++)
		{
			add(s,i,1);
			add(i+2*n,t,1);
		}
		for(int i=1;i<=n;i++)
			ra[a[i]]=0;
		int q=dinic();
		printf("%d\n",q-n);
	}
	return 0;
}