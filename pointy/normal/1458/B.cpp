#include<bits/stdc++.h>
using namespace std;
int n;
struct bottle
{
	int a,b;
	int id;
}a[101];
int s;
bool used[101];
bool cmp1(bottle x,bottle y)
{
	return x.a>y.a;
}
bool cmp2(bottle x,bottle y)
{
	return x.b>y.b;
}
int dp[101][101][10001];
double ans;
int main()
{
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i].a >> a[i].b;
		s+=a[i].b;
	}
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			for (int k=0;k<=10000;k++)
			{
				if (j==0&&k==0) continue;
				dp[i][j][k]=-10000000;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			for (int k=0;k<=10000;k++)
			{
				if (k>=a[i].a) dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-1][k-a[i].a]+a[i].b);
				else dp[i][j][k]=dp[i-1][j][k];
			}
		}
	}
	for (int k=1;k<=n;k++)
	{
		double ans=0;
		for (int i=0;i<=10000;i++)
		{
			ans=max(ans,1.0*min(1.0*i,0.5*s+0.5*dp[n][k][i]));
		}
		printf("%.10lf ",ans);
	}
	return 0;
}