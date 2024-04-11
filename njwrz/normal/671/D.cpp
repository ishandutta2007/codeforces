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
multiset<P<int,int> > dp[300005];
int n;
V<int> g[300005];
V<P<int,int> > v[300005];
int add[300005],f[300005],dep[300005];
void update(multiset<P<int,int> > &s,P<int,int> t){
	auto it=s.lwb(t);
	if(it!=s.begin()){
		--it;
		if((*it).S<=t.S)RE;
		++it;
	}
	V<P<int,int> > v;
	while(it!=s.end()&&(*it).S>=t.S)v.PB(*it),++it;
	for(auto u:v)s.erase(u);
	s.emplace(t);
}
void dfs(int x,int y){
	int t=0,mx=-1;
	for(auto u:g[x])if(u!=y){
		dfs(u,x);
		if((int)dp[u].size()>mx){
			mx=dp[u].size();t=u;
		}
	}
	if(x==1)RE;
	if(!t){
		for(auto u:v[x])update(dp[x],u);
	}else{
		swap(dp[x],dp[t]);
		int sum=0;
		for(auto u:g[x])if(u!=y)sum+=f[u];
		add[x]=add[t]+sum-f[t];
		for(auto u:g[x])if(u!=y&&u!=t){
			for(auto tu:dp[u]){
				tu.S+=add[u];tu.S-=add[x];tu.S+=sum-f[u];
				update(dp[x],tu);
			}
		}
		for(auto u:v[x]){
			u.S+=sum;u.S-=add[x];
			update(dp[x],u);
		}
	}
	if(dp[x].empty()){
		cout<<-1;exit(0);
	}
	f[x]=(*dp[x].rbegin()).S+add[x];
	while(!dp[x].empty()&&(*dp[x].rbegin()).F>=dep[x]-1)dp[x].erase(*dp[x].rbegin());
}
void get(int x,int y){
	for(auto u:g[x])if(u!=y){
		dep[u]=dep[x]+1;
		get(u,x);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		g[x].PB(y);
		g[y].PB(x);
	}
	get(1,-1);
	FOR(i,1,m){
		int x,y,z;cin>>x>>y>>z;
		if(x==y)continue;
		v[x].PB(MP(dep[y],z));
	}
	dfs(1,-1);
	int ans=0;
	for(auto u:g[1])ans+=f[u];
	cout<<ans;
	RE 0;
}