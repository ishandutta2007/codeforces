// Author: Little09
// Problem: E. Trees of Tranquillity
// Contest: Codeforces Round #722 (Div. 2)
// URL: https://codeforces.com/contest/1529/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=300005;
int n,m; 
int fa[N],fb[N];
vector<int>ta[N],tb[N];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}

int siz[N],son[N],deth[N];
int top[N],dfn[N],rk[N],tot;

namespace ST
{
	ll add[N*4],sum[N*4],mn[N*4];
	inline void push_up(int u)
	{
		if (mn[u*2]==mn[u*2+1])
		{
			sum[u]=sum[u*2]+sum[u*2+1];
			mn[u]=mn[u*2];
		}
		else if (mn[u*2]<mn[u*2+1])
		{
			sum[u]=sum[u*2];
			mn[u]=mn[u*2];
		}
		else
		{
			sum[u]=sum[u*2+1];
			mn[u]=mn[u*2+1];
		}
	}
	inline void push_down(int u)
	{
		if (add[u]==0) return;
		mn[u*2]+=add[u],mn[u*2+1]+=add[u];
		add[u*2]+=add[u],add[u*2+1]+=add[u];
		add[u]=0;
	}
	void build(int u,int l,int r)
	{
		add[u]=0;
		if (l==r) 
		{
			sum[u]=1,mn[u]=N;
			return;
		}
		int mid=(l+r)>>1;
		build(u*2,l,mid),build(u*2+1,mid+1,r);
		push_up(u);
	}
	void change(int u,int L,int R,int l,int r,ll k)
	{
		if (l<=L&&R<=r)
		{
			add[u]+=k,mn[u]+=k;
			return;
		}
		push_down(u);
		int mid=(L+R)>>1;
		if (l<=mid) change(u*2,L,mid,l,r,k);
		if (mid<r)  change(u*2+1,mid+1,R,l,r,k);
		push_up(u);
	}
}
namespace tree
{
	void init()
	{
		for (int i=1;i<=n;i++) deth[i]=0;
		tot=0;
	}
	void dfs1(int u,int f)
	{
		deth[u]=deth[f]+1,son[u]=-1,siz[u]=1;
		for (int i:tb[u])
		{
			if (i==f) continue;
			dfs1(i,u);
			siz[u]+=siz[i];
			if (son[u]==-1||siz[i]>siz[son[u]]) son[u]=i;
		}
	}
	void dfs2(int x,int y)
	{
		top[x]=y,dfn[x]=++tot,rk[tot]=x;
		if (son[x]==-1) return;
		dfs2(son[x],y);
		for (int i:tb[x])
		{
			if (i==fb[x]) continue;
			if (i==son[x]) continue;
			dfs2(i,i);
		}
	}
	void ask(int l,int r,int k)
	{
		if (l>r) swap(l,r);
		ST::change(1,1,n,l,r,k);
	}
	void path(int x,int y,int k)
	{
		ll res=0;
		while (top[x]!=top[y])
		{
			if (deth[x]<deth[y]) swap(x,y);
			ask(dfn[x],dfn[top[x]],k);
			x=fb[top[x]];
		}
		ask(dfn[x],dfn[y],k);
	}
}

ll ans;

void dfs(int x,int f)
{
	//cout << x << endl;
	tree::path(x,x,-N);
	if (fb[x]!=0) tree::path(fb[x],1,1);
	if (ST::mn[1]==0) ans=max(ans,ST::sum[1]);
	for (int i:ta[x])
	{
		if (i==f) continue;
		dfs(i,x);
	}
	tree::path(x,x,N);
	if (fb[x]!=0) tree::path(fb[x],1,-1);
}


void work()
{
	n=read(),ans=0;
	for (int i=1;i<=n;i++) ta[i].clear();
	for (int i=1;i<=n;i++) tb[i].clear();
	for (int i=2;i<=n;i++) fa[i]=read(),ta[fa[i]].push_back(i);
	for (int i=2;i<=n;i++) fb[i]=read(),tb[fb[i]].push_back(i);
	tree::init();
	tree::dfs1(1,0);
	tree::dfs2(1,1);
	ST::build(1,1,n);
	dfs(1,0);
	printf("%d\n",ans);
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}