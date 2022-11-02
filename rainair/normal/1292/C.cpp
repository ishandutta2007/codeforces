#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 3000+5;

struct Edge{
	int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
	e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
	e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int sz[MAXN][MAXN],fa[MAXN][MAXN];
int rt;

inline void dfs(int v){
	sz[rt][v] = 1;
	for(int i = head[v];i;i = e[i].nxt){
		if(e[i].to == fa[rt][v]) continue;
		fa[rt][e[i].to] = v;dfs(e[i].to);
		sz[rt][v] += sz[rt][e[i].to];
	}
}
int f[MAXN][MAXN];
inline int dp(int x,int y){
	if(x == y) return 0;
	if(f[x][y] != -1) return f[x][y];
	return f[x][y] = std::max(dp(fa[y][x],y),dp(x,fa[x][y]))+sz[y][x]*sz[x][y];
}
int n;
signed main(){
	scanf("%lld",&n);
	FOR(i,2,n){
		int u,v;scanf("%lld%lld",&u,&v);add(u,v);
	}
	FOR(i,1,n){
		rt = i;dfs(rt);
	}
	CLR(f,-1);
	FOR(v,1,n){
		for(int i = head[v];i;i = e[i].nxt){
			f[e[i].to][v] = f[v][e[i].to] = sz[e[i].to][v]*sz[v][e[i].to];
		}
	}
	int ans = 0;
	FOR(i,1,n){
		FOR(j,1,i){
			ans = std::max(ans,dp(i,j));
		}
	}
	printf("%lld\n",ans);
	return 0;
}