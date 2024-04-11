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
int dp[205][405];
int ti[205];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)cin>>ti[i];
	sort(ti+1,ti+n+1);
	FOR(i,1,n){
		FOR(j,0,2*n){
			dp[i][j]=1e9;
			rep(k,0,j){
				gmin(dp[i][j],dp[i-1][k]+abs(ti[i]-j));
//				cout<<dp[i-1][k]<<' ';
			}
//			cout<<'\n';
		}
	}
	int ans=1e9;
	FOR(i,1,2*n){
		gmin(ans,dp[n][i]);
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}