#include<bits/stdc++.h> 
using namespace std;  
#define ll long long
#define INF 10000000000000001
  ll n,m,q,i,j,k,t,num[100001][2],presum[100001][2],dp[100001][2],res=0,x,y; char c;
signed main()  
{  
	cin>>n>>m>>x>>y;
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) {cin>>c; if (c=='#') num[j][1]++; else num[j][0]++;}
	for (i=1;i<=m;i++) {presum[i][0]=presum[i-1][0]+num[i][0]; presum[i][1]=presum[i-1][1]+num[i][1];}
	dp[0][0]=0;
	dp[0][1]=0;	
	for (i=1;i<=m;i++) {dp[i][0]=dp[i][1]=INF; for (j=(i-y>0)?i-y:0;j<=i-x;j++) for (k=0;k<2;k++) if (dp[i][k]>dp[j][1-k]+(presum[i][1-k]-presum[j][1-k])) dp[i][k]=dp[j][1-k]+(presum[i][1-k]-presum[j][1-k]);}
	cout<<((dp[m][0]<dp[m][1])?dp[m][0]:dp[m][1]);
}