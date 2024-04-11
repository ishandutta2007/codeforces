#include <bits/stdc++.h>
using namespace std;
#define lll long long
vector<lll> aa;
lll dp[201][201][2][201],k[2];
int main(){
  lll h, n1,n2, i, a, b,j,l,ll;
	cin>>n1>>n2>>k[0]>>k[1];
	for (i=0;i<2;i++) for (j=0;j<=k[i];j++)
	dp[n1][n2][i][j]=1;
	for (i=n1;i>=0;i--)
	for (j=n2;j>=0;j--) 
	if (i+j<n1+n2)
	for (l=0;l<2;l++)
	for (ll=k[l];ll>=0;ll--){
	if (i==n1)
		if (l==0) dp[i][j][l][ll]=dp[i][j+1][1][1];
		else dp[i][j][l][ll]=dp[i][j+1][l][ll+1];
	else if (j==n2)
		if (l==1) dp[i][j][l][ll]=dp[i+1][j][0][1];
		else dp[i][j][l][ll]=dp[i+1][j][l][ll+1];
	else if (ll==k[l]) if (l==0) dp[i][j][l][ll]=dp[i][j+1][1-l][1]; else dp[i][j][l][ll]=dp[i+1][j][1-l][1];
	else if (l==0) dp[i][j][l][ll]=dp[i][j+1][1][1]+dp[i+1][j][l][ll+1]; else dp[i][j][l][ll]=dp[i][j+1][l][ll+1]+dp[i+1][j][0][1];
	dp[i][j][l][ll]%=100000000;
//	cout<<i<<' '<<j<<' '<<l<<' '<<ll<<' '<<dp[i][j][l][ll]<<endl;
	}
	cout<<dp[0][0][0][0];
}