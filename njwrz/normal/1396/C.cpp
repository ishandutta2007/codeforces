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
int lst,a[1000005],cost[1000005],dp[1000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,r1,r2,r3,d;
	cin>>n>>r1>>r2>>r3>>d;
	FOR(i,1,n)cin>>a[i],cost[i]=min((a[i]+2)*r1,r2+r1),gmin(cost[i],a[i]*r1+r3),cost[i]+=cost[i-1];
	FOR(i,1,n){
		dp[i]=dp[i-1]+a[i]*r1+r3+d;
		if(lst<i-1)gmin(dp[i],dp[lst]+(i-lst-1)*d*2+(i-lst)*d+cost[i]-cost[lst]);
		int t=i-1;
		if(dp[t]+(n-t-1)*d*2+(n-t)*d+cost[n]-cost[t]<dp[lst]+(n-lst-1)*d*2+(n-lst)*d+cost[n]-cost[lst]){
			lst=t;
		}
	}
	int ans=dp[n];
	rep(i,0,n-1){
		gmin(ans,dp[i]+(n-i-1)*d+(n-i)*d+cost[n-1]-cost[i]+a[n]*r1+r3);
	}
	cout<<ans-d;
	RE 0;
}