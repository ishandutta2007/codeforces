#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,w,nxt;
}e[500005];
int n,m,h[100005],t,c[2][100005][20],d[2][100005],sum[2][1000005],fl;
int dfn[2][100005],dmx[2][100005],dmn[2][100005],cnt[2],lazy[2][1000005];
int udfn[2][100005],sumid[2][1000005],f[2][100005],g[2][100005];
int vis[2][100005],qid[2][100005];
ll qans[2][100005];
void add(int u,int v,int w)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
}
void pushup(int x)
{
	sum[fl][x]=max(sum[fl][x*2],sum[fl][x*2+1]);
	if(sum[fl][x]==sum[fl][x*2]) sumid[fl][x]=sumid[fl][x*2];
	else sumid[fl][x]=sumid[fl][x*2+1];
}
void col(int x,int v)
{
	sum[fl][x]+=v;
	lazy[fl][x]+=v;
}
void pushdown(int x)
{
	if(lazy[fl][x])
	{
		col(x*2,lazy[fl][x]);
		col(x*2+1,lazy[fl][x]);
		lazy[fl][x]=0;
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sumid[fl][x]=l;
		sum[fl][x]=d[fl][udfn[fl][l]];
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int ql,int qr,int v)
{
	//if(x==1) printf("modify:ql=%d,qr=%d,v=%d\n",ql,qr,v);
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
void dfs(int u,int fa,int dep)
{
	d[fl][u]=dep;
	c[fl][u][0]=fa;
	for(int i=1;i<=18;i++)
		c[fl][u][i]=c[fl][c[fl][u][i-1]][i-1];
	dmx[fl][u]=0,dmn[fl][u]=1e9;
	int tfl=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+e[i].w);
		if(f[fl][v]>f[fl][u])
		{
			f[fl][u]=f[fl][v];
			g[fl][u]=g[fl][v];
		}
		tfl=1;
		dmx[fl][u]=max(dmx[fl][u],dmx[fl][v]);
		dmn[fl][u]=min(dmn[fl][u],dmn[fl][v]);
	}
	if(!tfl)
	{
		dmx[fl][u]=dmn[fl][u]=dfn[fl][u]=++cnt[fl];
		udfn[fl][cnt[fl]]=u;
		f[fl][u]=dep;
		g[fl][u]=u;
	}
}
int mxl=0,id=0,p1,p2;
void dfs2(int u,int fa,int dep)
{
	if(dep>mxl) mxl=dep,id=u;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u,dep+e[i].w);
	}
}
void solve(int rt)
{
	dfs(rt,0,0);
	build(1,1,cnt[fl]);
	for(int i=1;i<=cnt[fl];i++)
	{
		int u=udfn[fl][sumid[fl][1]];
		qans[fl][i]=qans[fl][i-1]+sum[fl][1];
	//	printf("rt=%d,i=%d,u=%d,ans=%d\n",rt,i,u,sum[fl][1]);
		qid[fl][i]=u;
		while(!vis[fl][u])
		{
			vis[fl][u]=i;
		//	printf("u=%d,fa=%d,d=%d,%d\n",u,c[fl][u][0],d[fl][u],d[fl][c[fl][u][0]]);
			modify(1,1,cnt[fl],dmn[fl][u],dmx[fl][u],d[fl][c[fl][u][0]]-d[fl][u]);
			u=c[fl][u][0];
		}
	}
}
int getans(int u,int k)
{
	for(int i=18;i>=0;i--)
		if(vis[fl][c[fl][u][i]]>=k)
			u=c[fl][u][i];
	return c[fl][u][0];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	mxl=-1;
	dfs2(1,0,0);
	p1=id;
	mxl=-1;
	dfs2(p1,0,0);
	p2=id;
	fl=0;
	solve(p1);
	fl=1;
	solve(p2);
	//printf("p1=%d,p2=%d\n",p1,p2);
	ll las=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=(x+las-1)%n+1,y=(y+las-1)%n+1;
		//printf("x=%d,y=%d\n",x,y);
		if(d[0][x]>d[1][x]) fl=0;
		else fl=1;
		if(vis[fl][x]<=2*y-1)
		{
			printf("%lld\n",las=qans[fl][min(2*y-1,cnt[fl])]);
			continue;
		}
		int u=getans(x,2*y-1);
		int lf=qid[fl][vis[fl][u]];
		int nw=d[fl][lf]-d[fl][u];
		//printf("u=%d,lf=%d,nw=%d\n",u,lf,nw);
		printf("%lld\n",las=max(qans[fl][2*y-2],qans[fl][2*y-1]-nw)+f[fl][x]-d[fl][u]);
	}
	return 0;
}