//AFO countdown:???
#include<bits/stdc++.h>
//#define int long long
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

const int M=1e6+10;
int n,k,de[M],vis[M],fa[M][25];
vector<int>e[M];

void dfs(int u,int ff)
{
	fa[u][0]=ff;de[u]=de[ff]+1;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if (to==ff)continue;
		dfs(to,u);
	}
}

void init()
{
	for (int j=1;j<=20;j++)
		for (int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
}

int query(int x)
{
	int y=x;
	for (int j=20;j>=0;j--)
		if (!vis[fa[y][j]])
			y=fa[y][j];
	return de[x]-de[y]+1;
}

void update(int x)
{
	while(!vis[x])
		vis[x]=1,x=fa[x][0];
}

signed main()
{
	n=read(),k=n-read()-1;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	dfs(n,n);vis[n]=1;init();
	for (int i=n-1;i>=1;i--)
	{
		if (query(i)<=k&&!vis[i])
			k-=query(i),update(i);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i])
			cout<<i<<' ';
	return 0;
}