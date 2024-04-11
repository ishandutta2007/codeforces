#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int M=5e5+10;
int n,q,x[M],y[M],w[M],f[M],ans[M],dis[M];
int dfn[M],top[M],ti,sz[M],ff[M],son[M],de[M];
vector<pair<int,int> >e[M];

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
}T;

void dfs1(int u,int fa)
{
	ff[u]=fa,de[u]=de[fa]+1;sz[u]=1,son[u]=0;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i].x,w=e[u][i].y;
		if (to==fa)continue;dis[to]=dis[u]^w;
		dfs1(to,u);sz[u]+=sz[to];
		if (sz[to]>sz[son[u]])son[u]=to;
	}
}

void dfs2(int u,int topf)
{
	dfn[u]=++ti;top[u]=topf;
	if (son[u])dfs2(son[u],topf);
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i].x;
		if (to==ff[u]||to==son[u])continue;
		dfs2(to,to);
	}
}

int q1(int x,int y)
{
	int res=0;
	while(top[x]!=top[y])
	{
		if (de[top[x]]<de[top[y]])swap(x,y);
		res+=T.query(1,dfn[top[x]],dfn[x]);
		x=ff[top[x]];
	}
	if (de[x]<de[y])swap(x,y);
	res+=T.query(1,dfn[y]+1,dfn[x]);
	return res;
}

void u1(int x,int y)
{
	while(top[x]!=top[y])
	{
		if (de[top[x]]<de[top[y]])swap(x,y);
		T.update(1,dfn[top[x]],dfn[x],1);
		x=ff[top[x]];
	}
	if (de[x]<de[y])swap(x,y);
	T.update(1,dfn[y]+1,dfn[x],1);
}

int find(int x){return x==f[x]?x:f[x]=find(f[x]);}

signed main()
{
	n=read(),q=read();T.build(1,1,n);
	for (int i=1;i<=n;i++)f[i]=i;
	for (int i=1;i<=q;i++)
	{
		x[i]=read(),y[i]=read(),w[i]=read();
		if (find(x[i])!=find(y[i]))
			f[find(x[i])]=find(y[i]),ans[i]=1,
			e[x[i]].pb(mp(y[i],w[i])),e[y[i]].pb(mp(x[i],w[i]));
	}
	for (int i=1;i<=n;i++)
		if (de[i]==0)dfs1(i,0),dfs2(i,i);
	for (int i=1;i<=q;i++)
	{
		if (ans[i])continue;
		if (q1(x[i],y[i]))continue;
		if (dis[x[i]]^dis[y[i]]^w[i]!=1)continue;
		ans[i]=1;u1(x[i],y[i]);
	}
	for (int i=1;i<=q;i++)
		if (ans[i])YES
		else NO
	return 0;
}