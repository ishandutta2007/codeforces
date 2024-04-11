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

const int M=3e5+10;
int n,ans,now,a[M],b[M],ti,dfn[M],sz[M],out[M];
vector<int>e1[M],e2[M];

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
		l(k)=l,r(k)=r;tag(k)=val(k)=0;
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

void dfs1(int u)
{
	sz[u]=1,dfn[u]=++ti;
	for (int i=0;i<e2[u].size();i++)
	{
		int to=e2[u][i];dfs1(to);
		sz[u]+=sz[to]; 
	}
}

void dfs2(int u)
{
	int x=T.query(1,dfn[u],dfn[u]);
	if (x==0)now++;
	else T.update(1,dfn[x],dfn[x]+sz[x]-1,-x);
	T.update(1,dfn[u],dfn[u]+sz[u]-1,u);
	if (out[u]==0)ans=max(ans,now);
	for (int i=0;i<e1[u].size();i++)
	{
		int to=e1[u][i];
		dfs2(to);
	}
	if (x==0)now--;
	else T.update(1,dfn[x],dfn[x]+sz[x]-1,x);
	T.update(1,dfn[u],dfn[u]+sz[u]-1,-u);
}

signed main()
{
	WT
	{
		n=read(),ans=now=ti=0;
		for (int i=1;i<=n;i++)e1[i].clear(),e2[i].clear(),out[i]=0;
		for (int i=2;i<=n;i++)
			a[i]=read(),e1[a[i]].pb(i),out[a[i]]++;
		for (int i=2;i<=n;i++)
			b[i]=read(),e2[b[i]].pb(i);
		dfs1(1);T.build(1,1,n);
		dfs2(1);cout<<ans<<endl;
	}
	return 0;
}
/*
1
6
1 1 1 1 2
1 2 1 2 2
*/