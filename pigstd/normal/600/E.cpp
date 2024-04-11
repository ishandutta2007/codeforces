#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int T=read();while(T--) 
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

const int M=1e5+10;
int n,c[M],rt[M],cnt,ans[M];
vector<int>e[M];
struct tree
{
	int lson,rson,maxn,val;
}t[M<<6];
#define lson(x) t[(x)].lson
#define rson(x) t[(x)].rson
#define maxn(x) t[(x)].maxn
#define val(x) t[(x)].val

void pushup(int now)
{
	if (maxn(lson(now))>maxn(rson(now)))
	{
		maxn(now)=maxn(lson(now));
		val(now)=val(lson(now));
	}
	else if (maxn(lson(now))<maxn(rson(now)))
	{
		maxn(now)=maxn(rson(now));
		val(now)=val(rson(now));
	}
	else
	{
		maxn(now)=maxn(rson(now));
		val(now)=val(lson(now))+val(rson(now));
	}
}

void update(int &now,int l,int r,int k,int x)
{
	if (!now)now=++cnt;
	if (l==r)
	{
		maxn(now)++;
		val(now)=l;
		return;
	}int Mid=(l+r)>>1;
	if (k<=Mid)update(lson(now),l,Mid,k,x);
	else update(rson(now),Mid+1,r,k,x);
	pushup(now);
}

int merge(int p1,int p2,int l,int r)
{
	if (!p1)return p2;if (!p2)return p1;
	if (l==r)
	{
		maxn(p1)+=maxn(p2);
		val(p1)=l;
		return p1;
	}int Mid=(l+r)>>1;
	lson(p1)=merge(lson(p1),lson(p2),l,Mid);
	rson(p1)=merge(rson(p1),rson(p2),Mid+1,r);
	pushup(p1);return p1;
}

void dfs(int u,int fa)
{
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];if (to==fa)continue;
		dfs(to,u);rt[u]=merge(rt[u],rt[to],1,n);
	}update(rt[u],1,n,c[u],1);
	ans[u]=val(rt[u]);
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)c[i]=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}