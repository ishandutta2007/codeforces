#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 4e5 + 5;
int n,m;
std::vector<int> G[MAXN];
int dfn[MAXN],low[MAXN],st[MAXN],bel[MAXN],tp,ts,tot,sz[MAXN];
bool ins[MAXN];
std::vector<int> scc[MAXN];

inline void dfs(int v){
	dfn[v] = low[v] = ++ts;ins[v] = 1;st[++tp] = v;
	for(auto x:G[v]){
		if(!dfn[x]){
			dfs(x);
			low[v] = std::min(low[v],low[x]);
		}
		else if(ins[x]) low[v] = std::min(low[v],dfn[x]);
	}
	if(low[v] == dfn[v]){
		int t = -1;++tot;sz[tot] = 0;scc[tot].clear();
		do{
			t = st[tp--];
			ins[t] = 0;
			bel[t] = tot;
			++sz[tot];
			scc[tot].pb(t);
		}while(t != v);
	}
}

std::vector<int> T[MAXN];
bool vis[MAXN];
int f[MAXN],deg[MAXN];
bool lp[MAXN];

inline bool inf(int x){
	return sz[bel[x]] > 1 || lp[x];
}

inline void Solve(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) G[i].clear(),dfn[i] = 0,lp[i] = 0;ts = 0;tot = 0;
	FOR(i,1,m){
		int u,v;scanf("%d%d",&u,&v);
		if(u == v) lp[u] = 1;
		else G[u].pb(v);
	}
	FOR(i,1,n) if(!dfn[i]) dfs(i);
	FOR(i,1,tot) T[i].clear(),vis[i] = 0,f[i] = deg[i] = 0;
	FOR(i,1,n){
		for(auto x:G[i]){
			if(bel[i] != bel[x]) T[bel[i]].pb(bel[x]),++deg[bel[x]];
		}
	}
//	DEBUG(lp[5]);
	f[bel[1]] = inf(1)?-1:1;std::queue<int> q;
	FOR(i,1,tot) if(!deg[i]) q.push(i);
	while(!q.empty()){
		int v = q.front();q.pop();
		if(f[v] > 0 && inf(scc[v][0])) f[v] = -1;
		for(auto x:T[v]){
			if(f[v] == -1) f[x] = -1;
			else{
				if(f[x] != -1){
					f[x] += f[v];
					f[x] = std::min(f[x],2);
				}
			}
			if(!--deg[x]){
				q.push(x);
			}
		}
	}
	FOR(i,1,n) printf("%d%c",f[bel[i]]," \n"[i==n]);
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}