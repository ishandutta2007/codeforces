#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define ins insert
#define del erase
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int n,ans[M],m,fa[M],ff[M],deg[M],t[M],pos[M],vis[M];
int de[M],top[M],dfn[M],ti,son[M],sz[M],x[M],y[M];
vector<int>e[M];
set<int>s[M];
vector<pair<int,int>>q[M];

int find(int x){return x==ff[x]?x:ff[x]=find(ff[x]);}

void dfs1(int u,int ff)
{
	fa[u]=ff,sz[u]=1,de[u]=de[ff]+1;
	for (auto to:e[u])
	{
		if (to==ff)continue;
		dfs1(to,u);sz[u]+=sz[to];
		if (sz[to]>sz[son[u]])son[u]=to;
	}
}
void dfs2(int u,int topf)
{
	top[u]=topf,dfn[u]=++ti;
	if (son[u]!=0)dfs2(son[u],topf);
	for (auto to:e[u])
	{
		if (to==fa[u]||to==son[u])continue;
		dfs2(to,to);
	}
}
struct segment_tree
{
	struct tree{int tl,tr,val,tag;}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define len(x) (r(x)-l(x)+1)
	#define val(x) t[(x)].val
	#define tag(x) t[(x)].tag
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k)
	{val(k)=val(lson)+val(rson);}
	void pushdown(int k)
	{val(lson)+=tag(k)*len(lson),val(rson)+=tag(k)*len(rson);tag(lson)+=tag(k),tag(rson)+=tag(k);tag(k)=0;}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int r,int z)
	{
		if (l(k)>=l&&r(k)<=r){val(k)+=z*len(k),tag(k)+=z;return;}
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return 0;
		pushdown(k);
		return query(lson,l,r)+query(rson,l,r);
	}
}T1,T2;
void update(int u,int v,int k1,int k2)
{
	while(top[u]!=top[v])
	{
		if (de[top[u]]<de[top[v]])swap(u,v);
		T1.update(1,dfn[top[u]],dfn[u],k1),
		T2.update(1,dfn[top[u]],dfn[u],k2);
		u=fa[top[u]];
	}
	if (de[u]<de[v])swap(u,v);
	T1.update(1,dfn[v],dfn[u],k1),
	T2.update(1,dfn[v],dfn[u],k2);
}

void merge(int u,int v,int lim)
{
	int fv=find(v);ff[find(u)]=fv;vis[u]=1;
//	assert(-x[u]*lim+y[u]-lim>=1);
	int sz=T1.query(1,dfn[u],dfn[u]),cnt=T2.query(1,dfn[u],dfn[u]);
//	assert(sz-1==x[u]),assert(cnt==y[u]);
	update(v,fv,sz,cnt-1);
	if (!vis[fv])
	{
		s[pos[fv]].del(fv);
		x[fv]+=sz,y[fv]+=cnt-1;
		pos[fv]=min(lim,(y[fv]-1)/(x[fv]));
		s[pos[fv]].insert(fv);
	}
//	else if (fv!=1)
//	{
//		int ffv=fa[fv];if (vis[ffv])return;
//		s[pos[ffv]].del(ffv);
//		x[ffv]+=sz,y[ffv]+=cnt-1;
//		pos[ffv]=min(lim,(y[ffv]-1)/(x[ffv]));
//		s[pos[ffv]].insert(ffv);
//	}
}
/*
-x[i]*a+y[i]>=1
y[i]-1>=(x[i]+1)*a
*/

signed main()
{
//	freopen("qwq.txt","r",stdin);
//	freopen("1.out","w",stdout);
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
		deg[u]++,deg[v]++,deg[i+1]--;
	}
	T1.build(1,1,n),T2.build(1,1,n);
	dfs1(1,0),dfs2(1,1);
	m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),k=read();
		q[k].pb(mp(u,i));
	}
	for (int i=1;i<=n;i++)
	{
		x[i]=1,y[i]=deg[i],pos[i]=deg[i]-1,ff[i]=i;
		if (deg[i]!=0)s[pos[i]].ins(i);
	}
	T1.update(1,1,n,1);
	for (int i=1;i<=n;i++)T2.update(1,dfn[i],dfn[i],deg[i]);
//	puts("");
	for (int i=2e5;i>=0;i--)
	{
		while(!s[i].empty())
		{
			int u=*s[i].begin();s[i].del(u);
			if (u!=1)merge(u,fa[u],i);//,cout<<u<<' '<<i<<'\n';
		}
		for (auto x:q[i])
		{
			int tmp=T2.query(1,dfn[x.x],dfn[x.x])-i*(T1.query(1,dfn[x.x],dfn[x.x])-1);
//			if (tmp==0&&deg[x.x]!=0)assert(0);
			ans[x.y]=tmp;
		}
	}
	for (int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}
/*
md 
*/