#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
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
#define lc (x<<1)
#define rc ((x<<1)^1)
using namespace std;
V<int> v[300005];
int n,m,col[300005],dep[300005];
priority_queue<P<int,int> > q[300005];
int fa[300005];
int tap[300005];
void dfs(int x,int y){
	fa[x]=y;
	if(col[x])q[col[x]].emplace(MP(dep[x],x));
	for(auto u:v[x])if(u!=y){
		dep[u]=dep[x]+1;
		dfs(u,x);
	}
}
P<int,int> edge[300005];
void Add(int x,int y){
	if(col[x])x=tap[col[x]];
	if(col[y])y=tap[col[y]];
	v[x].PB(y);
	v[y].PB(x);
}
int dp[300005][2],mod=998244353;
void dfs2(int x,int y){
	if(col[x]){
		dp[x][0]=1;
		for(auto u:v[x])if(u!=y){
			dfs2(u,x);
			dp[x][0]=1ll*dp[x][0]*dp[u][1]%mod;
		}
		dp[x][1]=dp[x][0];
	}else{
		int t=1;
		for(auto u:v[x])if(u!=y){
			dfs2(u,x);
			t=1ll*t*dp[u][1]%mod;
		}
		int t1=1,t2=0;
		for(auto u:v[x])if(u!=y){
			t2=(1ll*t2*dp[u][1]+1ll*t1*dp[u][0])%mod;
			t1=1ll*t1*dp[u][1]%mod;
		}
		dp[x][0]=t2;
		dp[x][1]=(t2+t)%mod;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)cin>>col[i];
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;edge[i]=MP(x,y);
		v[x].PB(y);
		v[y].PB(x);
	}
	dep[1]=1;
	dfs(1,-1);
	FOR(i,1,m){
		while(q[i].size()>1){
			P<int,int> x=q[i].top();q[i].pop();
			if(col[fa[x.S]]){
				if(col[fa[x.S]]!=col[x.S]){
					cout<<0;RE 0;
				}
			}else{
				col[fa[x.S]]=col[x.S];
				q[i].emplace(MP(x.F-1,fa[x.S]));
			}
		}
	}
	FOR(i,1,n)if(col[i]&&!tap[col[i]])tap[col[i]]=i;
	FOR(i,1,n)v[i].clear();
	FOR(i,2,n){
		if(!col[edge[i].F]||col[edge[i].F]!=col[edge[i].S]){
			Add(edge[i].F,edge[i].S);
		}
	}
	dfs2(1,-1);
	cout<<dp[1][0];
	RE 0;
}