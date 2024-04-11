#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[1000005];
int n,m,rt[300005];
ll sum[9000005],lazy[9000005],f[300005];
int ls[9000005],rs[9000005],h[300005],t,d[300005],cnt;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void pushup(int x)
{
	sum[x]=min(sum[ls[x]],sum[rs[x]]);
}
void col(int x,ll v)
{
	lazy[x]+=v;
	sum[x]+=v;
}
void pushdown(int x)
{
	if(lazy[x])
	{
		if(ls[x]) col(ls[x],lazy[x]);
		if(rs[x]) col(rs[x],lazy[x]);
		lazy[x]=0;
	}
}
void modify(int x,int l,int r,int ql,int qr,ll v)
{
	if(l>qr||r<ql||!x) return;
	if(ql<=l&&r<=qr)
	{
		col(x,v);
		return;
	}
	int mid=(l+r)/2;
	pushdown(x);
	modify(ls[x],l,mid,ql,qr,v);
	modify(rs[x],mid+1,r,ql,qr,v);
	pushup(x);
}
int modifyp(int x,int l,int r,int qx,ll v)
{
	if(l>qx||r<qx) return x;
	if(!x) x=++cnt,sum[x]=1e18;
	if(l==r)
	{
		sum[x]=min(sum[x],(ll)v);
		return x;
	}
	pushdown(x);
	int mid=(l+r)/2;
	ls[x]=modifyp(ls[x],l,mid,qx,v);
	rs[x]=modifyp(rs[x],mid+1,r,qx,v);
	pushup(x);
	return x;
}
int merge(int x,int y)
{
	if(!x||!y) return x+y;
	pushdown(x);
	pushdown(y);
	sum[x]=min(sum[x],sum[y]);
	ls[x]=merge(ls[x],ls[y]);
	rs[x]=merge(rs[x],rs[y]);
	return x;
}
ll query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql||!x) return 1e18;
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2;
	pushdown(x);
	return min(query(ls[x],l,mid,ql,qr),query(rs[x],mid+1,r,ql,qr));
}
void dfs(int u,int fa,int dep)
{
	d[u]=dep;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
	}
}
void dfs2(int u,int fa)
{
	ll ssum=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u);
		ssum+=f[v];
	}
	modify(rt[u],1,n,1,n,ssum);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		modify(rt[v],1,n,1,n,ssum-f[v]);
		rt[u]=merge(rt[u],rt[v]);
	}
	f[u]=query(rt[u],1,n,1,u==1?d[u]:d[u]-1);
	//printf("u=%d,d=%d,%d,f=%lld,ssum=%d\n",u,d[u],u==1?d[u]:d[u]-1,f[u],ssum);
//	print(rt[u],1,n);
	if(f[u]==1e18)
	{
		printf("-1\n");
		exit(0);
	}
}
int main()
{
//	freopen("CF617D.in","r",stdin);
	sum[0]=1e18;
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0,1);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		rt[u]=modifyp(rt[u],1,n,d[v],w);
	}
	dfs2(1,0);
	printf("%lld\n",f[1]);
	return 0;
}