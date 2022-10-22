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
int dp[200005][2],p[200005],a[200005],d[200005];
V<int> v[200005],g[200005];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)v[i].clear(),g[i].clear();
	v[1].PB(1);d[1]=1;
	FOR(i,2,n){
		cin>>p[i];
		g[p[i]].PB(i);
	}
	queue<int> q;
	q.emplace(1);
	while(!q.empty()){
		int cur=q.front();q.pop();
		v[d[cur]].PB(cur);
		for(auto u:g[cur]){
			d[u]=d[cur]+1;
			q.emplace(u);
		}
	}
	FOR(i,2,n){
		cin>>a[i];
	}
	FOR(i,1,n)dp[i][0]=dp[i][1]=0;
	int ans=-1e18;
	FOR(i,2,n){
		int max1=-1e18,max2=-1e18,maxi=-1e18,mini=1e18;
		for(auto u:v[i-1]){
			for(auto to:g[u]){
				dp[to][0]=dp[u][1];
				gmax(max1,dp[to][0]+a[to]);
				gmax(max2,dp[to][0]-a[to]);
//				cout<<max2<<' '<<to<<' '<<dp[u][1]<<' '<<u<<"    ";
				gmax(maxi,a[to]);
				gmin(mini,a[to]);
			}
		}
		for(auto u:v[i]){
			dp[u][1]=max(max1-a[u],max2+a[u]);
			gmax(dp[u][1],dp[u][0]+maxi-a[u]);
			gmax(dp[u][1],dp[u][0]+a[u]-mini);
			gmax(ans,dp[u][1]);
		}
//		for(auto u:v[i])cout<<u<<' '<<dp[u][1]<<' '<<max1-a[u]<<' '<<max2+a[u]<<'\n';; 
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