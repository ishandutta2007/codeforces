#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"

const ll INF = 1e18;
const int MAXN = 3e5 + 10;
const int MAXL = 20;

int n, m, s;
vector<vii> g;

bool read() {
	if  (scanf("%d%d%d", &n, &m, &s) < 3) {
		return 0;
	}
	--s;
	g.clear();
	g.resize(n);
	forn(i, m) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		--a;
		--b;
		g[a].pb(mp(b, w));
		g[b].pb(mp(a, w));
	}
	return 1;
}

vll dij(const vector<vii>& g, const int& s) {
	const int N = sz(g);
	vll dist(N, INF);
	dist[s] = 0;
	set<pair<ll, int>> S;
	S.insert(mp(dist[s], s));
	while (!S.empty()) {
		int v = S.begin()->snd;
		S.erase(S.begin());
		for (const auto& e : g[v]) {
			int to, w;
			tie(to, w) = e;
			if  (dist[to] > dist[v] + w) {
				S.erase(mp(dist[to], to));
				dist[to] = dist[v] + w;
				S.insert(mp(dist[to], to));
			}
		}
	}
	return dist;
}

vvi dag;
vvi dag_t;
bool was[MAXN];
int par[MAXN][MAXL];
int depth[MAXN];

void dfs(int v, vi& top) {
	assert(!was[v]);
	was[v] = 1;
	for (const auto& to : dag[v]) {
		if  (!was[to]) {
			dfs(to, top);
		}
	}
	top.pb(v);
}

int go_up(int v, int cnt) {
	int v0 = v;
	int cnt0 = cnt;
	ford(l, MAXL) {
		if  ((1 << l) <= cnt) {
			v = par[v][l];
			cnt -= 1 << l;
		}
	}
	assert(depth[v0] - depth[v] == cnt0);
	return v;
}

int lca(int v, int u) {
	if  (depth[v] < depth[u]) {
		swap(v, u);
	}
	v = go_up(v, depth[v] - depth[u]);
	if  (v == u) {
		return v;
	}
	ford(l, MAXL) {
		if  (par[v][l] != par[u][l]) {
			v = par[v][l];
			u = par[u][l];
		}
	}
	return par[v][0];
}

int ans[MAXN];
vvi sons;
int sz[MAXN];

void dfs_sz(int v) {
	sz[v] = 1;
	for (int to : sons[v]) {
		dfs_sz(to);
		sz[v] += sz[to];
	}
}

int solve() {
	vll dist = dij(g, s);

	dag.clear();
	dag.resize(n);
	dag_t.clear();
	dag_t.resize(n);
	forn(v, n) for (const auto& e : g[v]) {
		int to, w;
		tie(to, w) = e;
		if  (dist[v] + w == dist[to]) {
			dag[v].pb(to);
			dag_t[to].pb(v);
		}
	}

	vi top;
	memset (was, 0, sizeof was);
	dfs(s, top);
	reverse(all(top));

	sons.clear();
	sons.resize(n);

	forn(i, MAXL) par[s][i] = s;
	depth[s] = 0;
	for (int it = 1; it < sz(top); ++it) {
		int v = top[it];
		int p = -1;
		for (int from : dag_t[v]) {
			if  (p == -1) {
				p = from;
			} else {
				p = lca(p, from);
			}
		}
		assert(p != -1);
		sons[p].pb(v);

		depth[v] = depth[p] + 1;
		par[v][0] = p;
		for (int i = 1; i < MAXL; ++i) {
			par[v][i] = par[par[v][i - 1]][i - 1];
		}
	}

	memset (sz, 0, sizeof sz);
	dfs_sz(s);

	int ans = 0;
	forn(v, n) {
		if  (v != s) {
			ans = max(ans, sz[v]);
		}
	}
	
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}