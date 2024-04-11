#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=3e5+10;
int n,fa[M],tot,w[M],dfn[M],top[M],sz[M],son[M],ti,tt[M],vis[M],la;
vector<pii>e[M];
vector<int>ans;

struct segment_tree
{
	struct tree
	{
		int val1,val2,sum,tag,tl,tr;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define len(x) (r(x)-l(x)+1)
	#define val1(x) t[(x)].val1
	#define val2(x) t[(x)].val2
	#define sum(x) t[(x)].sum
	#define tag(x) t[(x)].tag
	#define lson k<<1
	#define rson k<<1|1
	void rev(int k){tag(k)^=1,val1(k)=sum(k)-val1(k),val2(k)=len(k)-val2(k);}
	void pushup(int k)
	{
		val1(k)=val1(lson)+val1(rson),
		val2(k)=val2(lson)+val2(rson);
	}
	void pushdown(int k){if (tag(k))rev(lson),rev(rson),tag(k)^=1;}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r)return sum(k)=w[tt[l]],void();
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		sum(k)=sum(lson)+sum(rson);
	}
	void update(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return rev(k),void();
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		update(lson,l,r),update(rson,l,r);
		pushup(k);
	}
	pii query(){return mp(val1(1),val2(1));}
}T;

void dfs1(int u,int f)
{
	sz[u]=1,fa[u]=f;
	for (auto v:e[u])
	{
		if (v.x==f)continue;
		dfs1(v.x,u),sz[u]+=sz[v.x];w[v.x]=v.y;
		if (sz[v.x]>sz[son[u]])son[u]=v.x;
	}
}

void dfs2(int u,int topf)
{
	dfn[u]=++ti,top[u]=topf,tt[ti]=u;
	if (son[u])dfs2(son[u],topf);
	for (auto v:e[u])
	{
		if (v.x==fa[u]||v.x==son[u])continue;
		dfs2(v.x,v.x);
	}
}

void work(int u,int opt=1)
{
	vis[u]=1,tot++;
	while(top[u]!=1)
		T.update(1,dfn[top[u]],dfn[u]),u=fa[top[u]];
	T.update(1,1,dfn[u]);
	auto x=T.query();
	if (x.y*2==tot)la=x.x;
	else la=0;
	if (opt==1)cout<<la<<endl;
}

void print(vector<int>v)
{
	sort(v.begin(),v.end());
	cout<<v.size();
	for (auto x:v)cout<<' '<<x;
	cout<<endl;
}

int dfs3(int u,int fa)
{
	if (!vis[u])return 0; 
	int sz=1;
	for (auto v:e[u])
	{
		if (v.x==fa)continue;
		int c=dfs3(v.x,u);
		if (c)sz^=1,ans.pb(v.y);
	}
	return sz;
}

void work2()
{
	if (la==0)return cout<<0<<endl,void();
	ans.clear();dfs3(1,0);print(ans);
}

signed main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(mp(v,i)),e[v].pb(mp(u,i));
	}
	dfs1(1,0),dfs2(1,1);T.build(1,1,n),work(1,0);
	while(1)
	{
		int opt=read();
		if (opt==0||opt==3)break;
		if (opt==1)
			work(read());
		else
			work2();
	}
	return 0;
}