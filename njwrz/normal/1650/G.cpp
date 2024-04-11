#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
#define int long long
#define lb long double
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
V<int> v[200005];
int n,m;
int dis[200005];
int dp[200005][2];
int mod=1e9+7;
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
bool vis[200005];
void getdis(int x){
	FOR(i,1,n)dis[i]=-1,dp[i][0]=dp[i][1]=0;
	queue<int> q;
	dis[x]=0;
	q.emplace(x);
	dp[x][0]=1;
	while(!q.empty()){
		int now=q.front();q.pop();
		for(auto u:v[now]){
			if(dis[u]==-1){
				dis[u]=dis[now]+1;
				dp[u][0]=dp[now][0];
				q.emplace(u);
			}else if(dis[u]==dis[now]+1){
				add(dp[u][0],dp[now][0]);
			}
		}
	}
	q.emplace(x);vis[x]=1;
	FOR(i,1,n)for(auto u:v[i])if(dis[i]==dis[u])add(dp[u][1],dp[i][0]);
	while(!q.empty()){
		int now=q.front();q.pop();
		for(auto u:v[now]){
			if(!vis[u]){
				dis[u]=dis[now]+1;
				add(dp[u][1],dp[now][1]);
				q.emplace(u);
				vis[u]=1;
			}else if(dis[u]==dis[now]+1){
				add(dp[u][1],dp[now][1]);
			}
		}
	}
}
void solve(){
	cin>>n>>m;
	FOR(i,1,n)v[i].clear(),vis[i]=0;
	int s,t;
	cin>>s>>t;
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	getdis(s);
	add(dp[t][0],dp[t][1]);
	cout<<dp[t][0]<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}