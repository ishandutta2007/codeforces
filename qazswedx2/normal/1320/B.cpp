#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005],e2[500005];
int n,m,k,h[200005],h2[200005],t,a[200005],dis[200005],vis[200005],t2;
int q[1000005],head,tail,las[200005],f[200005],te[200005][2],dfn[200005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void add2(int u,int v)
{
	e2[++t2].v=v;
	e2[t2].nxt=h2[u];
	h2[u]=t2;
}
void bfs(int s)
{
	dis[s]=0;
	vis[s]=1;
	head=0,tail=1;
	q[1]=s;
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(vis[v]) continue;
			dis[v]=dis[u]+1;
			vis[v]=1;
			las[v]=u;
			q[++tail]=v;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(v,u);
		add2(u,v);
		//te[i][0]=u,te[i][1]=v;
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	bfs(a[k]);
	//for(int i=1;i<=n;i++)
	//	if(las[i]) add2(las[i],i);
	int ans1=0,ans2=0;
	for(int i=1;i<k;i++)
	{
		int fl=0,ct=0;
		for(int j=h2[a[i]];j;j=e2[j].nxt)
		{
			int v=e2[j].v;
			if(dis[v]!=dis[a[i]]-1) continue;
			ct++;
			if(v==a[i+1]) fl=1;
			///printf("v=%d\n",v);
		}
		//printf("i=%d,fl=%d,ct=%d\n",i,fl,ct);
		if(!fl) ans1++,ans2++;
		else if(ct>1) ans2++;
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}