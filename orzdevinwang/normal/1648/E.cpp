#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1 << 19;
int n, m;

struct edge {
	int u, v, w, id;
} e[N];

int f[N];
int find(int x) { 
	return f[x] == x ? x : f[x] = find(f[x]);
}
int Fa[N], w[N], siz[N], tot;
int up[20][N], ch[N][2], dep[N];
int lca (int x, int y) {
	if(dep[x] < dep[y]) swap (x, y);
	R(i, 19, 0) if(dep[x] - dep[y] >= (1 << i)) x = up[i][x];
	if(x == y) return x;
	R(i, 19, 0) if(up[i][x] != up[i][y]) x = up[i][x], y = up[i][y]; 
	return up[0][x];
}
void dfs(int x) {
	if(x > n) dep[ch[x][0]] = dep[ch[x][1]] = dep[x] + 1, dfs(ch[x][0]), dfs(ch[x][1]);	
}

int xtot, xfa[N], xw[N], xch[N][2];
void mgx(int x, int y, int w) {
	x = find(x), y = find(y);
	if(x != y) 
		++xtot, xfa[x] = xfa[y] = f[x] = f[y] = xtot, 
		xch[xtot][0] = x, xch[xtot][1] = y, xw[xtot] = w, siz[xtot] = siz[x] + siz[y]; 
//		cout << "mgx " << x << ' ' << y << ' ' << w << '\n';
} 
vi kk[N];
set < int > te[N], comp[N];
int vis[N], svis[N];
void solve(int x) {
	comp[x].clear();
	if(x > n) {
		solve(ch[x][0]), solve(ch[x][1]);
		set < int > cl = comp[ch[x][0]], cr = comp[ch[x][1]];
		for(const int &u : cl) te[u].clear();
		for(const int &u : cr) te[u].clear();
		
		map < pair < int, int >, int > mp;
		for(const int &u : kk[x]) {
			int xu = find(e[u].u), xv = find(e[u].v);
			te[xu].insert(xv), te[xv].insert(xu);
			mp[make_pair(xu, xv)] += 1; 
			mp[make_pair(xv, xu)] += 1; 
		}
		for(const int &u : cl) {
			vi del;
			for(const int &v : te[u]) 
				if(mp[make_pair(u, v)] != (ll) siz[u] * siz[v]) del.emplace_back(v);
			for(const int &v : del) te[u].erase(v), te[v].erase(u);
		}
		int mxp = -1, mx = 1e9;
		for(const int &u : cl) if(sz(te[u]) < mx) 
			mx = sz(te[u]), mxp = u;
		
		vi must;
		for(const int &v : cr) vis[v] = false;
		for(const int &v : te[mxp]) vis[v] = true;
		int rcnt = 0;
		for(const int &v : cr) 
			if(vis[v]) must.emplace_back(v);
			else rcnt += 1, mgx(mxp, v, w[x]); // , cout << "v = " << v << endl;
//		cout << "mxp = " << mxp << ' ' << rcnt << endl;
		for(const int &u : cl) if(u != mxp) {
			int cnt = 0;
			for(const int &v : te[u]) {
				svis[v] = true;
				if(!vis[v]) cnt += 1;
			}
//			cout << "cnt = " << cnt << '\n';

			if(cnt != rcnt) mgx(mxp, u, w[x]);
			for(const int &v : must) if(!svis[v]) mgx(u, v, w[x]);
			for(const int &v : te[u]) svis[v] = 0;
		}
		
		for(const int &u : cl) 
			comp[x].insert(find(u));
		for(const int &u : cr) 
			comp[x].insert(find(u));
	} else comp[x].insert(x);
}

int rns[N];

void Main() {
	cin >> n >> m, tot = n, xtot = n;
	L(i, 1, m) cin >> e[i].u >> e[i].v >> e[i].w, e[i].id = i;
	sort(e + 1, e + m + 1, [&] (edge a, edge b) {
		return a.w < b.w;
	});
	L(i, 1, n * 2) f[i] = i;
	L(i, 1, m) {
		int x = find(e[i].u), y = find(e[i].v);
		if(x != y) {
			++tot;
			Fa[x] = Fa[y] = tot;
			f[x] = f[y] = tot;
			w[tot] = e[i].w;
			ch[tot][0] = x;
			ch[tot][1] = y;
		}
	}
	L(i, 1, n * 2 - 1) up[0][i] = Fa[i];
	L(i, 1, 19) L(j, 1, n * 2 - 1) up[i][j] = up[i - 1][up[i - 1][j]];
	dep[tot] = 0, dfs(tot);
	
	L(i, 1, tot) kk[i].clear();
	L(i, 1, m) kk[lca(e[i].u, e[i].v)].emplace_back(i);
	
	L(i, 1, n * 2) f[i] = i, siz[i] = (i <= n);
	solve(tot);
	
	L(i, 1, tot) ch[i][0] = xch[i][0], ch[i][1] = xch[i][1], xch[i][0] = xch[i][1] = 0;
	dep[xtot] = 0, dfs(xtot);
	L(i, 1, n * 2 - 1) up[0][i] = xfa[i];
	L(i, 1, 19) L(j, 1, n * 2 - 1) up[i][j] = up[i - 1][up[i - 1][j]];
	L(i, 1, m) rns[e[i].id] = xw[lca(e[i].u, e[i].v)];
//		cout << e[i].u << ' ' << e[i].v << " : " << lca(e[i].u, e[i].v) << '\n';
	L(i, 1, m) cout << rns[i] << ' ';
	cout << '\n';
	L(i, 1, tot) ch[i][0] = ch[i][1] = 0;
}

int main () { 
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main(); 
	return 0;
}