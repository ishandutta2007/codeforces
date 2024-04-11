#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=5005;
const LL mod=1000000007;
LL dp[maxn][maxn];
int n,k,a,b;
int main()
{
	cin>>n>>a>>b>>k;
	for(int i=a;i<=n;i++)
		dp[0][i]=1;
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j<=n;j++)
			if(j<b)
				dp[i][j]=(dp[i-1][j+b-1>>1]-dp[i-1][0]-dp[i-1][j]+dp[i-1][j-1])%mod;
			else if(j>b)
			{
				dp[i][j]=(dp[i-1][n]-dp[i-1][j+b>>1]-dp[i-1][j]+dp[i-1][j-1])%mod;
			}
		for(int j=1;j<=n;j++)
		{
			dp[i][j]+=dp[i][j-1];
		}
	}
	printf("%I64d\n",(dp[k][n]+mod)%mod);
	return 0;
}