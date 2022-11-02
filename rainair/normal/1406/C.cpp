#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
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

const int MAXN = 1e5 + 5;
int n;

int sz[MAXN],mx[MAXN];
std::vector<int> G[MAXN];

inline void dfs(int v,int fa=0){
	mx[v] = 0;sz[v] = 1;
	for(auto x:G[v]){
		if(x == fa) continue;
		dfs(x,v);sz[v] += sz[x];mx[v] = std::max(mx[v],sz[x]);
	}
	mx[v] = std::max(mx[v],n-sz[v]);
}

inline void Solve(){
	scanf("%d",&n);FOR(i,1,n) G[i].clear();
	FOR(i,2,n){
		int u,v;scanf("%d%d",&u,&v);G[u].pb(v);G[v].pb(u);
	}
	dfs(1);
	std::vector<int> ve;
	FOR(i,1,n){
		if(mx[i] <= n/2) ve.pb(i);
	}
	if(ve.size() == 1){
		printf("%d %d\n%d %d\n",1,G[1][0],1,G[1][0]);
	}
	else{
		int u = ve[0],v = ve[1];
		int p = -1;
		for(auto x:G[u]){
			if(x == v) continue;
			p = x;break;
		}
		printf("%d %d\n%d %d\n",u,p,v,p);
	}
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}