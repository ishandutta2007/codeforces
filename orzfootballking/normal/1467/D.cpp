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
int dp[5005][5005],a[5005],s[5005],mod=1e9+7;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k,q;
	cin>>n>>k>>q;
	FOR(i,1,n)cin>>a[i];
	int x,y;
	FOR(i,1,n)dp[0][i]=1;
	FOR(i,1,k){
		FOR(j,1,n){
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%mod;
		}
	}
	FOR(i,1,n){
		FOR(j,0,k)s[i]=(s[i]+dp[j][i]*dp[k-j][i])%mod;
	} 
	int ans=0;
	FOR(i,1,n)ans=(ans+s[i]*a[i])%mod;
	FOR(i,1,q){
		cin>>x>>y;
		ans=(ans+(y-a[x])*s[x])%mod;
		ans=(ans+mod)%mod;
		a[x]=y;
		cout<<ans<<'\n';
	}
	RE 0;
}