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

const int inf=1e18;
const int M=510;
const int N=25;
int n,m,k,v1[M][M],v2[M][M],dp[M][M][N];

signed main()
{
	n=read(),m=read(),k=read();
	if (k&1)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
				cout<<"-1 ";
			puts("");
		}
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<m;j++)
			v1[i][j]=read();
	for (int i=1;i<n;i++)
		for (int j=1;j<=m;j++)
			v2[i][j]=read();
	for (int i=1;i<=n;i++)
		v1[i][0]=v1[i][m]=inf;
	for (int j=1;j<=m;j++)
		v2[0][j]=v2[n][j]=inf;
	for (int t=2;t<=k;t+=2)
	{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			{
				dp[i][j][t]=dp[i][j][t-2]+
				min(min(v1[i][j],v1[i][j-1]),min(v2[i][j],v2[i-1][j]))*2;
				dp[i][j][t]=min(dp[i][j][t],dp[i][j+1][t-2]+2*v1[i][j]);
				dp[i][j][t]=min(dp[i][j][t],dp[i][j-1][t-2]+2*v1[i][j-1]);
				dp[i][j][t]=min(dp[i][j][t],dp[i+1][j][t-2]+2*v2[i][j]);
				dp[i][j][t]=min(dp[i][j][t],dp[i-1][j][t-2]+2*v2[i-1][j]);
			}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			cout<<dp[i][j][k]<<' ';
		puts("");
	}
}