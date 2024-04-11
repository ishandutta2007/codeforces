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
int siz[205];
V<int> v[205],dp[205];
int a[205],k,to[205];
void dfs(int x,int y){
	dp[x].resize(1,a[x]);
	for(auto u:v[x])if(u!=y){
		#define tou(b) ((int)(dp[u].size())-b-1)
		#define tox(b) ((int)(dp[x].size())-b-1)
		dfs(u,x);
		dp[u].PB(dp[u].back());
		if(dp[x].size()<dp[u].size())swap(dp[x],dp[u]);
		rep(i,0,dp[u].size()){
			int t=dp[x][tox(i)];
			gmax(dp[x][tox(i)],dp[u][tou(i)]+((k-i<dp[x].size())?dp[x][tox(max(i,k-i))]:0));
			gmax(dp[x][tox(i)],t+((k-i<dp[u].size())?dp[u][tou(max(i,k-i))]:0));
		} 
		if(dp[u].size()>=2)
			for(int i=dp[u].size()-2;i>=0;i--)
				gmax(dp[x][tox(i)],dp[x][tox(i-1)]);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n>>k;k++;
	FOR(i,1,n)cin>>a[i];
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1,-1);
	cout<<(*max_element(ALL(dp[1])));
	RE 0;
}