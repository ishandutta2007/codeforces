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
int cost[200005],n; 
V<int> v[200005];
int dfs(int p,int fa,int h){
	int re=0;
	for(auto u:v[p])if(u!=fa){
		re+=dfs(u,p,h+1);
	}
	cost[p]=h-re;
	re++;
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x,y,k;
	cin>>n>>k;
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1,-1,0);
	sort(cost+1,cost+n+1,greater<int>());
	int ans=0;
	FOR(i,1,k)ans+=cost[i];
	cout<<ans<<'\n';
	RE 0;
}