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

struct Edge{
	int to,w,nxt;
}e[MAXN<<1];
int head[MAXN],cnt=1;

inline void add(int u,int v,int w){
	e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
	e[++cnt] = (Edge){u,w,head[v]};head[v] = cnt;
}

int dfn[MAXN],low[MAXN],stk[MAXN],bel[MAXN],tp;
bool vis[MAXN];
int N;
bool sp[MAXN],is[MAXN];
LL a[MAXN];int val[MAXN];
std::vector<P> G[MAXN];

inline void dfs(int v,int fe=0){
	static int ts=0;stk[++tp] = v;dfn[v] = low[v] = ++ts;vis[v] = 1;
	for(int i = head[v];i;i = e[i].nxt){
		if((i>>1) == (fe>>1)) continue;
		if(!vis[e[i].to]) dfs(e[i].to,i),low[v] = std::min(low[v],low[e[i].to]);
		else low[v] = std::min(low[v],dfn[e[i].to]);
	}
	if(low[v] == dfn[v]){ // fe is a cut
		int r = -1;++N;
		do{
			r = stk[tp--];
			sp[N] |= is[r];
			a[N] += val[r];
			bel[r] = N;
		}while(r != v);
	}
}

int n,m,k;

int csp[MAXN];
int fa[MAXN];

inline int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

inline void dfs1(int v,int fa=0){
	csp[v] = sp[v];
	for(auto x:G[v]){
		if(x.fi == fa) continue;
		dfs1(x.fi,v);csp[v] += csp[x.fi];
		if(!csp[x.fi]){
			a[v] += a[x.fi];
			::fa[x.fi] = v;
		}
	}
}

int rt;

inline void build(){
	FOR(i,1,n) if(!vis[i]) dfs(i);
	FOR(v,1,n){
		for(int i = head[v];i;i = e[i].nxt){
			if(bel[e[i].to] != bel[v]) G[bel[v]].pb(MP(bel[e[i].to],e[i].w));
		}
	}
	rt = 1;while(!sp[rt]) ++rt;
	FOR(i,1,n) fa[i] = i;
	dfs1(rt);
}

int _[MAXN];
LL f[MAXN],ans[MAXN];

inline void dp(int v,int fa=0){
	for(auto x:G[v]){
		if(x.fi == fa) continue;
		if(!csp[x.fi]) continue;
		dp(x.fi,v);
		f[v] += std::max(0ll,f[x.fi]+a[x.fi]-x.se);
	}
}

inline void dfs2(int v,int fa=0){
	if(!csp[v]) return;
	ans[v] = f[v]+a[v];
	for(auto x:G[v]){
		if(x.fi == fa) continue;
		LL t1 = f[v],t2 = f[x.fi];
		f[v] -= std::max(0ll,t2+a[x.fi]-x.se);
		f[x.fi] += std::max(0ll,f[v]+a[v]-x.se);
		dfs2(x.fi,v);
		f[v] = t1;f[x.fi] = t2;
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,1,k){
		int x;scanf("%d",&x);is[x] = 1;
	}
	FOR(i,1,n) scanf("%d",val+i);
	FOR(i,1,m) scanf("%d",_+i);
	FOR(i,1,m){
		int u,v;scanf("%d%d",&u,&v);
		add(u,v,_[i]);
	}
	build();
	dp(rt); //  
	dfs2(rt);
	FOR(i,1,n) printf("%lld%c",ans[find(bel[i])]," \n"[i==n]);
	return 0;
}