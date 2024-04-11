/*

DP





ll int
 dp 










*/
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
int dp[200005][22];
int a[200005];
int lst[10000005];
void solve(){
	int n,k;
	cin>>n>>k;
	FOR(i,1,n){
		cin>>a[i];
		for(int j=2;j*j<=a[i];j++)if(a[i]%(j*j)==0){
			while(a[i]%(j*j)==0){
				a[i]/=(j*j);
			}
		}
	}
	FOR(i,1,n)FOR(j,0,k)dp[i][j]=1e9;
	set<int> s;s.emplace(0);
	FOR(i,1,n){
		if(lst[a[i]])s.emplace(lst[a[i]]);
		lst[a[i]]=i;
		FOR(j,0,k){
			auto u=s.end();u--;
			FOR(m,0,j){
				gmin(dp[i][j],dp[*u][j-m]+1);
				if(u==s.begin())break;
				u--;
			}
		}
	}
	FOR(i,1,n)lst[a[i]]=0;
	int ans=1e9;
	FOR(i,0,k)gmin(ans,dp[n][i]);
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