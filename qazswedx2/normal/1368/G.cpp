#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[500005];
struct pt
{
	int x,l,r,fl;
	pt(int x=0,int l=0,int r=0,int fl=0):x(x),l(l),r(r),fl(fl){}
	bool operator<(const pt p) const
	{
		return x<p.x;
	}
}q[500005];
int n,m,qt;
#define id(x,y) ((x-1)*m+y)
int h[200005],t,deg[200005],dfn[200005],sz[200005],ct;
int sum[2000005],lazy[2000005];
ll ans;
void pushup(int x)
{
	if(!lazy[x])
		sum[x]=sum[x*2]+sum[x*2+1];
}
void col(int x,int v,int l,int r)
{
	lazy[x]+=v;
	if(lazy[x]) sum[x]=r-l+1;
	else pushup(x);
}
void modify(int x,int l,int r,int ql,int qr,int v)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		col(x,v,l,r);
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,ql,qr,v);
	modify(x*2+1,mid+1,r,ql,qr,v);
	pushup(x);
}
void add(int u,int v)
{
//	printf("add:%d %d\n",u,v);
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
	deg[v]++;
}
void dfs(int u,int fa)
{
	if(u) dfn[u]=++ct;
	sz[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
char s[500005];
void ins(int x,int y,int xx,int yy)
{
	q[++qt]=pt(x,xx,yy,1);
	q[++qt]=pt(y+1,xx,yy,-1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s+(i-1)*m+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			char ch=s[id(i,j)];
			if(ch=='U'&&i+2<=n)	add(id(i+2,j),id(i,j));
			if(ch=='D'&&i-2>=1) add(id(i-2,j),id(i,j));
			if(ch=='L'&&j+2<=m) add(id(i,j+2),id(i,j));
			if(ch=='R'&&j-2>=1) add(id(i,j-2),id(i,j));
		}
	for(int i=1;i<=n*m;i++)
		if(!deg[i])
			add(0,i);
	dfs(0,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int u=id(i,j),v;
			char ch=s[id(i,j)];
			if(ch=='U') v=id(i+1,j);
			else if(ch=='L') v=id(i,j+1);
			else continue;
			if((i+j)%2==1) swap(u,v);
			ins(dfn[u],dfn[u]+sz[u]-1,dfn[v],dfn[v]+sz[v]-1);
		}
	sort(q+1,q+qt+1);
	int nw=1;
	for(int i=1;i<=n*m;i++)
	{
		while(nw<=qt&&q[nw].x==i)
		{
			modify(1,1,n*m,q[nw].l,q[nw].r,q[nw].fl);
			nw++;
		}
		ans+=sum[1];
	}
	printf("%lld\n",ans);
	return 0;
}