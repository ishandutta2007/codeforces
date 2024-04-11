#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define pf emplace_front
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5e5 + 5;

struct Edge{
	int u,v,w;
}edge[MAXN];

std::vector<P<int,int> > G[MAXN],tr[MAXN<<2];
int n;
std::vector<int> S;
LL ans;
int sz[MAXN],f[MAXN];

inline int find(int x){
	return x == f[x] ? x : find(f[x]);
}

std::vector<int> vec;

inline void merge(int x,int y){
	x = find(x);y = find(y);
	assert(x != y);// x -> y
	if(sz[x] > sz[y]) std::swap(x,y);
	f[x] = y;sz[y] += sz[x];
	vec.pb(x);
}

inline void undo(){
	int x = vec.back();vec.pop_back();
	int y = f[x];
	f[x] = x;sz[y] -= sz[x];
}

#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void build(int x,int l,int r){
	if(l == r){
		tr[x] = G[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lc,l,mid);build(rc,mid+1,r);
	for(auto v:tr[lc]) tr[x].pb(v);
	for(auto v:tr[rc]) tr[x].pb(v);
}

inline void work(int x,int l,int r){
	if(l == r){
		for(auto x:tr[x]) ans += 1ll*sz[find(x.fi)]*sz[find(x.se)];
		return;
	}
	int now = SZ(vec),mid = (l + r) >> 1;
	for(auto x:tr[rc]) merge(x.fi,x.se);
	work(lc,l,mid);
	while(now != SZ(vec)) undo();
	for(auto x:tr[lc]) merge(x.fi,x.se);
	work(rc,mid+1,r);
	while(now != SZ(vec)) undo();
}

int main(){
	scanf("%d",&n);FOR(i,1,n) f[i] = i,sz[i] = 1;
	FOR(i,1,n-1) scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w),S.pb(edge[i].w);
	std::sort(all(S));S.erase(std::unique(all(S)),S.end());
	FOR(i,1,n-1) G[std::lower_bound(all(S),edge[i].w)-S.begin()+1].pb(edge[i].u,edge[i].v);
	int m = SZ(S);
	build(1,1,m);
	work(1,1,m);
	printf("%lld\n",ans);
	return 0;
}