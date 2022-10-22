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

const int Mod=998244353;
const int M=5010;
int n,k,tmp[M],dp[M][M],sz[M],sum[M];
vector<int>e[M];

void dfs(int u,int fa)
{
	dp[u][0]=1;sz[u]=1;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];if (to==fa)continue;
		dfs(to,u);memset(tmp,0,sizeof(tmp));
		for (int i=0;i<=sz[u]&&i<=k;i++)
			for (int j=0;j<=sz[to]&&i+j+1<=k;j++)
				tmp[max(i,j+1)]=(tmp[max(i,j+1)]+dp[u][i]*dp[to][j])%Mod;
		for (int i=0;i<=k;i++)
			dp[u][i]=(dp[u][i]*sum[to]+tmp[i])%Mod;
		sz[u]+=sz[to];
	}
	for (int i=0;i<=k;i++)sum[u]=(sum[u]+dp[u][i])%Mod;
}

signed main()
{
	n=read(),k=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
//	puts("qwq");
	dfs(1,0);int ans=0;
	for (int i=0;i<=k;i++)
		ans=(ans+dp[1][i])%Mod;
	cout<<ans<<endl;
	return 0;
}