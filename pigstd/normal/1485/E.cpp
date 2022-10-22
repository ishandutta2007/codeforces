#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int M=2e5+10;
const int MAXN=1e18;
int T,n,dp[M],a[M],f[M];
int maxn[M],minn[M];
vector<int>e[M],de[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void clear()
{
	for (int i=1;i<=n;i++)dp[i]=maxn[i]=0,minn[i]=MAXN;
	for (int i=1;i<=n;i++)e[i].clear(),de[i].clear();
}

void dfs(int u,int dep)
{
	de[dep].pb(u),maxn[dep]=max(maxn[dep],a[u]),minn[dep]=min(minn[dep],a[u]);
	for (int i=0;i<e[u].size();i++)
		dfs(e[u][i],dep+1);
}

void solve()
{
	dfs(1,1);int ans=0;
	for (int i=2;i<=n;i++)
	{
		if (de[i].size()==0)continue;
		int max1=-MAXN,max2=-MAXN;
		for (int j=0;j<de[i].size();j++)
		{
			int u=de[i][j];int fa=f[u];
			max1=max(max1,dp[fa]-a[u]),
			max2=max(max2,dp[fa]+a[u]);
		}
		for (int j=0;j<de[i].size();j++)
		{
			int u=de[i][j];int fa=f[u];
			dp[u]=max(max(a[u]-minn[i]+dp[fa],maxn[i]-a[u]+dp[fa]),
			max(max1+a[u],max2-a[u]));
		}
		for (int j=0;j<de[i].size();j++)
			ans=max(ans,dp[de[i][j]]);
	}
//	for (int i=1;i<=n;i++)
//		cout<<dp[i]<<' ';
//	puts("");
	cout<<ans<<endl;
	return;
}

signed main()
{
	T=read();
	while(T--)
	{
		n=read();clear();
		for (int i=2;i<=n;i++)f[i]=read(),e[f[i]].pb(i);
		for (int i=2;i<=n;i++)a[i]=read();
		solve();
	}
	return 0;
}