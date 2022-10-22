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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,h[200005];
V<int> v[200005];
int maxi[200005];
int cost[200005];
void dfs(int x,int y){
	maxi[x]=0;
	int m1=0,m2=0;
	for(auto u:v[x])if(u!=y){
		dfs(u,x);
		cost[x]+=cost[u];
		gmax(maxi[x],maxi[u]);
		if(maxi[u]>m1){
			m2=m1;
			m1=maxi[u];
		}else if(maxi[u]>m2){
			m2=maxi[u];
		}
	}
	cost[x]+=max(0ll,h[x]-maxi[x]);
	if(y==-1){
		cost[x]+=h[x]-m2;
	}
	gmax(maxi[x],h[x]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int rt=0; 
	FOR(i,1,n)cin>>h[i];
	FOR(i,1,n)if(h[rt]<h[i])rt=i;
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(rt,-1);
	cout<<cost[rt];
	RE 0;
}