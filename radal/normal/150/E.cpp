#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("O3")
//#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e5+20,mod = 998244353,inf = 1e9+10;

vector<pll> adj[N];
vector<int> G[N],ve;
int sz[N],n,L,R,ro,h[N],s[N],mx,out1,out2;
pll seg[N*4];
bool hide[N];
int cent(int v,int _n){
	int p = -1;
	while (true){
		bool f = 0;
		for (pll u : adj[v]){
			if (!hide[u.X] && u.X != p && sz[u.X]*2 > _n){
				p = v;
				v = u.X;
				f = 1;
				break;
			}
		}
		if (!f) break;
	}
	return v;
}
void siz(int v,int p){
	sz[v] = 1;
	for (pll u : adj[v]){
		if (hide[u.X] || u.X == p) continue;
		siz(u.X,v);
		sz[v] += sz[u.X];
	}
}
void build_tree(int v,int p){
	siz(v,-1);
	v = cent(v,sz[v]);
	if (p != -1)
		G[p].pb(v);
	else
		ro = v;
	hide[v] = 1;
	for(pll u : adj[v]) if (!hide[u.X]) build_tree(u.X,v);
}
void dfs(int v,int m,int p){
	mx = max(mx,h[v]);
	for (pll u : adj[v]){
		if (hide[u.X] || p == u.X) continue;
		h[u.X] = h[v]+1;
		s[u.X] = s[v];
		if (u.Y >= m) s[u.X]++;
		dfs(u.X,m,v);
	}
	return;
}
void build(int r) {  // build the tree
	for (int i = 2*r; i > 0; --i) seg[i] = {-inf,0};
}

void modify(int p, int r,pll value) {  // set value at position p
	p += r;
	for (seg[p] = max(seg[p],value); p > 1; p >>= 1) seg[p>>1] = max(seg[p], seg[p^1]);
}

pll query(int l, int r,int x) {  // sum on interval [l, r)
	pll res = {-inf,0};
	for (l += x, r += x; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = max(res,seg[l++]);
		if (r&1) res = max(res,seg[--r]);
	}
	return res;
}
bool calc(int v){
	if (h[v] <= R && L-h[v] <= mx){
		pll p = query(max(0,L-h[v]),min(mx,R-h[v])+1,mx+1);
		if (p.X >= h[v]-2*s[v]){
			out1 = v;
			out2 = p.Y;
			return 1;
		}
	}
	for (int u : G[v])
		if (calc(u)) return 1;
	return 0;
}
void add(int v){
	modify(h[v],mx+1,{2*s[v]-h[v],v});
	for (int u : G[v]) add(u);
}
bool check(int x,int v = ro){
	s[v] = 0;
	h[v] = 0;
	mx = 0;
	dfs(v,x,-1);
	build(mx+1);
	modify(0,mx+1,{0,v});
	hide[v] = 1;
	for (int u : G[v]){
		if (calc(u))
			return 1;
		add(u);
	}
	for (int u : G[v]) if (check(x,u)) return 1;
	return 0;
}
inline void bs(){
	int l = -1,r = ve.size(),m;
	while (r-l > 1){
		m = (l+r) >> 1;
		memset(hide,0,sizeof hide);
		if (!check(ve[m])) r = m;
		else l = m;
	}
	return;
}
int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> L >> R;
	rep(i,1,n){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
        ve.pb(w);
	}
    sort(ve.begin(),ve.end());
    ve.resize(unique(ve.begin(),ve.end())-ve.begin());
	build_tree(1,-1);
	bs();
	cout << out1 << ' ' << out2 << endl;
	return 0;
}