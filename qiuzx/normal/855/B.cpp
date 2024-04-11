#include <bits/stdc++.h>
#define N 100010
using namespace std;
long long dp[N][3];
int main(){
	long long n,p,q,r,a[N],i;
	cin>>n>>p>>q>>r;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<N;i++)
	{
		dp[i][0]=dp[i][1]=dp[i][2]=-3e18;
	}
	for(i=1;i<=n;i++)
	{
		dp[i][0]=max(dp[i-1][0],p*a[i]);
		dp[i][1]=max(max(dp[i-1][0]+q*a[i],dp[i-1][1]),dp[i][0]+q*a[i]);
		dp[i][2]=max(max(dp[i-1][1]+r*a[i],dp[i-1][2]),dp[i][1]+r*a[i]);
	}
	cout<<dp[n][2]<<endl;
	return 0;
}