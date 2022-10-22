// By: Little09
// Problem: CF1077F1 Pictures with Kittens (easy version)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1077F1
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1000000000000000000;
const int N=205;
int n,m,k;
ll a[N],dp[N][N];
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
	n=read(),k=read(),m=read();
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=m;j++)
		{
			dp[i][j]=-inf;
		}
	}
	for (int i=1;i<=n;i++) a[i]=read();
	dp[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		int u=min(i,m),p=max(0,i-k);
		for (int j=1;j<=u;j++)
		{
			for (int w=p;w<i;w++)
			{
				dp[i][j]=max(dp[i][j],dp[w][j-1]+a[i]);
			}
		}
	}
	ll ans=-1;
	for (int i=n-k+1;i<=n;i++) ans=max(ans,dp[i][m]);
	cout << ans;
	return 0;
}