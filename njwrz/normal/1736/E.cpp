#include<bits/stdc++.h>
#define gmax(x,y) x=max(x,y)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int dp[505][505][505];
int a[505],s[505],n;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i],s[i]=s[i-1]+a[i];
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;
	FOR(i,0,n-1)FOR(j,0,n)FOR(k,0,n)if(dp[i][j][k]>=0){
		int now=dp[i][j][k]+a[j];
		gmax(dp[i+1][j][k],now);
		if(j<=i)gmax(dp[i+1][i+1][k+1],now);
		if(i+2<=n)gmax(dp[i+1][i+2][k],now);
		if(k)gmax(dp[i][j+1][k-1],dp[i][j][k]);
	}
	int ans=0;
	FOR(i,0,n)FOR(j,0,n)gmax(ans,dp[n][i][j]+a[i]);
	cout<<ans;
	return 0;
}