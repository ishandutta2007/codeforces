#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[1000005];
struct edge2
{
	int u,v,w;
	bool operator<(const edge2 e) const
	{
		return w>e.w;
	}
}e2[500005];
int n,m,q,a[200005],h[500005],t,pt,ql[500005][2],f[500005];
int val[500005],c[500005][22],dfn[500005],udfn[500005],cnt;
int sum[2000005],sumid[2000005],dmn[500005],dmx[500005];
void pushup(int x)
{
	sum[x]=max(sum[x*2],sum[x*2+1]);
	if(sum[x]==sum[x*2]) sumid[x]=sumid[x*2];
	else sumid[x]=sumid[x*2+1];
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sumid[x]=l;
		sum[x]=a[udfn[l]];
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int qx,int v)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
		sum[x]=v;
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx,v);
	modify(x*2+1,mid+1,r,qx,v);
	pushup(x);
}
void query(int x,int l,int r,int ql,int qr,int &ans,int &id)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		if(ans<sum[x])
		{
			ans=sum[x];
			id=sumid[x];
		}
		return;
	}
	int mid=(l+r)/2;
	query(x*2,l,mid,ql,qr,ans,id);
	query(x*2+1,mid+1,r,ql,qr,ans,id);
}
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	f[x]=y;
}
void add(int u,int v)
{
//	printf("add:u=%d,v=%d\n",u,v);
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	if(u<=n)
	{
		dfn[u]=++cnt;
		udfn[cnt]=u;
		dmx[u]=dmn[u]=dfn[u];
	}
	else dmx[u]=0,dmn[u]=1e9;
	c[u][0]=fa;
	for(int i=1;i<=19;i++)
		c[u][i]=c[c[u][i-1]][i-1];
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		dmn[u]=min(dmn[u],dmn[v]);
		dmx[u]=max(dmx[u],dmx[v]);
	}
}
int getans(int u,int k)
{
	for(int i=19;i>=0;i--)
		if(val[c[u][i]]>=k)
			u=c[u][i];
	return u;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&e2[i].u,&e2[i].v);
		e2[i].w=q+1;
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&ql[i][0],&ql[i][1]);
		if(ql[i][0]==2) e2[ql[i][1]].w=i;
	}
	sort(e2+1,e2+m+1);
	pt=n;
	for(int i=1;i<=2*n;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		val[i]=1e9;
	for(int i=1;i<=m;i++)
	{
		int u=e2[i].u,v=e2[i].v,w=e2[i].w;
		if(find(u)!=find(v))
		{
			pt++;
			u=find(u),v=find(v);
			link(u,pt);
			link(v,pt);
			val[pt]=w;
			add(u,pt),add(pt,u);
			add(v,pt),add(pt,v);
		}
	}
	pt++;
	for(int i=1;i<=n;i++)
		if(find(i)!=pt)
		{
			int v=find(i);
			link(v,pt);
			add(v,pt),add(pt,v);
		}
	//for(int i=1;i<=pt;i++)
	//	printf("i=%d,val=%d\n",i,val[i]);
	dfs(pt,0);
	build(1,1,n);
	for(int i=1;i<=q;i++)
		if(ql[i][0]==1)
		{
			int nw=getans(ql[i][1],i),l,r,ans=0,id=0;
			l=dmn[nw],r=dmx[nw];
		//	printf("i=%d,nw=%d,l=%d,r=%d,ans=%d,id=%d\n",i,nw,l,r,ans,id);
			query(1,1,n,l,r,ans,id);
			printf("%d\n",ans);
			if(id) modify(1,1,n,id,0);
		}
	return 0;
}