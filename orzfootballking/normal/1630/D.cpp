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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,m;
int a[1000005];
int dp[1000005][2];
void solve(){
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	int t=0;
	FOR(i,1,m){
		int x;
		cin>>x;
		t=__gcd(t,x);
	}
	FOR(i,1,n){
		if(i>t){
			dp[i][1]=max(dp[i-t][1]+2*a[i-t]-a[i],dp[i-t][0]-2*a[i-t]-a[i]);
			dp[i][0]=max(dp[i-t][1]+a[i],dp[i-t][0]+a[i]);
		}else{
			dp[i][0]=a[i];
			dp[i][1]=-1e18;
		}
	}
	int ans1=0,ans2=0;
	FOR(i,n-t+1,n){
		ans1+=max(dp[i][0],dp[i][1]);
		ans2+=max(dp[i][0]-2*a[i],dp[i][1]+2*a[i]);
	}
	cout<<max(ans1,ans2)<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}