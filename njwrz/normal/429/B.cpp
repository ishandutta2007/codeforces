#include<bits/stdc++.h>
using namespace std;
int a[1002][1002],dp[4][1002][1002];
int main(){
	int i,j,n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)cin>>a[i][j];
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)dp[0][i][j]=max(dp[0][i-1][j],dp[0][i][j-1])+a[i][j];
	}
	for(i=1;i<=n;i++){
		for(j=m;j>=1;j--)dp[1][i][j]=max(dp[1][i-1][j],dp[1][i][j+1])+a[i][j];
	}
	for(i=n;i>=1;i--){
		for(j=m;j>=1;j--)dp[2][i][j]=max(dp[2][i+1][j],dp[2][i][j+1])+a[i][j];
	}
	for(i=n;i>=1;i--){
		for(j=1;j<=m;j++){
			dp[3][i][j]=max(dp[3][i+1][j],dp[3][i][j-1])+a[i][j];
		}
	}
	int ans=0;
	for(i=2;i<n;i++){
		for(j=2;j<m;j++){
			ans=max(ans,dp[0][i-1][j]+dp[1][i][j+1]+dp[2][i+1][j]+dp[3][i][j-1]);
			ans=max(ans,dp[0][i][j-1]+dp[1][i-1][j]+dp[2][i][j+1]+dp[3][i+1][j]);
		}
	}
	cout<<ans;
	return 0;
}