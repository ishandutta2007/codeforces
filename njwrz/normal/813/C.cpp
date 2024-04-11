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
int d[2][200005];
V<int> g[200005];
void dfs(int x,int fa,int tap){
	for(auto u:g[x])if(u!=fa){
		d[tap][u]=d[tap][x]+1;
		dfs(u,x,tap);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,x;
	cin>>n>>x;
	int u,v;
	rep(i,1,n){
		cin>>u>>v;
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(x,-1,0);
	dfs(1,-1,1);
	int ans=0;
	FOR(i,1,n){
		if(d[0][i]<d[1][i]){
			gmax(ans,d[1][i]);
		}
	}
	cout<<ans*2;
	RE 0;
}