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

const int MAXN = 1e5 + 5;
int n;
std::vector<int> G[MAXN];

int f[MAXN],act[MAXN];

int dep[MAXN];

inline void dfs0(int v,int fa=0){
	dep[v] = dep[fa]+1;
	for(auto x:G[v]){
		if(x == fa) continue;
		dfs0(x,v);
	}
}

inline void dfs1(int v,int fa=0){
	std::vector<P<int,int> > lst;
	for(auto x:G[v]){
		if(x == fa) continue;
		dfs1(x,v);
		lst.pb(f[x],x);
	}
	std::sort(all(lst));std::reverse(all(lst));
	if(lst.empty()){
		f[v] = 1;act[v] = v;
		return;
	}
	FOR(i,0,SZ(lst)-1) f[v] = std::max(f[v],lst[i].fi+i);
	act[v] = act[lst[0].se];
}

int g[MAXN],pre[MAXN],suf[MAXN];

inline void dfs2(int v,int fa=0){
	std::vector<P<int,int> > lst;
	if(fa) lst.pb(g[v],fa);
	for(auto x:G[v]){
		if(x == fa) continue;
		lst.pb(f[x],x);
	}
	if(lst.empty()) return;
	std::sort(all(lst));std::reverse(all(lst));
	pre[0] = lst[0].fi;
	FOR(i,1,SZ(lst)-1) pre[i] = std::max(pre[i-1],lst[i].fi+i);
	suf[SZ(lst)-1] = lst.back().fi+SZ(lst)-2;
	ROF(i,SZ(lst)-2,0) suf[i] = std::max(suf[i+1],lst[i].fi+i-1);
	FOR(i,0,SZ(lst)-1){
		if(lst[i].se == fa) continue;
		g[lst[i].se] = std::max(i==0?0:pre[i-1],i==SZ(lst)-1?0:suf[i+1]);
		if(!g[lst[i].se]) g[lst[i].se] = 1;
	}

	for(auto x:G[v]){
		if(x == fa) continue;
		dfs2(x,v);
	}
}

inline int query(int v){
	printf("? %d\n",v);
	std::fflush(stdout);
	int ans;scanf("%d",&ans);return ans;
}

inline int dfs3(int v,int now){
	std::vector<P<int,int> > lst;
	for(auto x:G[v]){
		if(dep[x] < dep[v]) continue;
		lst.pb(f[x],x);
	}
	std::sort(all(lst));std::reverse(all(lst));
	FOR(i,0,SZ(lst)-1){
		int res;
		if(i == 0) res = now;
		else res = query(act[lst[i].se]);
		if(res == v) continue;
		return dfs3(lst[i].se,res);
	}
	return v;
}

std::vector<int> res;

int main(){
	scanf("%d",&n);
	FOR(i,2,n){
		int u,v;scanf("%d%d",&u,&v);
		G[u].pb(v);G[v].pb(u);
	}
	dfs0(1);dfs1(1);dfs2(1);
	int ans = 0;
	FOR(v,1,n){
		std::vector<int> lst;
		for(auto x:G[v]) if(dep[x] == dep[v] + 1) lst.pb(f[x]);
		if(v != 1) lst.pb(g[v]);
		std::sort(all(lst));std::reverse(all(lst));
		if(lst.empty()) continue;
//		for(auto x:lst) printf("%d ",x);puts("");
		FOR(i,1,SZ(lst)-1) ans = std::max(ans,lst[0]+lst[i]+i-1);
		ans = std::max(ans,lst[0]);
	}
	printf("%d\n",ans);std::fflush(stdout);
	int v;scanf("%d",&v);
	dfs0(v);dfs1(v);
	std::vector<P<int,int> > lst;
	for(auto x:G[v]) lst.pb(f[x],x);
	std::sort(all(lst));std::reverse(all(lst));
	FOR(i,0,SZ(lst)-1){
		if(SZ(res) == 2) break;
		int t = query(act[lst[i].se]);
		if(t == v) continue;
		res.pb(dfs3(lst[i].se,t));
	}
	while(SZ(res) < 2) res.pb(v);
	printf("! %d %d\n",res[0],res[1]);std::fflush(stdout);
	return 0;
}