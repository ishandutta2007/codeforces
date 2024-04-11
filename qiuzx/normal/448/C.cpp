#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 5010
using namespace std;
int n,a[N],dp[N][N],ans=INF;
int main(){
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	memset(dp,63,sizeof(dp));
	dp[0][0]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=min(a[i],n);j++)
		{
			dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
			if(j!=a[i])
			{
				dp[i+1][min(j,a[i+1])]=min(dp[i+1][min(j,a[i+1])],dp[i][j]+1);
			}
			else
			{
				dp[i+1][min(j,a[i+1])]=min(dp[i+1][min(j,a[i+1])],dp[i][j]);
			}
		}
	}
	for(i=0;i<=min(a[n-1],n);i++)
	{
		ans=min(ans,dp[n][i]);
	}
	cout<<ans<<endl;
	return 0;
}