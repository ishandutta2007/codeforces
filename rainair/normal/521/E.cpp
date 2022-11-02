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

const int MAXN = 2e5 + 5;

int n,m;
struct Edge{
	int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
	e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
	e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

bool vis[MAXN],vv[MAXN];
int dep[MAXN],cf[MAXN],dfn[MAXN],ts,sz[MAXN],fa[MAXN];
std::vector<P> edge;

inline void dfs1(int v,int fa=0){
	dep[v] = dep[fa]+1;vis[v] = 1;dfn[v] = ++ts;sz[v] = 1;::fa[v] = fa;
	// printf("%d %d\n",fa,v);
	for(int i = head[v];i;i = e[i].nxt){
		if(e[i].to == fa) continue;
		if(!vis[e[i].to]) dfs1(e[i].to,v),sz[v] += sz[e[i].to];
		else{
			if(dep[e[i].to] > dep[v]){
				cf[e[i].to]++;cf[v]--;
				edge.pb(MP(v,e[i].to));
			}
		}
	}
}

bool flag = 0;
int ps = -1;

inline void dfs2(int v,int fa=0){
	vv[v] = 1;
	for(int i = head[v];i;i = e[i].nxt){
		if(e[i].to == fa) continue;
		if(!vv[e[i].to]) dfs2(e[i].to,v),cf[v] += cf[e[i].to];
	}
	if(cf[v] >= 2) ps = v;
}

int u1=-1,u2=-1,v1=-1,v2=-1;

inline bool in(int x,int y){
	return dfn[y] >= dfn[x] && dfn[y] <= dfn[x]+sz[x]-1;
}

inline void dfs3(int v,int fa=0){
	vis[v] = 1;
	for(int i = head[v];i;i = e[i].nxt){
		if(e[i].to == fa) continue;
		if(!vis[e[i].to]) dfs3(e[i].to,v),cf[v] += cf[e[i].to];
	}
}

inline std::vector<int> gao(int u,int v){
	bool flag = (dep[u] < dep[v]);
	if(dep[u] < dep[v]) std::swap(u,v);
	std::vector<int> res;
	while(u != v){
		res.pb(u);
		u = fa[u];
	}
	res.pb(v);
	if(flag) std::reverse(all(res));
	return res;
}

inline void print(std::vector<int> v){
	printf("%d ",(int)v.size());
	for(auto x:v) printf("%d ",x);puts("");
}

inline void work(int rt){
	ts = 0;dfs1(rt);ps = -1;dfs2(rt);if(ps == -1) return;
	for(auto x:edge){
		if(in(ps,x.se) && !in(ps,x.fi)){
			if(u1 == -1) std::tie(u1,v1) = x;
			else{
				std::tie(u2,v2) = x;break;
			}
		}
	}
	FOR(i,1,n) cf[i] = vis[i] = 0;
	cf[u1]--;cf[v1]++;cf[u2]--;cf[v2]++;
	dfs3(rt);
	int x = v1,y = v2;
	while(x != y){
		if(dep[x] < dep[y]) std::swap(x,y);
		x = fa[x];
	}
	assert(cf[x] == 2);
	int v = x;
	while(cf[fa[x]] == 2) x = fa[x];
	int u = fa[x];
	DEBUG(u);DEBUG(v);
	assert(u != v);
	std::vector<int> r1,r2,r3;
	r1 = gao(v,u);
	std::vector<int> t1 = gao(v,v1),t2 = gao(u1,u),t3 = gao(v,v2),t4 = gao(u2,u);
	r2.insert(r2.end(),all(t1));
	r2.insert(r2.end(),all(t2));
	r3.insert(r3.end(),all(t3));
	r3.insert(r3.end(),all(t4));
	puts("YES");
	print(r1);print(r2);print(r3);
	exit(0);
}

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,m){
		int u,v;scanf("%d%d",&u,&v);add(u,v);
	}
	FOR(i,1,n) if(!vis[i]) work(i);
	puts("NO");
	return 0;
}