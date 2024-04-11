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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
ll n,dp[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)dp[i]=-1e18;
	FOR(i,1,n){
		ll x;
		cin>>x;
		for(int j=i-1;j>=0;j--){
			gmax(dp[j+1],dp[j]+(j+1)*x);
		}
	}
	ll ans=0;
	FOR(i,1,n)gmax(ans,dp[i]);
	cout<<ans;
	RE 0;
}