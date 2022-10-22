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
int dp1[5005],dp2[5005],tag[5005],s[5005];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)cin>>tag[i];
	FOR(i,1,n)cin>>s[i];
	FOR(i,1,n){
		dp1[i]=dp2[i]=0;
	}
	int ans=0;
	FOR(i,1,n){
		for(int j=i-1;j>=1;j--)if(tag[i]!=tag[j]){
			int t=dp2[j];
			gmax(dp2[j],dp1[i]+abs(s[i]-s[j]));
			gmax(dp1[i],max(dp1[j],t)+abs(s[i]-s[j]));
		}
	}
	FOR(i,1,n){
		gmax(ans,dp1[i]);
		gmax(ans,dp2[i]);
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