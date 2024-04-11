#include<bits/stdc++.h>

using namespace std;

const int N=3e5+10;

int n,a[N],dp[N][110];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]),a[i]/=100;
	for(int i=0;i<=n;i++)
	for(int j=0;j<110;j++)
		dp[i][j]=1e9;
	dp[0][0]=0;
	for (int i=0;i<n;i++)
	for (int j=0;j<=102;j++){
		if (j>=a[i+1]) dp[i+1][j-a[i+1]]=min(dp[i+1][j-a[i+1]],dp[i][j]);
			else dp[i+1][0]=min(dp[i+1][0],dp[i][j]+a[i+1]-j);
		dp[i+1][j+a[i+1]/10]=min(dp[i+1][j+a[i+1]/10],dp[i][j]+a[i+1]);
	}
	printf("%lld\n",100ll*dp[n][0]);
	return 0;
}