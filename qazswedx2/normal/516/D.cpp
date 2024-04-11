#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,w,nxt;
}e[500005];
int n,m,h[100005],t=1,a[100005],p1,p2,id,rt1,rt2;
int bt,rt[100005],sum[10000005],ls[10000005],rs[10000005],ct;
int qans[105];
ll q[105],dis[100005][2],ans,b[100005],c[100005];
void pushup(int x)
{
	sum[x]=sum[ls[x]]+sum[rs[x]];
}
int modify(int x,int l,int r,int qx,int v)
{
	if(l>qx||r<qx) return x;
	if(!x) x=++ct;
	if(l==r)
	{
		sum[x]+=v;
		return x;
	}
	int mid=(l+r)/2;
	ls[x]=modify(ls[x],l,mid,qx,v);
	rs[x]=modify(rs[x],mid+1,r,qx,v);
	pushup(x);
	return x;
}
int merge(int x,int y)
{
	if(!x||!y) return x+y;
	sum[x]+=sum[y];
	ls[x]=merge(ls[x],ls[y]);
	rs[x]=merge(rs[x],rs[y]);
	return x;
}
int query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql||!x) return 0;
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2;
	return query(ls[x],l,mid,ql,qr)+query(rs[x],mid+1,r,ql,qr);
}
void add(int u,int v,int w)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,ll dep)
{
	if(dep>ans)
	{
		ans=dep;
		id=u;
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+e[i].w);
	}
}
void dfs2(int u,int fa,int fl,ll dep)
{
	dis[u][fl]=dep;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u,fl,dep+e[i].w);
	}
}
void dfs3(int u,int fa)
{
	rt[u]=modify(rt[u],1,bt,c[u],1);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs3(v,u);
		rt[u]=merge(rt[u],rt[v]);
	}
	for(int i=1;i<=m;i++)
	{
		int nw=upper_bound(b+1,b+bt+1,b[c[u]]+q[i])-b-1;
		qans[i]=max(qans[i],query(rt[u],1,bt,c[u],nw));
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	ans=-1;
	dfs(1,0,0);
	p1=id;
	ans=-1;
	dfs(p1,0,0);
	p2=id;
	dfs2(p1,0,0,0);
	dfs2(p2,0,1,0);
	for(int i=1;i<=n;i++)
	{
		a[i]=(dis[i][0]<=dis[i][1]);
		c[i]=max(dis[i][0],dis[i][1]);
	}
	for(int i=2;i<=t;i+=2)
	{
		int u=e[i].v,v=e[i^1].v;
		if(a[u]!=a[v]) rt1=u,rt2=v;
	}
	for(int i=1;i<=n;i++)
		b[++bt]=c[i];
	sort(b+1,b+bt+1);
	bt=unique(b+1,b+bt+1)-b-1;
	for(int i=1;i<=n;i++)
		c[i]=lower_bound(b+1,b+bt+1,c[i])-b;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		ll mn=min(b[c[rt1]],b[c[rt2]]);
		scanf("%lld",&q[i]);
		for(int j=1;j<=n;j++)
			if(b[c[j]]<=mn+q[i])
				qans[i]++;
	}
	dfs3(rt1,rt2);
	dfs3(rt2,rt1);
	for(int i=1;i<=m;i++)
		printf("%d\n",qans[i]);
	return 0;
}