#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
struct pt
{
	ll val;
	int id,fr;
	pt(ll val=0,int id=0,int fr=0):val(val),id(id),fr(fr){}
	bool operator<(const pt x) const
	{
		return val>x.val;
	}
};
priority_queue<pt> pq;
int n,a[100005],b[100005],c[100005],d[100005],vis[100005];
int f[100005],ft,g[100005][2],gt;
ll dis[100005],tans;
ll getdis(int u,int v)
{
	return 1ll*(abs(a[u]-a[v])+abs(b[u]-b[v]))*(d[u]+d[v]);
}
void prim()
{
	for(int i=1;i<=n;i++)
		pq.push(pt(c[i],i,0)),dis[i]=c[i];
	while(!pq.empty())
	{
		while(!pq.empty()&&dis[pq.top().id]!=pq.top().val) pq.pop();
		if(pq.empty()) break;
		int u=pq.top().id,fa=pq.top().fr;
		pq.pop();
		if(!fa) f[++ft]=u;
		else g[++gt][0]=u,g[gt][1]=fa;
		vis[u]=1;
		tans+=dis[u];
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				ll nw=getdis(u,i);
				if(nw>=dis[i]) continue;
				dis[i]=nw;
				pq.push(pt(dis[i],i,u));
			}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	prim();
	printf("%I64d\n%d\n",tans,ft);
	for(int i=1;i<=ft;i++)
		printf("%d ",f[i]);
	printf("\n%d\n",gt);
	for(int i=1;i<=gt;i++)
		printf("%d %d\n",g[i][0],g[i][1]);
	return 0;
}