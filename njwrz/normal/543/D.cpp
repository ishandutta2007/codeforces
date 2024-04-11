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
int dp[200005][2],mod=1e9+7;
int p[200005],q[200005];
V<int> v[200005];
void dfs(int x,int fa){
	dp[x][0]=1;
	for(auto u:v[x]){
		dfs(u,x);
		dp[x][0]=dp[x][0]*(1+dp[u][0])%mod;
	}
}
void dfsr(int x,int fa){
	if(v[x].empty())RE;
	p[0]=1;
	rep(i,0,v[x].size()){
		p[i+1]=p[i]*(dp[v[x][i]][0]+1)%mod;
	}
	q[v[x].size()+1]=1;
	for(int i=v[x].size()-1;i>=0;i--){
		q[i+1]=q[i+2]*(dp[v[x][i]][0]+1)%mod;
	}
	rep(i,0,v[x].size()){
		dp[v[x][i]][1]=(p[i]*q[i+2]%mod*dp[x][1]+1)%mod;
	}
	for(auto u:v[x])dfsr(u,x);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,2,n){
		int x;
		cin>>x;
		v[x].PB(i);
	}
	dfs(1,-1);
	dp[1][1]=1;
	dfsr(1,-1);
	FOR(i,1,n){
//		cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
		cout<<dp[i][0]*dp[i][1]%mod<<' ';
	}
	RE 0;
}