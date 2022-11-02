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
V<int> v[300005];
int mod=998244353,n,dp[300005][2][2];
void dfs(int p,int fa){
	int d[2][2][2]={};
	bool f=1;
	d[0][1][0]=d[0][0][0]=1;
	for(auto u:v[p])if(u!=fa){
		dfs(u,p);
		FILL(d[f],0);
		d[f][0][0]=(d[f][0][0]+d[f^1][0][0]*(dp[u][0][0]+dp[u][0][1]+dp[u][1][1])%mod)%mod;
		d[f][0][1]=(d[f][0][1]+d[f^1][0][1]*(dp[u][0][0]*2+dp[u][0][1]*2+dp[u][1][0]+dp[u][1][1]*2)%mod+
		d[f^1][0][0]*(dp[u][0][0]+dp[u][0][1]+dp[u][1][0]+dp[u][1][1])%mod)%mod;
		d[f][1][0]=(d[f][1][0]+d[f^1][1][0]*(dp[u][0][0]+dp[u][0][1]+dp[u][1][1])%mod)%mod;
		d[f][1][1]=(d[f][1][1]+d[f^1][1][1]*(dp[u][0][0]*2+dp[u][0][1]*2+dp[u][1][1])%mod+
		d[f^1][1][0]*(dp[u][0][0]+dp[u][0][1])%mod)%mod;
		f^=1;
	} 
	rep(i,0,2)rep(j,0,2)dp[p][i][j]=d[f^1][i][j]; 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int x,y;
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1,-1);
	cout<<(dp[1][0][1]+dp[1][0][0]+dp[1][1][1]-1+mod)%mod;
	RE 0;
}