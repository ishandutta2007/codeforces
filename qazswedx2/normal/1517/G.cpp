#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,w,nxt;
}e[500005];
int n,h[100005],t=1,S,T,dis[100005],vis[100005],q[100005],head,tail,cur[100005];
int a[100005][3],b[2][2];
void add(int u,int v,int w)
{
	//printf("add:u=%d,v=%d,w=%d\n",u,v,w);
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
		vis[i]=0;
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
			int v=e[i].v,w=e[i].w;
			if(!w||vis[v]) continue;
			vis[v]=1;
			dis[v]=dis[u]+1;
			q[++tail]=v;
		}
	}
	return vis[T];
}
ll dfs(int u,ll flow)
{
	if(u==T) return flow;
	ll nw,ans=0;
	for(int i=cur[u];i;i=e[i].nxt)
	{
		int v=e[i].v,w=e[i].w;
		if(!w||dis[v]!=dis[u]+1) continue;
		if(ans==flow) break;
		nw=dfs(v,min(flow-ans,(ll)w));
		ans+=nw;
		e[i].w-=nw;
		e[i^1].w+=nw;
		cur[u]=i;
	}
	return ans;
}
ll dinic()
{
	ll ans=0;
	while(bfs())
	{
		for(int i=1;i<=T;i++)
			cur[i]=h[i];
		ans+=dfs(S,1e18);
		//printf("ans=%lld\n",ans);
	}
	return ans;
}
inline int F(int x)
{
	return x>0?x:-x;
}
int main()
{
	b[0][0]=1,b[1][0]=0,b[0][1]=2,b[1][1]=3;
	scanf("%d",&n);
	S=2*n+1,T=2*n+2;
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		int w;
		scanf("%d%d%d",&a[i][0],&a[i][1],&w);
		add(i,i+n,w);
		a[i][2]=b[a[i][0]&1][a[i][1]&1];
		sum+=w;
	}
	for(int i=1;i<=n;i++)
	{
		int x=a[i][0],y=a[i][1],fl=a[i][2];
		if(fl==0) add(S,i,1e9);
		if(fl==3) add(i+n,T,1e9);
		for(int j=1;j<=n;j++)
			if(F(a[j][0]-x)+F(a[j][1]-y)==1&&a[j][2]==fl+1)
				add(i+n,j,1e9);
	}
	printf("%lld\n",sum-dinic());
	return 0;
}