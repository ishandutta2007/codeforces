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
int dp[5005][5005],k,d[5005],t[5005];
int n,mod=998244353;
V<int> v[5005];
void dfs(int x,int fa){
	dp[x][0]=1;
	for(auto u:v[x])if(u!=fa){
		dfs(u,x);
		FILL(t,0);
		FOR(i,0,d[x]){
			FOR(j,0,d[u])if(i+j<=k){
				t[max(i,j)]=(t[max(i,j)]+dp[x][i]*dp[u][j])%mod;
			}
		}
		gmax(d[x],d[u]);
		FOR(i,0,d[x])dp[x][i]=t[i];
	}
	d[x]++;
	for(int i=d[x];i>=1;i--){
		dp[x][i]=dp[x][i-1];
	}
	dp[x][0]=0;
	FOR(i,1,d[x])if(i<=k+1){
		dp[x][0]=(dp[x][0]+dp[x][i])%mod;
	}
//	FOR(i,0,d[x])cout<<dp[x][i]<<' ';
//	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1,-1);
	cout<<dp[1][0];
	RE 0;
}