#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[2000005];
int n,k,sum[2000005],lazy[2000005],dfn[500005],h[500005],d[500005],t,sz[500005],ct;
int sumid[2000005],vis[500005],f[500005],udfn[500005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep)
{
	d[u]=dep;
	f[u]=fa;
	dfn[u]=++ct;
	udfn[ct]=u;
	sz[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
		sz[u]+=sz[v];
	}
}
void pushup(int x)
{
	sum[x]=max(sum[x*2],sum[x*2+1]);
	if(sum[x]==sum[x*2]) sumid[x]=sumid[x*2];
	else sumid[x]=sumid[x*2+1]; 
}
void col(int x,int v)
{
	sum[x]+=v;
	lazy[x]+=v;
}
void pushdown(int x)
{
	if(lazy[x])
	{
		col(x*2,lazy[x]);
		col(x*2+1,lazy[x]);
		lazy[x]=0;
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sum[x]=d[udfn[l]];
		sumid[x]=udfn[l];
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int ql,int qr,int v)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		col(x,v);
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	modify(x*2,l,mid,ql,qr,v);
	modify(x*2+1,mid+1,r,ql,qr,v);
	pushup(x); 
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0,1);
	build(1,1,n);
	int ct0=0,ct1=0,ct2=0;
	for(int i=1;i<=k;i++)
	{
		int u=sumid[1];
		int v=u;
		if(sum[1]==0&&i>n/2) break;
		ct0++;
		while(v&&!vis[v])
		{
			vis[v]=1;
			modify(1,1,n,dfn[v],dfn[v]+sz[v]-1,-1);
			v=f[v];
		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]) ct1++;
	long long ans=1e18;
	for(int i=0;i<=ct1;i++)
		ans=min(ans,1ll*(n-ct0-i)*(ct0-i));
	/*if(ct1>ct0&&ct1>n-ct0-ct1) ct1=ct0+(n-ct0)/2;
	ct2=n-ct0-ct1;*/
	printf("%lld\n",ans);//1ll*ct2*(ct0-ct1));
	return 0;
}