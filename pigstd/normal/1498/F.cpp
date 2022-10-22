#include<bits/stdc++.h>
#define int long long
#define pb push_back
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
int n,k,f[M][45],g[M][45],de[M],a[M];
vector<int>e[M];

void dfs1(int u,int fa)
{
	de[u]=de[fa]+1;f[u][0]^=a[u];
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];if (to==fa)continue;
		dfs1(to,u);
		for (int j=0;j<2*k;j++)
			f[u][(j+1)%(2*k)]^=f[to][j];
	}
}

void dfs2(int u,int fa)
{
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];if (to==fa)continue;
		for (int j=0;j<2*k;j++)
			g[to][j]=f[to][j];
		for (int j=0;j<2*k;j++)
			g[to][j]^=g[u][(j-1+2*k)%(2*k)]^f[to][(j-2+2*k)%(2*k)];
		dfs2(to,u);
	}
}

signed main()
{
	n=read(),k=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	for (int i=1;i<=n;i++)a[i]=read();
	dfs1(1,0);
	for (int i=0;i<2*k;i++)
		g[1][i]=f[1][i];
	dfs2(1,0);
	for (int i=1;i<=n;i++)
	{
		int res=0;
		for (int j=k;j<2*k;j++)
			res^=g[i][j];
		if (res)cout<<"1 ";
		else cout<<"0 ";
	}
	return 0;
}