#include <bits/stdc++.h>
#define INF 10000000000000010
using namespace std;
int main()
{
	int n,t,c,i,j;
	long long dp[2005];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		dp[i]=INF;
	}
	dp[0]=0;
	for(i=0;i<n;i++)
	{
		cin>>t>>c;
		for(j=n;j>0;j--)
		{
			dp[j]=min(dp[j],dp[max(0,j-t-1)]+c);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}