#include <bits/stdc++.h>
using namespace std;
int arr[10001];
int dp[3001][3001];
int maxx[3001];
int t,t1,n,m,i,j,k,u,v,a,b;
int main()
{
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n;
		for (i=1;i<=n;i++) cin>>arr[i];
		v=0;
		for (i=n-1;i>=1;i--) 
		{
		if (i+arr[i]>=n) dp[i][n]=v; else {
		dp[i][n]=-1e4; if (arr[i]) v++;}
		}
	//	for (i=n;i>=1;i--) for (j=i-1;j>=1;j--) cout<<j<<' '<<i<<' '<<dp[j][i]<<endl;
		for (j=n-1;j>1;j--)
		{
			if (arr[j]==0) for (i=1;i<j;i++) dp[i][j]=-1e4;
			else
			{
				for (i=1;i<=n;i++) maxx[i]=-1e4;
				u=-1e4;
				for (i=j+arr[j];i>=j+1;i--)
				{
					u=max(u,dp[j][i]);
					maxx[i]=u;
				}
					v=0;
				for (i=j-1;i>=1;i--)
				{
					if (i+arr[i]<j) dp[i][j]=-1e4;
					else if (i+arr[i]>=j+arr[j]) dp[i][j]=-1e4;
					else dp[i][j]=1+maxx[i+arr[i]+1]+v;
					if ((arr[i])and(i+arr[i]<j)) v++;
				}
			}
		}
//		for (i=n;i>=1;i--) for (j=i-1;j>=1;j--) cout<<j<<' '<<i<<' '<<dp[j][i]<<endl;
		u=0;
		v=0;
		for (i=2;i<=1+arr[1];i++) u=max(u,2+dp[1][i]);
		for (i=1;i<=n;i++) if (arr[i]) v++;
	//	cout<<u<<' '<<v<<endl;
		cout<<v-(u-1)<<endl;
	}
}
// 4 0 4 2 1 0 2 0 0