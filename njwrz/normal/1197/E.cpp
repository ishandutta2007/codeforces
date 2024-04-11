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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
P<int,int> p[200005],ans[200005],dp[200005];
int n,lb[200005],mod=1e9+7; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int check=0;
	cin>>n;
	FOR(i,1,n)cin>>p[i].F>>p[i].S,gmax(check,p[i].S);
	sort(p+1,p+n+1);
	FOR(i,1,n)lb[i]=p[i].F;
	dp[0]=MP(0,1);
	int t;
	FOR(i,1,n){
		t=upper_bound(lb+1,lb+n+1,p[i].S)-lb-1;
		if(t>=i)continue;
		ans[i].F=dp[t].F+p[i].S;
		ans[i].S=dp[t].S;
		dp[i]=dp[i-1];
		if(ans[i].F-p[i].F<dp[i].F){
			dp[i].F=ans[i].F-p[i].F;
			dp[i].S=ans[i].S;
		}else if(ans[i].F-p[i].F==dp[i].F){
			dp[i].S+=ans[i].S;
			dp[i].S%=mod;
		}
	}
	P<int,int> maxi=MP(mod*mod,0);
	FOR(i,1,n){
		if(p[i].F>check){
			if(maxi.F>ans[i].F){
				maxi=ans[i];
			}else if(maxi.F==ans[i].F){
				maxi.S+=ans[i].S;
				maxi.S%=mod;
			}
		}
	}
	cout<<maxi.S;
	RE 0;
}