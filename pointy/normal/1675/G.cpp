// Author: Little09
// Problem: CF1675G Sorting Pancakes
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1675G
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define endl "\n"
#define lowbit(x) (x&(-x))

const int inf=1e7; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=255;
int n,m; 
int a[N],dp[N][N][2*N],s[2*N][N];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[n+1-i]=read();
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=m;j++)
		{
			for (int k=-m;k<=m;k++)
			{
				dp[i][j][k+m]=inf;
			}
		}
	}
	dp[0][0][m]=0;
	for (int i=0;i<=n;i++)
	{
		if (i!=0)
		{
			for (int j=0;j<=m;j++)
			{
				for (int k=-m;k<=m;k++)
				{
					int u=k-(a[i]-j);
					if (abs(u)>m) continue;
					dp[i][j][k+m]=min(dp[i][j][k+m],dp[i-1][j][u+m]+abs(u));
				}
			}	
		}
		for (int k=-m;k<=m;k++)
		{
			for (int j=1;j<=m;j++)
			{
				dp[i][j][k+m]=min(dp[i][j][k+m],dp[i][j-1][k+m]);
			}
		}
	}
	int ans=inf;
	for (int i=0;i<=m;i++) ans=min(ans,dp[n][i][m]);
	cout << ans;
	return 0;
}