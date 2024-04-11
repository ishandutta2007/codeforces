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
int n,q;

std::vector<P<int,int> > edge[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void modify(int x,int l,int r,int L,int R,P<int,int> d){
	if(l == L && r == R){edge[x].pb(d);return;}
	int mid = (l + r) >> 1;
	if(R <= mid) modify(lc,l,mid,L,R,d);
	else if(L > mid) modify(rc,mid+1,r,L,R,d);
	else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
}

bool ans[MAXN];
bool flag;
int f[MAXN],sz[MAXN],c[MAXN];

inline int find(int x){
	return x == f[x] ? x : find(f[x]);
}

inline int dis(int x){
	if(f[x] == x) return 0;
	return c[x]^dis(f[x]);
}

struct Node{
	int x,y,w;
	Node(int x=0,int y=0,int w=0) : x(x),y(y),w(w) {};
};
std::vector<Node> opt;

inline void undo(){
	Node v = opt.back();opt.pop_back();
	c[v.x] = 0;f[v.x] = v.x;sz[v.y] -= sz[v.x];
}

inline void dfs(int x,int l,int r){
	int tp = SZ(opt);bool tmp = flag;
	for(auto e:edge[x]){
		int x = e.fi,y = e.se,fx = find(x),fy = find(y);
		if(sz[fx] > sz[fy]) std::swap(x,y),std::swap(fx,fy);
		// x -> y
		if(fx == fy){
			int u = dis(x),v = dis(y);
			flag &= (u^v);
			continue;
		}
		int o = dis(x)^dis(y)^1;
		f[fx] = fy;sz[fy] += fx;c[fx] = o;
		opt.pb(fx,fy,o);
	}
	if(l == r){
		ans[l] = flag;
		flag = tmp;
		while(SZ(opt) != tp) undo();
		return;
	}
	int mid = (l + r) >> 1;
	dfs(lc,l,mid);dfs(rc,mid+1,r);

	flag = tmp;
	while(SZ(opt) != tp) undo();
}

int main(){
	scanf("%d%d",&n,&q);
	std::map<P<int,int>,int> mp;
	FOR(i,1,q){
		int u,v;scanf("%d%d",&u,&v);
		if(mp.count(MP(u,v))){
			modify(1,1,q,mp[MP(u,v)],i-1,MP(u,v));
			mp.erase(MP(u,v));
		}
		else mp[MP(u,v)] = i;
	}
	for(auto x:mp) modify(1,1,q,x.se,q,x.fi);
	FOR(i,1,n) f[i] = i,sz[i] = 1;
	flag = 1;dfs(1,1,q);
	FOR(i,1,q) puts(ans[i]?"YES":"NO");
	return 0;
}