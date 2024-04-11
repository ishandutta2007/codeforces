/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
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
int dp[105][105],a[105],b[105];
void solve(){
	int n,m;
	cin>>n;
	FOR(i,1,n)cin>>a[i],a[i]+=a[i-1];
	cin>>m;
	FOR(i,1,m)cin>>b[i],b[i]+=b[i-1];
	FOR(i,0,n){
		FOR(j,0,m){
			dp[i][j]=-1e9;
			if(i){
				gmax(dp[i][j],max(dp[i-1][j],(a[i]+b[j])));
			}
			if(j){
				gmax(dp[i][j],max(dp[i][j-1],(a[i]+b[j])));
			}
			if(!i&&!j)dp[i][j]=0;
		}
	}
	cout<<max(0,dp[n][m])<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}