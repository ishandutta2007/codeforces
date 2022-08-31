#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
	ll w;
}e[500005];
int n,m,dfn[100005],udfn[100005],ct,h[100005],t,sz[100005],c[100005][20],dd[100005];
ll e2[500005][3];
ll d[100005];
void add(int u,int v,ll w)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,ll dep,int ddep)
{
	d[u]=dep;
	dd[u]=ddep;
	dfn[u]=++ct;
	udfn[ct]=u;
	sz[u]=1;
	c[u][0]=fa;
	for(int i=1;i<=18;i++)
		c[u][i]=c[c[u][i-1]][i-1];
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+e[i].w,ddep+1);
		sz[u]+=sz[v];
	}
}
int lca(int u,int v)
{
	if(dd[u]<dd[v]) swap(u,v);
	for(int i=18;i>=0;i--)
		if(dd[c[u][i]]>=dd[v])
			u=c[u][i];
	if(u==v) return u;
	for(int i=18;i>=0;i--)
		if(c[u][i]!=c[v][i])
			u=c[u][i],v=c[v][i];
	return c[u][0];
}
namespace BIT
{
	ll sum[1000005];
	inline int lowbit(int x)
	{
		return x&-x;
	}
	void modify(int x,ll v)
	{
		for(int i=x;i<=n;i+=lowbit(i))
			sum[i]+=v;
	}
	ll query(int x)
	{
		ll ans=0;
		for(int i=x;i;i-=lowbit(i))
			ans+=sum[i];
		return ans;
	}
}
namespace SGT
{
	struct pt
	{
		int u,v;
		ll w;
		pt(int u=0,int v=0,ll w=0):u(u),v(v),w(w){}
	}sum[1000005];
	inline void upd(pt &x,pt y)
	{
		if(y.w>x.w) x=y;
	}
	inline ll getdis(int u,int v)
	{
		return BIT::query(dfn[u])+BIT::query(dfn[v])-2*BIT::query(dfn[lca(u,v)]);
	}
	void pushup(int x)
	{
		int u=sum[x*2].u,v=sum[x*2].v,uu=sum[x*2+1].u,vv=sum[x*2+1].v;
	//	u=udfn[u],v=udfn[v],uu=udfn[uu],vv=udfn[vv];
		sum[x]=sum[x*2];
		upd(sum[x],sum[x*2+1]);
		upd(sum[x],pt(u,uu,getdis(u,uu)));
		upd(sum[x],pt(u,vv,getdis(u,vv)));
		upd(sum[x],pt(v,uu,getdis(v,uu)));
		upd(sum[x],pt(v,vv,getdis(v,vv)));
	}
	void build(int x,int l,int r)
	{
		if(l==r)
		{
			sum[x]=pt(udfn[l],udfn[l],0);
			return;
		}
		int mid=(l+r)/2;
		build(x*2,l,mid);
		build(x*2+1,mid+1,r);
		pushup(x);
	}
	void modify(int x,int l,int r,int ql,int qr)
	{
		if(l>qr||r<ql) return;
		if(ql<=l&&r<=qr) return;
		int mid=(l+r)/2;
		modify(x*2,l,mid,ql,qr);
		modify(x*2+1,mid+1,r,ql,qr);
		pushup(x);
	}
}
int main()
{
	ll qwq;
	scanf("%d%d%lld",&n,&m,&qwq);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
		e2[i][0]=u,e2[i][1]=v,e2[i][2]=w;
	}
	dfs(1,0,0,1);
	//for(int i=1;i<=n;i++)
	//	for(int j=1;j<=n;j++)
	//		printf("i=%d,j=%d,l=%d\n",i,j,lca(i,j));
	for(int i=1;i<=n;i++)
	{
		BIT::modify(dfn[i],d[i]);
		BIT::modify(dfn[i]+1,-d[i]);
	}
	SGT::build(1,1,n);
	ll las=0;
	for(int i=1;i<=m;i++)
	{
		int x;
		ll w;
		scanf("%d%lld",&x,&w);
		x=(x+las)%(n-1);
		w=(w+las)%qwq;
		w=w-e2[x][2];
		int u=e2[x][0];
		if(c[e2[x][1]][0]==u) u=e2[x][1];
	//	printf("i=%d,x=%d,w=%lld,u=%d\n",i,x,w,u);
		BIT::modify(dfn[u],w);
		BIT::modify(dfn[u]+sz[u],-w);
		SGT::modify(1,1,n,dfn[u],dfn[u]+sz[u]-1);
		e2[x][2]+=w;
	//	printf("u=%d,v=%d,w=%lld\n",SGT::sum[1].u,SGT::sum[1].v,SGT::sum[1].w);
		printf("%lld\n",las=SGT::sum[1].w);
	}
	return 0;
}