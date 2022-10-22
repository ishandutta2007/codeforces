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
int k,dis[185][185];
int n,a[185];
int dp[185][185];
int mini[185],lst[185],co[185][185],fa[185];
bool vis[185];
V<int> v[185];
void dfs(int p,int start){
	for(auto u:v[p])if(!vis[u]){
		vis[u]=1;dis[start][u]=dis[start][p]+1;
		dfs(u,start);
	}
}
void get(int x){
	for(auto u:v[x])if(u!=fa[x]){
		fa[u]=x;
		get(u); 
	}
	mini[x]=1e9;
	FOR(to,1,n){
		dp[x][to]=a[dis[to][x]]+k;
		for(auto u:v[x])if(u!=fa[x]){
			if(mini[u]<dp[u][to]-k){
				co[to][u]=lst[u];
				dp[x][to]+=mini[u];
			}else{
				co[to][u]=to;
				dp[x][to]+=dp[u][to]-k;
			}
		}
		if(mini[x]>dp[x][to]){
			mini[x]=dp[x][to];
			lst[x]=to;
		}
	}
}
int pr[185];
void getpr(int x,int now){
	pr[x]=now;
	for(auto u:v[x])if(u!=fa[x]){
		getpr(u,co[now][u]);
	} 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	rep(i,1,n)cin>>a[i];
	int x,y;
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	FOR(i,1,n){
		FILL(vis,0);
		vis[i]=1;
		dfs(i,i);
	}
	get(1);
	int ans=1;
//	cout<<dp[1][1]<<'\n';
	FOR(i,2,n){
		if(dp[1][i]<dp[1][ans])ans=i;
//		cout<<dp[1][i]<<'\n';
	}
	cout<<dp[1][ans]<<'\n';
	getpr(1,ans);
	FOR(i,1,n)cout<<pr[i]<<' ';
	RE 0;
}