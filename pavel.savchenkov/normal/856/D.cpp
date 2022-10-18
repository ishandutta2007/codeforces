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

struct Edge {
	int a, b;
	int cost;

	void read() {
		scanf("%d%d%d", &a, &b, &cost);
		--a;
		--b;
	}
};

int n, m;
vvi g;
vector<Edge> es;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	g.clear();
	g.resize(n);
	for (int i = 1; i < n; ++i) {
		int par;
		scanf("%d", &par);
		--par;
		g[par].pb(i);
	}
	es.resize(m);
	forn(i, m) {
		es[i].read();
	}
	return 1;
}

struct FenwTree {
	vi t;

	FenwTree(int n = 0) {
		t.assign(n, 0);
	}

	int get(int r) {
		int s = 0;
		for (int i = r; i >= 0; i &= i + 1, --i) {
			s += t[i];
		}
		return s;
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}

	void inc(int pos, int v) {
		for (int i = pos; i < sz(t); i |= i + 1) {
			t[i] += v;
		}
	}
};

int LOG;
vvi par;
vi tin;
vi tout;
int timer;
vector<vector<Edge>> es_node;
vi dp;
vi sum_dp;
vi order;
FenwTree fenwTree;

bool upper(int a, int b) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
	if  (upper(a, b)) {
		return a;
	}
	if  (upper(b, a)) {
		return b;
	}
	ford(l, LOG) {
		if  (!upper(par[b][l], a)) {
			b = par[b][l];
		}
	}
	return par[b][0];
}

void set_func(int v, int f) {
	fenwTree.inc(tin[v], f);
	fenwTree.inc(tout[v], -f);
}

int sum_func(int a, int b) {
	assert(upper(a, b));
	int ans = fenwTree.get(0, tin[b]);
	if  (a) {
		ans -= fenwTree.get(0, tin[a] - 1);
	}
	return ans;
}

void dfs0(int v, int p) {
	tin[v] = timer++;
	order.pb(v);

	par[v][0] = p;
	for (int i = 1; i < LOG; ++i) {
		par[v][i] = par[par[v][i - 1]][i - 1];
	}

	for (int to : g[v]) {
		dfs0(to, v);
	}

	tout[v] = timer++;
	order.pb(v);
}

void dfs(int v) {
	sum_dp[v] = 0;
	for (int to : g[v]) {
		dfs(to);
		sum_dp[v] += dp[to];
	}

	dp[v] = sum_dp[v];

	auto find_son = [&](int u) {
		int L = 0;
		int R = sz(g[v]);
		while (L != R - 1) {
			int M = (L + R) / 2;
			if  (tin[g[v][M]] <= tin[u]) {
				L = M;
			} else {
				R = M;
			}
		}
		return L;
	};

	for (const auto& e : es_node[v]) {
		int a = e.a;
		int b = e.b;
		assert(a != b);

		if  (tin[a] > tin[b]) {
			swap(a, b);
		}

		int cur = e.cost;

		const int b_to = g[v].at(find_son(b));
		if  (a == v) {
			cur += sum_dp[b];
			cur += sum_func(b_to, b);
			cur += sum_dp[v] - dp[b_to];
		} else {
			const int a_to = g[v].at(find_son(a));
			cur += sum_dp[a];
			cur += sum_func(a_to, a);
			cur += sum_dp[b];
			cur += sum_func(b_to, b);
			cur += sum_dp[v] - dp[a_to] - dp[b_to];
		}

		dp[v] = max(dp[v], cur);
	}

	for (int to : g[v]) {
		set_func(to, sum_dp[v] - dp[to]);
	}
}

int solve() {
	LOG = 0;
	while ((1 << LOG) < n) {
		++LOG;
	}
	par.assign(n, vi(LOG));
	timer = 0;
	tin.assign(n, 0);
	tout.assign(n, 0);
	order.clear();

	dfs0(0, 0);

	es_node.clear();
	es_node.resize(n);
	for (const auto& e : es) {
		int lc = lca(e.a, e.b);
		es_node[lc].pb(e);
	}

	fenwTree = FenwTree(sz(order));
	dp.assign(n, 0);
	sum_dp.assign(n, 0);
	dfs(0);

	return dp[0];
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