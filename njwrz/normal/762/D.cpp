/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int a[3][100005],dp[5][100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,0,2){
		FOR(j,0,n-1)cin>>a[i][j];
	}
	FOR(i,0,4){
		FOR(j,0,n)dp[i][j]=-1e18;
	}
	dp[0][0]=0;
	FOR(i,0,n-1){
		gmax(dp[0][i+1],dp[0][i]+a[0][i]);
        gmax(dp[0][i+1],dp[1][i]+a[0][i]+a[1][i]);
        gmax(dp[0][i+1],dp[2][i]+a[0][i]+a[1][i]+a[2][i]);
        gmax(dp[0][i+1],dp[4][i]+a[0][i]+a[1][i]+a[2][i]);

        gmax(dp[1][i+1],dp[1][i]+a[1][i]);
        gmax(dp[1][i+1],dp[0][i]+a[0][i]+a[1][i]);
        gmax(dp[1][i+1],dp[2][i]+a[1][i]+a[2][i]);

        gmax(dp[2][i+1],dp[2][i]+a[2][i]);
        gmax(dp[2][i+1],dp[1][i]+a[2][i]+a[1][i]);
        gmax(dp[2][i+1],dp[0][i]+a[0][i]+a[1][i]+a[2][i]);
        gmax(dp[2][i+1],dp[3][i]+a[0][i]+a[1][i]+a[2][i]);

        gmax(dp[3][i+1],dp[0][i]+a[0][i]+a[1][i]+a[2][i]);
        gmax(dp[4][i+1],dp[2][i]+a[0][i]+a[1][i]+a[2][i]);
	}
	cout<<dp[2][n];
	RE 0;
}