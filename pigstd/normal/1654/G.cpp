#include<bits/stdc++.h>
//#define int long long
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

const int M=2e5+10; 
const int inf=1e9;
int n,h[M],p[M],ans[M],sum,dp[1000][M],p1[M],p2[M],cnt,vis[M];
vector<int>e[M],v[M],vv[M];

void dfs1(int u,int fa=0)
{
	for (auto v:e[u])
		if (v!=fa)dfs1(v,u),ckmin(h[u],h[v]+1);
}

void dfs2(int u,int fa=0)
{
	for (auto v:e[u])
		if (v!=fa)ckmin(h[v],h[u]+1),dfs2(v,u);
}

void dfs3(int u,int fa=0)
{
	vis[u]=1;dp[p2[u]][u]=0;
	for (auto v:e[u])
	{
		if (v==fa||h[u]!=h[v])continue;
		dfs3(v,u);
		for (int i=1;i<=cnt;i++)ckmin(dp[i][u],dp[i][v]+1);
	}
}

void dfs4(int u,int fa=0)
{
	for (auto v:e[u])
	{
		if (v==fa||h[u]!=h[v])continue;
		for (int i=1;i<=cnt;i++)
			ckmin(dp[i][v],dp[i][u]+1);
		dfs4(v,u);
	}
}

signed main()
{
	n=read();memset(h,0x3f,sizeof(h));
	for (int i=1;i<=n;i++)
		if (read())h[i]=0;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}dfs1(1),dfs2(1);
	for (int i=1;i<=n;i++)
		for (auto j:e[i])
			if (h[i]==h[j]){v[h[i]].pb(i),sum+=h[i];break;}
	for (int i=1;i<=n;i++)ans[i]=h[i],vv[h[i]].pb(i);
//	assert(sum<=2*n);
	for (int i=0;i<=n;i++)
		if (v[i].size())
		{
			p1[++cnt]=i;
			for (auto x:v[i])p2[x]=cnt;
		}
	if (cnt>=1000)while(1);
	memset(dp,0x3f,sizeof(dp));
	for (int i=0;i<=n;i++)
	{
		for (auto u:vv[i])
			for (auto j:e[u])
				if (h[j]==h[u]-1)
					for (int k=1;k<=cnt;k++)ckmin(dp[k][u],max(0,dp[k][j]-1));
		for (auto u:v[i])
			if (!vis[u])dfs3(u),dfs4(u);
	}
	for (int i=1;i<=n;i++)for (int j=1;j<=cnt;j++)if (!dp[j][i]){ans[i]=p1[j];break;}
	for (int i=1;i<=n;i++)cout<<h[i]*2-ans[i]<<' ';
	return 0;
}
/*
tm OI  
*/