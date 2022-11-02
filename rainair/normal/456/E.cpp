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

const int MAXN = 3e5 + 5;
int n,m,q;

std::vector<int> G[MAXN];
int f[MAXN],mx[MAXN];

inline int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}

inline void merge(int x,int y){
	x = find(x);y = find(y);
	if(x == y) return;
	f[y] = x;
}

int g[MAXN][2];
bool vis[MAXN];
int ans = 0;

inline void dfs(int v,int fa=0){
	vis[v] = 1;
	for(auto x:G[v]){
		if(x == fa) continue;
		dfs(x,v);merge(x,v);
		if(g[x][0]+1 > g[v][0]){
			g[v][1] = g[v][0];g[v][0] = g[x][0]+1;
		}
		else if(g[x][0]+1 > g[v][1]){
			g[v][1] = g[x][0]+1;
		}
	}
	ans = std::max(ans,g[v][0]+g[v][1]);
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	FOR(i,1,n) f[i] = i;
	FOR(i,1,m){
		int u,v;scanf("%d%d",&u,&v);
		G[u].pb(v);G[v].pb(u);
	}
	FOR(i,1,n) if(!vis[i]) ans=0,dfs(i),mx[find(i)] = ans;
	FOR(i,1,q){
		int opt,x,y;scanf("%d",&opt);
		if(opt == 1){
			scanf("%d",&x);
			printf("%d\n",mx[find(x)]);
		}
		if(opt == 2){
			scanf("%d%d",&x,&y);
			x = find(x);y = find(y);
			if(x == y) continue;
			mx[x] = std::max({mx[x],mx[y],(mx[x]+1)/2+(mx[y]+1)/2 + 1});
			merge(x,y);
		}
	}
	return 0;
}