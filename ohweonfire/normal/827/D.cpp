// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

#define lson (t<<1)
#define rson ((t<<1)|1)
struct SGT
{
	struct node
	{
		int l,r,mn,v;
	}seg[600111];
	void build(int l,int r,int t=1)
	{
		seg[t].l=l;seg[t].r=r;seg[t].mn=seg[t].v=inf;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(l,mid,lson);
		build(mid+1,r,rson);
	}
	void update(int l,int r,int v,int t=1)
	{
		seg[t].mn=min(seg[t].mn,v);
		if(seg[t].l==l&&seg[t].r==r)
		{
			seg[t].v=min(seg[t].v,v);
			return;
		}
		int mid=(seg[t].l+seg[t].r)>>1;
		if(r<=mid)update(l,r,v,lson);
		else if(l>mid)update(l,r,v,rson);
		else
		{
			update(l,mid,v,lson);
			update(mid+1,r,v,rson);
		}
	}
	int query(int l,int r,int t=1)
	{
		if(seg[t].l==l&&seg[t].r==r)return seg[t].mn;
		int mid=(seg[t].l+seg[t].r)>>1;
		if(r<=mid)return min(seg[t].v,query(l,r,lson));
		else if(l>mid)return min(seg[t].v,query(l,r,rson));
		else return min(seg[t].v,min(query(l,mid,lson),query(mid+1,r,rson)));
	}
}m1;

int f[200111];int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}

vector<int> g[200111];
int n,m,ans[200111],eu[200111],ev[200111],ew[200111],ord[200111];
bool tree[200111];

int top[200111],w[200111],son[200111],sz[200111],fa[200111],tot;
void dfs(int x,int f=0)
{
	fa[x]=f;
	sz[x]=1;
	for(int i=0;i<(int)g[x].size();i++)
		if(g[x][i]!=f)
		{
			dfs(g[x][i],x);
			sz[x]+=sz[g[x][i]];
			if(sz[g[x][i]]>sz[son[x]])son[x]=g[x][i];
		}
}
void dfs2(int x,int f=0)
{
	w[x]=++tot;
	if(son[x])
	{
		top[son[x]]=top[x];
		dfs2(son[x],x);
	}
	for(int i=0;i<(int)g[x].size();i++)
		if(g[x][i]!=f&&g[x][i]!=son[x])
		{
			top[g[x][i]]=g[x][i];
			dfs2(g[x][i],x);
		}
}

bool cmp(int x,int y){return ew[x]<ew[y];}

void update(int u,int v,int val)
{
	int cnt=0;
	while(true)
	{
		if(top[u]==top[v])
		{
			if(w[u]<w[v])m1.update(w[u]+1,w[v],val);
			else if(w[u]>w[v])m1.update(w[v]+1,w[u],val);
			break;
		}
		else if(w[top[u]]>w[top[v]])
		{
			m1.update(w[top[u]],w[u],val);
			u=fa[top[u]];
		}
		else
		{
			m1.update(w[top[v]],w[v],val);
			v=fa[top[v]];
		}
	}
}
int query(int u,int v)
{
	int ret=inf;
	int cnt=0;
	while(true)
	{
		if(top[u]==top[v])
		{
			if(w[u]<w[v])ret=min(ret,m1.query(w[u]+1,w[v]));
			else if(w[u]>w[v])ret=min(ret,m1.query(w[v]+1,w[u]));
			break;
		}
		else if(w[top[u]]>w[top[v]])
		{
			ret=min(ret,m1.query(w[top[u]],w[u]));
			u=fa[top[u]];
		}
		else
		{
			ret=min(ret,m1.query(w[top[v]],w[v]));
			v=fa[top[v]];
		}
	}
	return ret;
}
int main()
{
	get2(n,m);
	for(int i=1;i<=m;i++)
	{
		get3(eu[i],ev[i],ew[i]);
		ord[i]=i;
	}
	
	sort(ord+1,ord+m+1,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int _=1,i;_<=m;_++)
	{
		i=ord[_];
		if(gf(eu[i])!=gf(ev[i]))
		{
			tree[i]=1;
			f[gf(eu[i])]=gf(ev[i]);
			g[eu[i]].pb(ev[i]);
			g[ev[i]].pb(eu[i]);
		}
	}
	
	dfs(1);top[1]=1;dfs2(1);
	
	m1.build(1,n);
	for(int i=1;i<=m;i++)if(tree[i])update(eu[i],ev[i],-ew[i]);
	for(int i=1;i<=m;i++)if(!tree[i])ans[i]=-query(eu[i],ev[i]);
	
	m1.build(1,n);
	for(int i=1;i<=m;i++)if(!tree[i])update(eu[i],ev[i],ew[i]);
	for(int i=1;i<=m;i++)if(tree[i])ans[i]=query(eu[i],ev[i]);
	
	for(int i=1;i<=m;i++)printf("%d ",(ans[i]==inf||ans[i]==-inf)?-1:ans[i]-1);
	return 0;
}