#include<bits/stdc++.h>
#define piir pair<int,int>
#define int long long
#define ll long long
using namespace std;
const int N=3e3+5;
const int inf=1e18;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

inline void up(piir &x,piir y){if (x<y) x=y;}
piir dp[N][N],tmp[N];
int a[N],siz[N];
vector<int>e[N];
void dfs(int now,int father)
{
	siz[now]=1;
	dp[now][1]=make_pair(0,a[now]);
	for (int to:e[now])
	{
		if (to==father) continue;
		dfs(to,now);
		for (int i=1;i<=siz[now];i++)
		for (int j=1;j<=siz[to];j++)
		{
			up(tmp[i+j],make_pair(dp[now][i].first+dp[to][j].first+(dp[to][j].second>0),dp[now][i].second));
			up(tmp[i+j-1],make_pair(dp[now][i].first+dp[to][j].first,dp[now][i].second+dp[to][j].second));
		}
		siz[now]+=siz[to];
		for (int i=1;i<=siz[now];i++) dp[now][i]=tmp[i],tmp[i]=make_pair(-inf,-inf);
	}
}
void ACDC()
{
	int n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) a[i]=read()-a[i];
	for (int i=1;i<=n;i++) e[i].clear();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) dp[i][j]=make_pair(-inf,-inf);
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	print(dp[1][m].first+(dp[1][m].second>0));
}

signed main()
{
	for (int i=0;i<N;i++) tmp[i]=make_pair(-inf,-inf);
	int T=read();
	while (T--) ACDC();
	
	return 0;
}