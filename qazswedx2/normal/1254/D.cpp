#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
struct edge
{
	int v,nxt;
}e[500005];
int n,m,f[500005],h[500005],d[500005],tp[500005],size[500005],son[500005],dfn[500005];
int udfn[500005],t,cnt,sum[5000005],lazy[5000005],nans,inv,a[500005];
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
void pushup(int x)
{
	sum[x]=addmod(sum[x*2]+sum[x*2+1]);
}
void col(int x,int l,int r,int v)
{
	sum[x]=addmod(sum[x]+1ll*(r-l+1)*v%mod);
	lazy[x]=addmod(lazy[x]+v);
}
void pushdown(int x,int l,int r)
{
	if(lazy[x])
	{
		int mid=(l+r)/2;
		col(x*2,l,mid,lazy[x]);
		col(x*2+1,mid+1,r,lazy[x]);
		lazy[x]=0;
	}
}
void modify(int x,int l,int r,int ql,int qr,int v)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		col(x,l,r,v);
		return;
	}
	pushdown(x,l,r);
	int mid=(l+r)/2;
	modify(x*2,l,mid,ql,qr,v);
	modify(x*2+1,mid+1,r,ql,qr,v);
	pushup(x);
}
int query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return 0;
	if(ql<=l&&r<=qr) return sum[x];
	pushdown(x,l,r);
	int mid=(l+r)/2,q1,q2;
	q1=query(x*2,l,mid,ql,qr);
	q2=query(x*2+1,mid+1,r,ql,qr);
	return addmod(q1+q2);
}
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs1(int u,int fa,int dep)
{
	d[u]=dep;
	f[u]=fa;
	size[u]=1;
	son[u]=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs1(v,u,dep+1);
		size[u]+=size[v];
		if(size[v]>size[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int ttp)
{
	dfn[u]=++cnt;
	udfn[cnt]=u;
	tp[u]=ttp;
	if(son[u]) dfs2(son[u],ttp);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==f[u]||v==son[u]) continue;
		dfs2(v,v); 
	}
}
int tquery(int x)
{
	int ans=0;
	while(1)
	{
		x=tp[x];
		if(x==1) return ans;
		ans=addmod(ans+1ll*a[f[x]]*size[x]%mod*inv%mod);
		//printf("ans=%d,%d,%d,%d,%d\n",ans,f[x],a[f[x]],size[x],inv);
		x=f[x];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	inv=fpow(n,mod-2);
	dfs1(1,0,1);
	dfs2(1,1);
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			scanf("%d",&y);
			nans=addmod(nans+y);
			a[x]=addmod(a[x]+y);
			modify(1,1,n,1,dfn[x]-1,1ll*y*(n-size[x])%mod*inv%mod);
			modify(1,1,n,dfn[x]+size[x],n,1ll*y*(n-size[x])%mod*inv%mod);
			modify(1,1,n,dfn[x]+1,dfn[x]+size[son[x]],1ll*y*size[son[x]]%mod*inv%mod);
		}
		if(op==2)
		{
			int tans=query(1,1,n,dfn[x],dfn[x]);
			tans=addmod(tans+tquery(x));
			//printf("tans=%d\n",tans);
			tans=submod(nans-tans);
			printf("%d\n",tans);
		}
	//	printf("a=%d\n",a[2]);
	}
}