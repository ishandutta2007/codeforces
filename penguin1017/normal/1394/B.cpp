#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define mp make_pair
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=2e5+9;
const ll mod=998244353;
const ll Inf=1e18;
map<pair<int,ll>,int> id;
int dp[N];
bool ok[N][12];
int vis[N],cnt,k;
ll seed[N];
vector<pii> g[N];
vi deg[10][10];
ll dfs(int n,ll val){
	if(n==k+1)return 1;
	if(id.count(mp(n,val)))return dp[id[mp(n,val)]];
	id[mp(n,val)]=++cnt;
	ll ans=0;
	rep(i,1,n+1){
		int op=0;
		for(auto v:deg[n][i]){
			if(++vis[v]==2)op=1;
			//if(n==3)cout<<v<<' '<<op<<"??\n";
			val^=seed[v];
		}
		if(!op)ans+=dfs(n+1,val);
		for(auto v:deg[n][i]){
			--vis[v];
			val^=seed[v];
		}
	}
	//cout<<n<<' '<<ans<<"ans\n";
	return dp[id[mp(n,val)]]=ans;
}
int main(){
	int n,m;
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n+1){
		ll x=rand(),y=rand(),z=rand();
		seed[i]=((x<<40)+(y<<20)+z);
	}
	rep(i,0,m){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].pb({w,v});
	}
	rep(i,1,n+1){
		sort(all(g[i]));
		int s=g[i].size();
		rep(j,0,s){
			deg[s][j+1].pb(g[i][j].se);
		}
	}
	cout<<dfs(1,0);
}