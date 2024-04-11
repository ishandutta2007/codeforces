#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll dp[301][301],n,d[301][301],i,j,k,a,b,c,res;
	cin>>n;
	for (i=1;i<=n;i++) for (j=1;j<=n;j++)
	{
	cin>>d[i][j]; dp[i][j]=d[i][j];
	}
	for (k=1;k<=n;k++) 
	for (i=1;i<=n;i++) for (j=1;j<=n;j++)
	if (dp[i][j]>dp[i][k]+dp[k][j]) dp[i][j]=dp[i][k]+dp[k][j];
	cin>>k;
	
	for (k=k;k>0;k--) 
	{
	cin>>a>>b>>c;
	res=0;
	if (dp[a][b]>c) 
	{
	dp[a][b]=c;
	dp[b][a]=c;
	}
	for (i=1;i<=n;i++) for (j=1;j<=n;j++)
	{if (dp[i][j]>dp[i][a]+dp[a][b]+dp[b][j]) dp[i][j]=dp[j][i]=dp[i][a]+dp[a][b]+dp[b][j];
	if (dp[i][j]>dp[i][b]+dp[a][b]+dp[a][j]) dp[i][j]=dp[j][i]=dp[i][b]+dp[a][b]+dp[a][j];
	// cout<<dp[i][j]<<' '; if (j==n) cout<<endl; 
	res+=dp[i][j];}
	cout<<res/2<<' ';
	}
}