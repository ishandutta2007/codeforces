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
int dp[6][100005][2],a[100005];
void solve(){
	int n,k,z;
	cin>>n>>k>>z;
	FOR(i,1,n)cin>>a[i];
	FOR(i,0,n){
		FOR(j,0,z)dp[j][i][0]=dp[j][i][1]=-1e9;
	}
	dp[0][1][0]=a[1];
	FOR(p,0,z){
		if(p){
			FOR(i,1,n-1){
				gmax(dp[p][i][1],dp[p-1][i+1][0]+a[i]);
			}
		}
		rep(i,1,n){
			gmax(dp[p][i+1][0],max(dp[p][i][0],dp[p][i][1])+a[i+1]);
		}
	}
	int t=k+1;
	int ans=0;
	for(int i=t;i>=max(t-z*2,1);i-=2){
		gmax(ans,max(dp[(t-i)/2][i][0],dp[(t-i)/2][i][1]));
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}