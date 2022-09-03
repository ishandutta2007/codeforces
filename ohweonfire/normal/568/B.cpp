#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1000000007;
const int maxn=4005;
int c[maxn][maxn],n;
int dp[maxn][maxn],sum[maxn];
int main()
{
	cin>>n;
	for(int i=0;i<=n;i++)for(int j=0;j<=i;j++)
		if(i==0)c[i][j]=1;
		else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=(j*1ll*dp[i-1][j]+dp[i-1][j-1])%mod;
			sum[i]=(sum[i]+dp[i][j])%mod;
		}
	}
	long long ans=1;
	for(int i=1;i<n;i++)
		ans=(ans+c[n][i]*1ll*sum[i])%mod;
	cout<<ans<<endl;
}