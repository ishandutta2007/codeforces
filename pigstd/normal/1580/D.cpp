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

const int inf=1e18;
const int M=4010;
int n,m,a[M],dp[M][M],son[M][2];
int st[M],top,sz[M],tmp[M];
vector<int>e[M];

void dfs(int u)
{
	for (int i=1;i<=m;i++)dp[u][i]=-inf;
	sz[u]=1;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];dfs(to);
		for (int j=1;j<=m;j++)
			tmp[j]=-inf;
		for (int i=0;i<=sz[u];i++)
			for (int j=0;j<=sz[to]&&i+j<=m;j++)
				tmp[i+j]=max(tmp[i+j],dp[u][i]+dp[to][j]-2*a[u]*i*j);
		for (int j=0;j<=m;j++)
			dp[u][j]=tmp[j];sz[u]+=sz[to];
	}
	for (int i=m;i>=1;i--)
		dp[u][i]=max(dp[u][i],dp[u][i-1]+m*a[u]-(2*i-1)*a[u]);
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		while(a[st[top]]>a[i]&&top>0)son[i][0]=st[top],top--;
		if (top!=0)son[st[top]][1]=i;st[++top]=i;
	}int rt=st[1];
	for (int i=1;i<=n;i++)
	{
		if (son[i][0])e[i].pb(son[i][0]);//,cout<<i<<' '<<son[i][0]<<' ';
		if (son[i][1])e[i].pb(son[i][1]);//,cout<<i<<' '<<son[i][1]<<' ';
	}
	dfs(rt);
	cout<<dp[rt][m]<<endl;
	return 0;
}