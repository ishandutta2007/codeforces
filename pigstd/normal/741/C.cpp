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

const int M=2e5+10;
int n,a[M],b[M],ans[M],vis[M];
vector<int>e[M];

void dfs(int u)
{
	vis[u]=1;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];if (vis[to])continue;
		ans[to]=ans[u]^1,dfs(to);
	}
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),b[i]=read(),
		e[a[i]].pb(b[i]),e[b[i]].pb(a[i]);
	for (int i=1;i<=n;i++)
		e[i*2-1].pb(2*i),e[2*i].pb(2*i-1);
	for (int i=1;i<=2*n;i++)
		if (!vis[i])dfs(i);
	for (int i=1;i<=n;i++)
		printf("%lld %lld\n",ans[a[i]]+1,ans[b[i]]+1);
	return 0;
}