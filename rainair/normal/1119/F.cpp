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
int n;

std::vector<P> G[MAXN];
int deg[MAXN];
int now;

inline bool cmp(P x,P y){
	return deg[x.fi] > deg[y.fi];
}

std::multiset<LL> big[MAXN],small[MAXN];
LL sm[MAXN];int lim[MAXN];

inline void update(int o){
	while(!big[o].empty() && small[o].size() < lim[o]){
		small[o].insert(*big[o].begin());
		sm[o] += *big[o].begin();
		big[o].erase(big[o].begin());
	}
	while(small[o].size() > lim[o]){
		sm[o] -= *small[o].rbegin();
		big[o].insert(*small[o].rbegin());
		small[o].erase((--small[o].end()));
	}
}

inline void insert(int o,LL x){
	if(big[o].empty()) return (void)(small[o].insert(x),sm[o] += x);
	if(small[o].empty()) return (void)big[o].insert(x);
	if(x <= *small[o].rbegin()) return (void)(small[o].insert(x),sm[o] += x);
	return (void)big[o].insert(x);
}

inline void erase(int o,LL x){
	auto p = big[o].find(x);
	if(p != big[o].end()) return (void)big[o].erase(p);
	return (void)(small[o].erase(small[o].find(x)),sm[o] -= x);
}

inline void gao(int v){
	for(auto x:G[v]){
		if(deg[x.fi] <= now) break;
		insert(x.fi,x.se);
	}
}

bool vis[MAXN];
LL f[MAXN][2];

inline void dfs(int v,int fa=0){
	f[v][0] = f[v][1] = 0;
	std::vector<LL> del;vis[v] = 1;
	lim[v] = deg[v]-now;
	for(auto x:G[v]){
		if(x.fi == fa) continue;
		if(deg[x.fi] <= now) break;
		dfs(x.fi,v);
		f[v][0] += f[x.fi][0];
		f[v][1] += f[x.fi][0];
		LL gx = -f[x.fi][0]+x.se+f[x.fi][1];
		if(gx <= 0) --lim[v],f[v][0] += gx,f[v][1] += gx;
		else insert(v,gx),del.pb(gx);
	}
	lim[v] = std::max(lim[v],0);update(v);
	f[v][0] += sm[v];
	--lim[v];lim[v] = std::max(lim[v],0);update(v);
	f[v][1] += sm[v];
	// FOR(i,1,lim) f[v][0] += *p,++p;
	// p = S[v].begin();
	// FOR(i,1,lim-1) f[v][1] += *p,++p;
	for(auto x:del) erase(v,x);
	del.clear();
}

P node[MAXN];

int main(){
	scanf("%d",&n);
	LL sm = 0;
	FOR(i,2,n){
		int u,v,w;
		// u = i;v = 1+g()%(i-1);w = 1+g()%1000000;
		scanf("%d%d%d",&u,&v,&w);
		G[u].pb(MP(v,w));G[v].pb(MP(u,w));sm += w;
		++deg[u];++deg[v];
	}
	FOR(i,1,n) std::sort(all(G[i]),cmp),node[i] = MP(deg[i],i);
	std::sort(node+1,node+n+1);int ps = 1;
	printf("%lld",sm);
	for(now = 1;now <= n-1;++now){
		while(ps <= n && node[ps].fi <= now) gao(node[ps].se),++ps;
		LL ans = 0;
		FOR(i,ps,n) vis[node[i].se] = 0;
		FOR(i,ps,n){
			int x = node[i].se;
			if(vis[x]) continue;
			dfs(x);
			ans += f[x][0];
		}
		printf(" %lld",ans);
	}
	puts("");
	return 0;
}