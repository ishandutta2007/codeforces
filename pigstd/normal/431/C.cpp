#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=105;
const int Mod=1000000007;
int dp[M][M][2],n,d,k,ans;
//dp[i][j][0/1]:ij 1>d0 

signed main()
{
	dp[0][0][0]=1;
	cin>>n>>k>>d;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int kk=1;kk<=min(k,j);kk++)
			{
				if (kk>=d)
					dp[i][j][1]=(dp[i][j][1]+dp[i-1][j-kk][0])%Mod;
				else
					dp[i][j][0]=(dp[i][j][0]+dp[i-1][j-kk][0])%Mod;
				dp[i][j][1]=(dp[i][j][1]+dp[i-1][j-kk][1])%Mod;
			}
	for (int i=1;i<=n;i++)
		ans=(ans+dp[i][n][1])%Mod;
	cout<<ans;
	return 0;
}