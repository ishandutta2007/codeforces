#include <bits/stdc++.h>
using namespace std;
int t[500007];
int a[500007],dp[3][5007];
pair<int,int> b[500007];
vector<int> bi;
int main()
{
	int n,k;
	scanf("%d%d",&k,&n);
	for(int i=0;i<n;i++) scanf("%d",&t[i]);
	sort(t,t+n);
	for(int i=0;i<n-1;i++) a[i]=t[i+1]-t[i];
	for(int i=0;i<n-1;i++) b[i]=make_pair(a[i],i);
	sort(b,b+n-1);
	for(int i=0;i<fmin((3*k),n-1);i++) bi.push_back(b[i].second);
	sort(bi.begin(),bi.end());
	dp[0][0]=dp[1][0]=dp[2][0]=0;
	for(int i=1;i<=k;i++) dp[1][i]=dp[2][i]=1000000007;
	for(int i=0;i<bi.size();i++) 
	{
	    for(int j=k;j>=1;j--) 
		{
			dp[0][j]=fmin(dp[1][j],dp[2][j-1]+a[bi[i]]);
			if(i>0 && bi[i]>bi[i-1]+1) dp[0][j]=fmin(dp[0][j],dp[1][j-1]+a[bi[i]]);
		}
	    for(int j=0;j<=k;j++) dp[2][j]=dp[1][j];
	    for(int j=0;j<=k;j++) dp[1][j]=dp[0][j];
	    for(int j=1;j<=k;j++) dp[0][j]=1000000007;
	}
	printf("%d",dp[1][k]);
}