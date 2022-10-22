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
const int mod=1e9+7;
int fi[300005];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int n,k;
int siz[100005];
V<int> g[100005];
int dp[100005][205],val[205];
int S[205][205];
int f[205];
void dfs(int x,int y){
	siz[x]=1;dp[x][0]=2;
	for(auto u:g[x])if(u!=y){
		dfs(u,x);
		FILL(f,0);
		rep(i,0,min(siz[x],k+1))rep(j,0,min(siz[u],k+1))if(i+j<=k){
			add(f[i+j+1],dp[x][i]*dp[u][j]%mod);
			add(f[i+j],dp[x][i]*dp[u][j]%mod);
		}
		siz[x]+=siz[u];
		rep(i,0,min(siz[x],k+1))add(dp[x][i],f[i]);
	}
	for(auto u:g[x])if(u!=y){
		rep(i,0,min(k+1,siz[u])){
			add(val[i+1],mod-dp[u][i]);
			add(val[i],mod-dp[u][i]);
		}
	}
	add(dp[x][0],mod-1);
	FOR(i,1,min(k,siz[x]))add(val[i],dp[x][i]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		g[x].PB(y);
		g[y].PB(x);
	}
	fi[0]=fi[1]=1;
	FOR(i,2,n){
		fi[i]=fi[i-1]*i%mod;
	}
	S[0][0]=1;
	FOR(i,0,k)FOR(j,0,i){
		add(S[i+1][j],S[i][j]*j%mod);
		add(S[i+1][j+1],S[i][j]);
	}
	dfs(1,-1);
	int ans=0;
	FOR(i,1,k){
		add(ans,S[k][i]*fi[i]%mod*val[i]%mod);
	}
	cout<<ans;
	RE 0;
}