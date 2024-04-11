#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1e9+100;
struct pt
{
	int id,val;
	pt(int id=0,int val=0):id(id),val(val){}
	bool operator<(const pt p) const
	{
		return val<p.val;
	}
};
struct edge
{
	int v,nxt;
}e[500005];
int T,n,m,a[100005],b[100005],vis[100005],pre[100005],t,h[100005],f[100005],vis2[100005];
priority_queue<pt> pq;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
int solve(int u,int v)
{
	int ans=0;
	while(!f[u])
	{
		ans=min(ans+b[u],inf);
		f[u]=1;
		u=pre[u];
	}
	while(!f[v])
	{
		ans=min(ans+b[v],inf);
		f[v]=1;
		v=pre[v];
	}
	return ans;
}
bool dij(int &x)
{
	for(int i=1;i<=n;i++)
		vis[i]=0,pre[i]=0;
	while(!pq.empty()) pq.pop();
	for(int i=1;i<=n;i++)
		if(f[i])
		{
			vis[i]=1;
			pq.push(pt(i,x));
		}
	while(!pq.empty())
	{
		int u=pq.top().id,nw=pq.top().val;
		pq.pop();
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(v==pre[u]||(f[u]&&f[v])) continue;
			if(a[v]>=nw) continue;
			if(vis[v])
			{
				x=min(x+solve(u,v),inf);
			//	printf("u=%d,v=%d\n",u,v);
				return 1;
			}
			vis[v]=1;
			pre[v]=u;
			pq.push(pt(v,min(nw+b[v],inf)));
		}
	}
	return 0;
}
bool check(int x)
{
	for(int i=1;i<=n;i++)
		f[i]=0;
	f[1]=1;
	while(1)
	{
		int fl=0;
		for(int i=1;i<=n;i++)
			if(!f[i]) fl=1;
		if(!fl) return 1;
	//	printf("check:x=%d\n",x);
		if(!dij(x)) return 0;
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		t=0;
		for(int i=0;i<=n+1;i++)
			h[i]=0;
		for(int i=2;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=2;i<=n;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
//		printf("check=%d\n",check(12));
		int l=1,r=inf,mid;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(check(mid)) r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}