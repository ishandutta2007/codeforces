#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
	ll w;
}e[5000005];
struct pt
{
	int x,y;
	pt(int x=0,int y=0):x(x),y(y){}
	bool operator<(const pt p) const
	{
		if(x!=p.x) return x<p.x;
		return y<p.y;
	}
	bool operator==(const pt p) const
	{
		return x==p.x&&y==p.y;
	}
};
int T,n,m,k,c[1000005],q[1000005][5],h[1000005],t,bt;
pt b[1000005];
ll a[1000005],dis[1000005];
void add(int u,int v,ll w)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		t=bt=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=k;i++)
		{
			for(int j=0;j<5;j++)
				scanf("%d",&q[i][j]);
			b[++bt]=pt(q[i][0],q[i][1]);
			b[++bt]=pt(q[i][2],q[i][3]);
		}
		b[++bt]=pt(1,1);
		b[++bt]=pt(n,m);
		sort(b+1,b+bt+1);
		bt=unique(b+1,b+bt+1)-b-1;
		for(int i=0;i<=bt+1;i++)
			h[i]=0,dis[i]=1e18;
		for(int i=1;i<=k;i++)
		{
			int u=lower_bound(b+1,b+bt+1,pt(q[i][0],q[i][1]))-b;
			int v=lower_bound(b+1,b+bt+1,pt(q[i][2],q[i][3]))-b;
			add(u,v,q[i][4]);
		}
		dis[1]=0;
		for(int l=1,r;l<=bt;l=r+1)
		{
			r=l;
			while(r<bt&&b[r+1].x==b[l].x) r++;
			for(int i=l+1;i<=r;i++)
			{
				dis[i]=min(dis[i],dis[i-1]+1ll*(b[i].y-b[i-1].y)*a[b[l].x]);
			}
			for(int i=r-1;i>=l;i--)
			{
				dis[i]=min(dis[i],dis[i+1]+1ll*(b[i+1].y-b[i].y)*a[b[l].x]);
			}
			for(int i=l;i<=r;i++)
			{
			//	printf("l=%d,r=%d,i=%d,b=%d,%d,dis=%lld\n",l,r,i,b[i].x,b[i].y,dis[i]);
				for(int j=h[i];j;j=e[j].nxt)
				{
					int v=e[j].v;
					ll w=e[j].w;
					dis[v]=min(dis[v],dis[i]-w);
				}
			}
		}
		if(dis[bt]>9e17) printf("NO ESCAPE\n");
		else printf("%lld\n",dis[bt]);
	}
}