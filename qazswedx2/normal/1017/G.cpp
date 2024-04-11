#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int n,m,h[100005],t,d[100005],son[100005],sz[100005],dfn[100005],tp[100005],f[100005],ct;
int udfn[100005],sum[1000005],sum2[1000005],lazy[1000005],lazy0[1000005],suml[1000005];
void pushup(int x)
{
	sum[x]=max(sum[x*2],sum[x*2+1]);
} 
void col(int x,int v)
{
	sum[x]+=v;
	sum2[x]+=v;
	lazy[x]+=v;
}
void col0(int x)
{
	lazy0[x]=1;
	sum[x]=suml[x];
	sum2[x]=lazy[x]=0;
}
void pushdown(int x)
{
	if(lazy0[x])
	{
		col0(x*2);
		col0(x*2+1);
		lazy0[x]=0;
	}
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
		suml[x]=sum[x];
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
	suml[x]=sum[x];
}
void modify(int x,int l,int r,int ql,int qr,int v)
{
	//printf("modify:x=%d,l=%d,r=%d,ql=%d,qr=%d,v=%d\n",x,l,r,ql,qr,v); 
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
void modify0(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		col0(x);
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	modify0(x*2,l,mid,ql,qr);
	modify0(x*2+1,mid+1,r,ql,qr);
	pushup(x);
}
int query(int x,int l,int r,int ql,int qr,int fl)
{
	if(l>qr||r<ql) return -1e9;
	if(ql<=l&&r<=qr) return fl?sum2[x]:sum[x];
	pushdown(x);
	int mid=(l+r)/2;
	return max(query(x*2,l,mid,ql,qr,fl),query(x*2+1,mid+1,r,ql,qr,fl));
}
int tquery(int x)
{
	int q=query(1,1,n,dfn[x],dfn[x],0),v=0; 
	x=f[x];
	while(x)
	{
	//	printf("x=%d,tp=%d\n",x,tp[x]);
		v=max(v,query(1,1,n,dfn[tp[x]],dfn[x],0));
		x=f[tp[x]];
	}
	return q-v;
}
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs1(int u,int fa,int dep)
{
	f[u]=fa;
	d[u]=dep;
	sz[u]=1;
	son[u]=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs1(v,u,dep+1);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])
			son[u]=v;
	}
	//printf("u=%d,son=%d\n",u,son[u]); 
}
void dfs2(int u,int ttp)
{
	tp[u]=ttp;
	dfn[u]=++ct;
	udfn[ct]=u;
	if(son[u]) dfs2(son[u],ttp);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==f[u]||v==son[u]) continue;
		dfs2(v,v);
	}
//	printf("u=%d,dfn=%d\n",u,dfn[u]);
}
void print(int x,int l,int r)
{
	printf("x=%d,l=%d,r=%d,sum=%d\n",x,l,r,sum[x]);
	if(l==r) return;
	pushdown(x);
	int mid=(l+r)/2;
	print(x*2,l,mid);
	print(x*2+1,mid+1,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		add(i,v);
		add(v,i);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,x;
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			modify(1,1,n,dfn[x],dfn[x]+sz[x]-1,-1);
		}
		if(op==2)
		{
			modify0(1,1,n,dfn[x]+1,dfn[x]+sz[x]-1);
			int nw=query(1,1,n,dfn[x],dfn[x],0)-d[x];
			modify(1,1,n,dfn[x]+1,dfn[x]+sz[x]-1,nw);
			int q=tquery(x);
			if(q<=0) modify(1,1,n,dfn[x],dfn[x]+sz[x]-1,1-q);
		}
		if(op==3)
		{
			int q=tquery(x);
			if(q<=0) printf("black\n");
			else printf("white\n");
		}
	//	print(1,1,n);
	}
	return 0;
}