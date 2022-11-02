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
bool f[200005];
int dp[200005][2];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)cin>>f[i];
	dp[0][1]=0;
	dp[0][0]=1e9;
	FOR(i,1,n){
		dp[i][1]=dp[i-1][0];
		if(i>1)gmin(dp[i][1],dp[i-2][0]);
		dp[i][0]=dp[i-1][1]+f[i];
		if(i>1)gmin(dp[i][0],dp[i-2][1]+f[i]+f[i-1]);
	}
	cout<<min(dp[n][0],dp[n][1])<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}