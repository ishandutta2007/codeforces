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

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

struct Query {
	int type;
	int u, v;

	void read() {
		scanf("%d%d%d", &type, &u, &v);
		--u;
		--v;
	}
};

int n, q;
vector<vii> g;
vector<Query> qs;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	g.clear();
	g.resize(n);
	forn(i, n) {
		int par, t;
		scanf("%d%d", &par, &t);
		if  (par == -1) {
			continue;
		}
		--par;
		++t;
		g[par].pb(mp(i, t));
	}

	scanf("%d", &q);
	qs.resize(q);
	forn(i, q) {
		qs[i].read();
	}
	return 1;
}

int LOG;
vvi par;
vi sum;
vi comp;
vi depth;

void dfs(int v, int p, int val, int de) {
	depth[v] = de;
	sum[v] = val + sum[p];

	par[v][0] = p;
	for (int i = 1; i < LOG; ++i) {
		par[v][i] = par[par[v][i - 1]][i - 1];
	}

	for (const auto& e : g[v]) {
		int to, type;
		tie(to, type) = e;

		assert(to != p);

		comp[to] = comp[v];
		dfs(to, v, (type == 1), de + 1);
	}
}

int go_up(int a, int cnt) {
	ford(l, LOG) {
		if  ((1 << l) <= cnt) {
			a = par[a][l];
			cnt -= 1 << l;
		}
	}
	return a;
}

int lca(int a, int b) {
	if  (depth[a] < depth[b]) {
		swap(a, b);
	}

	a = go_up(a, depth[a] - depth[b]);

	ford(l, LOG) {
		if  (par[a][l] != par[b][l]) {
			a = par[a][l];
			b = par[b][l];
		}
	}

	if  (a != b) {
		a = par[a][0];
		b = par[b][0];
	}

	assert(a == b);
	return a;
}

int get_sum(int a, int b) {
	return sum[a] - sum[b];
}

bool ask1(int u, int v) {
	if  (u == v || comp[u] != comp[v]) {
		return 0;
	}

	int up_v = go_up(v, depth[v] - depth[u]);
	if  (up_v != u) {
		return 0;
	}

	const int s = get_sum(v, u);
	if  (s == depth[v] - depth[u]) {
		return 1;
	}
	return 0;
}

bool ask2(int u, int v) {
	if  (v == u || comp[v] != comp[u]) {
		return 0;
	}

	const int c = lca(v, u);
	if  (v == c) {
		return 0;
	}

	if  (get_sum(v, c) != 0) {
		return 0;
	}

	if  (get_sum(u, c) != depth[u] - depth[c]) {
		return 0;
	}

	return 1;
}

void solve() {
	LOG = 0;
	while ((1 << LOG) <= n) ++LOG;

	par.assign(n, vi(LOG, 0));
	sum.assign(n, 0);

	comp.assign(n, -1);
	depth.assign(n, 0);
	int comps = 0;
	forn(v, n) {
		if  (comp[v] == -1) {
			comp[v] = comps++;
			dfs(v, v, 0, 0);
		}
	}

	// forn(v, n) {
	// 	eprintf("sum[%d] = %d, depth = %d\n", v + 1, sum[v], depth[v]);
	// }

	for (const auto& q : qs) {
		bool ok = 0;
		if  (q.type == 1) {
			ok = ask1(q.u, q.v);
		} else {
			ok = ask2(q.u, q.v);
		}

		puts(ok ? "YES" : "NO");
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}