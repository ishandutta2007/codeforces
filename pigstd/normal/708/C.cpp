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

const int M=4e5+10;
int f[M],n,sz[M],rt;
vector<int>e[M],v;

struct node
{
	int x,y;
	void clear(){x=y=0;}
	void add(int a)
	{
		y=max(y,a);
		if (y>x)swap(x,y);
	}
};

void dfs1(int u,int fa)
{
	sz[u]=1;int maxn=0;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];if (to==fa)continue;
		dfs1(to,u),sz[u]+=sz[to],maxn=max(maxn,sz[to]);
	}maxn=max(maxn,n-sz[u]);
	if (maxn<=n/2)rt=u,v.pb(u);
}

void dfs2(int u,int fa,int x)
{
	if (n-sz[u]-x<=n/2)f[u]=1;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];if (to==fa)continue;
		dfs2(to,u,x);
	}
}

signed main()
{
//	freopen("reform.in","r",stdin);
//	freopen("reform.out","w",stdout);
	int TT=1;while(TT--)
	{
		n=read();rt=0;v.clear();
		for (int i=1;i<=n;i++)
			f[i]=0,e[i].clear();
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			e[u].pb(v),e[v].pb(u);
		}
		dfs1(1,0);
		if (v.size()==2)
		{
			for (int i=1;i<=n;i++)printf("1 ");
			puts("");continue;
		}
		dfs1(rt,0);
		node x;x.clear();f[rt]=1;
		for (int i=0;i<e[rt].size();i++)
			x.add(sz[e[rt][i]]);
		for (int i=0;i<e[rt].size();i++)
		{
			int to=e[rt][i];
			dfs2(to,rt,x.x==sz[to]?x.y:x.x);
		}
		for (int i=1;i<=n;i++)
			printf("%lld ",f[i]);puts("");
	}
	return 0;
}
/*
10
1 2
1 5
5 6
1 3
3 4
2 7
7 8
2 9
9 10
*/