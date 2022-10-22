#include<bits/stdc++.h>
using namespace std;
int n,k;
const int mod=1000000007;
long long dp[2001][2001];
inline int read()
{
	char C;
	int F=1,ANS=0;
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
	cin >> k >> n;
	for (int i=1;i<=k;i++) dp[1][i]=1;
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=k;j++)
		{
			for (int p=1;j*p<=k;p++)
			{
				dp[i][j*p]=(dp[i][j*p]+dp[i-1][j])%mod;
			}
		}
	}
	int ans=0;
	for (int i=1;i<=k;i++) ans=(ans+dp[n][i])%mod;
	cout << ans;
	return 0;
}