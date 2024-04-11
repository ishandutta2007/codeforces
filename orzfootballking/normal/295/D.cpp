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
int sum[2005][2005],dp[2005][2005],mod=1e9+7; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	if(m==1){
		cout<<0;RE 0;
	}
	FOR(i,2,m)dp[1][i]=1;
	FOR(i,2,n){
		FOR(j,2,m)dp[i][j]=(dp[i-1][j]+2*dp[i][j-1]-dp[i][j-2]+mod)%mod;
	}
	int ans=0;
	FOR(i,1,n){
		FOR(j,2,m){
			sum[i][j]=(sum[i-1][j]+dp[i][j])%mod;
		}
		FOR(j,2,m){
			ans=(ans+sum[i][j]*dp[n-i+1][j]%mod*(m-j+1))%mod;
		}
	}
	cout<<ans;
	RE 0;
}