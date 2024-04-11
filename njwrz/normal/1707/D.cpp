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
int C[2005][2005],n,mod;
int dp[2005][2005],siz[2005],sum[2005][2005];
V<int> v[2005];
int node[2005];
int val[2005][2005];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
void dfs(int x,int y){
	siz[x]=1;
	for(auto u:v[x])if(u!=y){
		dfs(u,x);
		FOR(i,1,n)sum[u][i]=(sum[u][i-1]+dp[u][i])%mod;
		siz[x]+=siz[y];
	}
	FOR(i,1,n){
		int mul=1;
		for(auto u:v[x])if(u!=y)val[u][i]=mul,mul=sum[u][i]*mul%mod;
	}
	reverse(ALL(v[x]));
	FOR(i,1,n){
		int mul=1;
		for(auto u:v[x])if(u!=y)val[u][i]=mul*val[u][i]%mod,mul=sum[u][i]*mul%mod;
	}
	if(x!=1)for(auto u:v[x])if(u!=y){
		int s=0;
		FOR(i,1,n){
			add(dp[x][i],dp[u][i]*s%mod);
			add(s,val[u][i]);
		}
	}
	FOR(i,1,n){
		int val=1;
		for(auto u:v[x])if(u!=y)val=val*sum[u][i]%mod;
		add(dp[x][i],val);
	}
}
int ans[2005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>mod;
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;v[x].PB(y);v[y].PB(x);
	}
	FOR(i,0,n){
		C[i][0]=1;
		FOR(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	dfs(1,-1);
	rep(i,1,n)ans[i]=dp[1][i];
	for(int i=n-1;i>=1;i--){
		rep(j,1,i)if((i-j)&1)add(ans[i],mod-C[i][j]*ans[j]%mod);else add(ans[i],C[i][j]*ans[j]%mod);
	}
	rep(i,1,n)cout<<ans[i]<<' ';
	RE 0;
}