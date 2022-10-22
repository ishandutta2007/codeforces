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
int n,r,ti[100005],x[100005],y[100005],dp[100005],ma[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>r>>n;
	FOR(i,1,n){
		cin>>ti[i]>>x[i]>>y[i];
	}
	x[0]=y[0]=1;
	int ans=0;
	FOR(i,1,n){
		int t=upb(ti,ti+i+1,ti[i]-r*2)-ti;
		if(t){
			dp[i]=ma[t-1]+1;
		}
		rep(j,t,i){
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=ti[i]-ti[j]){
				gmax(dp[i],dp[j]+1);
			}
		}
		if(!dp[i])dp[i]=-1e9;
		ma[i]=max(ma[i-1],dp[i]);
		gmax(ans,dp[i]);
	}
	cout<<ans;
	RE 0;
}