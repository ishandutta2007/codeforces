#include <bits/stdc++.h>

#define fi first
#define se second
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 +5;
int n,a,b,da,db;
std::vector<int> G[MAXN];

int dep[MAXN];

inline void dfs(int v,int fa=0){
	dep[v] = dep[fa]+1;
	for(auto x:G[v]) if(x != fa) dfs(x,v);
}

inline void Solve(){
	scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
	FOR(i,1,n) G[i].clear();
	FOR(i,2,n){
		int u,v;scanf("%d%d",&u,&v);
		G[u].pb(v);G[v].pb(u);
	}
	if(db <= 2*da){
		puts("Alice");
		return;
	}
	dep[0] = -1;
	dfs(a);
	if(dep[b] <= da){
		puts("Alice");
		return;
	}
	int mx = 0,ps = -1;
	FOR(i,1,n){
		if(dep[i] > mx){
			mx = dep[i];ps = i;
		}
	}
	dfs(ps);
	mx = 0;FOR(i,1,n) mx = std::max(mx,dep[i]);
	if(mx <= 2*da){
		puts("Alice");
		return;
	}
	puts("Bob");
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}