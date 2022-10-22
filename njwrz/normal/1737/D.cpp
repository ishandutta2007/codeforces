#include<bits/stdc++.h>
#define ll long long
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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int dis[505][505];
int INF=2e9;
P<int,int> p[250005];
int c[250005];
void solve(){
	int n,m;
	cin>>n>>m;
	FOR(i,1,n)FOR(j,1,n){
		if(i==j)dis[i][j]=0;else dis[i][j]=1e9;
	}
	FOR(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		p[i]=MP(x,y);
		c[i]=z;
		dis[x][y]=dis[y][x]=1;
	}
	FOR(k,1,n)FOR(i,1,n){
		FOR(j,1,n)gmin(dis[i][j],dis[i][k]+dis[k][j]);
	}
	ll ans=1e18;
//	FOR(i,1,n)FOR(j,1,n)cout<<dis[i][j]<<'\n';
	FOR(i,1,m){
		FOR(j,1,n){
			gmin(ans,1ll*(dis[p[i].F][j]+dis[j][1]+dis[j][n]+2)*c[i]);
			gmin(ans,1ll*(dis[p[i].S][j]+dis[j][1]+dis[j][n]+2)*c[i]);
		}
		gmin(ans,1ll*(dis[1][p[i].F]+dis[p[i].S][n]+1)*c[i]);
		gmin(ans,1ll*(dis[n][p[i].F]+dis[p[i].S][1]+1)*c[i]);
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}