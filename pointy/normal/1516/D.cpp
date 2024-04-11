// Author: Little09
// Problem: CF1516D Cut
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1516D
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+5;
int a[N];
int dp[N][21];
int f[N],res;
inline void update(int x,int y)
{
	x=a[x];
	for (int i=2;i<=sqrt(x);i++)
	{
		if (x%i==0)
		{
			res-=(f[i]>1);
			f[i]+=y;
			res+=(f[i]>1);
			while (x%i==0) x/=i;
		}
	}
	if (x>1) 
	{
		res-=(f[x]>1);
		f[x]+=y;
		res+=(f[x]>1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	int l=1;
	for (int i=1;i<=n;i++)
	{
		if (i!=1) update(i-1,-1);
		else update(i,1);
		while (l<n)
		{
			update(l+1,1);
			if (res>=1) 
			{
				update(l+1,-1);
				break;
			}
			l++;
		}
		dp[i][0]=l+1;
	}
	dp[n+1][0]=n+2,dp[n+2][0]=n+2;
	for (int j=1;j<=20;j++)
	{
		dp[n+1][j]=n+2,dp[n+2][j]=n+2;
		for (int i=1;i<=n;i++)
		{
			dp[i][j]=dp[dp[i][j-1]][j-1];
		}
	}
	for (int i=1;i<=m;i++)
	{
		int l,r;
		cin >> l >> r;
		int ans=0;
		for (int i=20;i>=0;i--)
		{
			if (dp[l][i]-1<=r) ans|=(1<<i),l=dp[l][i];
		}
		if (l<=r) ans++;
		cout << ans << endl;
	}
	return 0;
}