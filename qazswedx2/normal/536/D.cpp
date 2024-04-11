#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
struct edge
{
	int v,w,nxt;
}e[500005];
struct pt
{
	ll val;
	int id;
	pt(ll val=0,int id=0):val(val),id(id){}
	bool operator<(const pt x) const
	{
		return val>x.val;
	}
};
int n,m,h[100005],a[100005],t,p1,p2,vis[100005];
int bt,ct;
ll sum[2005][2005],f[2005][2005][2],g[2005][2005],g2[2005][2005];
ll dis[100005][2],c[100005],b[100005];
priority_queue<pt> pq;
void add(int u,int v,int w)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
}
void dij(int s,int fl)
{
	memset(vis,0,sizeof(vis));
	while(!pq.empty()) pq.pop();
	dis[s][fl]=0;
	pq.push(pt(dis[s][fl],s));
	while(!pq.empty())
	{
		while(!pq.empty()&&dis[pq.top().id][fl]!=pq.top().val) pq.pop();
		if(pq.empty()) break;
		int u=pq.top().id;
		pq.pop();
		vis[u]=1;
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
			if(vis[v]||dis[v][fl]<=dis[u][fl]+w) continue;
			dis[v][fl]=dis[u][fl]+w;
			pq.push(pt(dis[v][fl],v));
		}
	}
}
int main()
{
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d%d",&n,&m,&p1,&p2);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dij(p1,0);
	dij(p2,1);
	bt=0;
	for(int i=1;i<=n;i++)
		b[++bt]=dis[i][0];
	sort(b+1,b+bt+1);
	bt=unique(b+1,b+bt+1)-b-1;
	for(int i=1;i<=n;i++)
		dis[i][0]=lower_bound(b+1,b+bt+1,dis[i][0])-b;
	ct=0;
	for(int i=1;i<=n;i++)
		c[++ct]=dis[i][1];
	sort(c+1,c+ct+1);
	ct=unique(c+1,c+ct+1)-c-1;
	for(int i=1;i<=n;i++)
		dis[i][1]=lower_bound(c+1,c+ct+1,dis[i][1])-c;
	for(int i=1;i<=n;i++)
	{
		sum[dis[i][0]][dis[i][1]]+=a[i];
		//printf("i=%d,dis=%d,%d,a=%d\n",i,dis[i][0],dis[i][1],a[i]);
	}
	for(int i=bt;i>=0;i--)
		for(int j=ct;j>=0;j--)
			sum[i][j]+=sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1];
	for(int i=bt;i>=0;i--)
		for(int j=ct;j>=0;j--)
		{
			if(!sum[i+1][j+1]) continue;
			f[i][j][0]=f[i][j][1]=-1e18;
			/*for(int k=i+1;k<=bt;k++)
				if(sum[i+1][j+1]-sum[k+1][j+1])
					f[i][j][0]=max(f[i][j][0],sum[i+1][j+1]-sum[k+1][j+1]-f[k][j][1]);
			for(int k=j+1;k<=ct;k++)
				if(sum[i+1][j+1]-sum[i+1][k+1])
					f[i][j][1]=max(f[i][j][1],sum[i+1][j+1]-sum[i+1][k+1]-f[i][k][0]);*/
			f[i][j][0]=sum[i+1][j+1]-g[i+1][j];
			f[i][j][1]=sum[i+1][j+1]-g2[i][j+1];
			g[i][j]=g[i+1][j];
			g2[i][j]=g2[i][j+1];
			if(sum[i][j+1]-sum[i+1][j+1])
				g[i][j]=min(g[i][j],sum[i+1][j+1]+f[i][j][1]);
			if(sum[i+1][j]-sum[i+1][j+1])
				g2[i][j]=min(g2[i][j],sum[i+1][j+1]+f[i][j][0]);
		//	printf("i=%d,j=%d,f=%lld,%lld,sum=%lld\n",i,j,f[i][j][0],f[i][j][1],sum[i][j]);
		}
	if(f[0][0][0]>0) printf("Break a heart");
	else if(f[0][0][0]==0) printf("Flowers");
	else printf("Cry");
	return 0;
}