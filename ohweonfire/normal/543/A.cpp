#include <bits/stdc++.h>
using namespace std;
const int maxn=505;
int n,m,b,mod,a[maxn],dp[maxn][maxn];
int main()
{
	cin>>n>>m>>b>>mod;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=a[i];k<=b;k++)
			{
				dp[j][k]+=dp[j-1][k-a[i]];
				if(dp[j][k]>=mod)dp[j][k]-=mod;
			}
	int ans=0;
	for(int i=0;i<=b;i++)
	{
		ans+=dp[m][i];
		if(ans>=mod)ans-=mod;
	}
	cout<<ans<<endl;
	return 0;
}