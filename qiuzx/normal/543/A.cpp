#include <bits/stdc++.h>
#define N 505
using namespace std;
long long dp[N][N]={},n,m,b,mod,a[N],ans=0,lst[N][N]={};
int main(){
	int i,j,k;
	cin>>n>>m>>b>>mod;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	dp[0][0]=1;
	for(k=0;k<n;k++)
	{
		for(i=1;i<=m;i++)
		{
			for(j=0;j<=b;j++)
			{
				if(j>=a[k])
				{
					dp[i][j]=(lst[i][j]+dp[i-1][j-a[k]])%mod;
				}
				lst[i][j]=dp[i][j];
			}
		}
	}
	for(i=0;i<=b;i++)
	{
		ans=(ans+dp[m][i])%mod;
	}
	cout<<ans<<endl;
	return 0;
}