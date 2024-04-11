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

const int MAXN = 1e5 + 10;

struct Edge {
	int a, b;
	int id;

	void read(int i) {
		id = i;
		scanf("%d%d", &a, &b);
		--a;
		--b;
	}

	int to(int v) const {
		assert(v == a || v == b);
		return (a ^ b) ^ v;
	}
};

int n, m;
vi c;
vector<Edge> g[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	forn(i, n) {
		g[i].clear();
	}
	c.resize(n);
	forn(i, n) {
		scanf("%d", &c[i]);
	}
	forn(i, m) {
		Edge e;
		e.read(i);
		g[e.a].pb(e);
		g[e.b].pb(e);
	}
	return 1;
}

vi in_tree;

void dfs0(int v, int p, vi& was, vi& depth, int& root) {
	assert(!was[v]);
	was[v] = 1;
	for (const auto& e : g[v]) {
		const int to = e.to(v);
		if  (to == p) {
			continue;
		}
		if  (was[to]) {
			const int dist = abs(depth[v] - depth[to]);
			if  (dist % 2 == 0) {
				root = v;
			}
			continue;
		}

		in_tree[e.id] = 1;
		depth[to] = depth[v] + 1;
		dfs0(to, v, was, depth, root);
	}
}

int getRoot() {
	vi was(n, 0);
	vi depth(n, 0);
	int root = -1;
	dfs0(0, -1, was, depth, root);
	return root;
}

void dfs1(int v, int p, vi& was, vll& w, vector<Edge>& par, vi& depth) {
	assert(!was[v]);
	was[v] = 1;
	ll sum = 0;
	for (const auto& e : g[v]) {
		const int to = e.to(v);
		if  (to == p) {
			continue;
		}
		if  (was[to]) {
			continue;
		}
		par[to] = e;
		depth[to] = depth[v] + 1;
		dfs1(to, v, was, w, par, depth);
		sum += w[e.id];
	}

	if  (par[v].id == -1) {
		assert(p == -1);
		assert(depth[v] == 0);
		const ll diff = c[v] - sum;
		assert(diff % 2 == 0);
		const ll need = diff / 2;
		for (const auto& e : g[v]) {
			const int to = e.to(v);
			const int dist = depth[to];
			assert(dist > 0);
			if  (dist % 2 == 1) {
				continue;
			}
			w[e.id] = need;
			int u = to;
			int parity = 1;
			while (u != v) {
				w[par[u].id] += (parity ? -1 : +1) * need;
				parity ^= 1;
				u = par[u].to(u);
			}
			assert(parity == 1);
			{
				forn(u, n) {
					ll sum = 0;
					for (const auto& e : g[u]) {
						sum += w[e.id];
					}
					assert(sum == c[u]);
				}
			}
			break;
		}
	} else {
		w[par[v].id] = c[v] - sum;
	}
}

bool solve() {
	in_tree.assign(m, 0);
	int root = getRoot();

	forn(v, n) {
		sort(all(g[v]), [&](const Edge& e1, const Edge& e2) { return in_tree[e1.id] > in_tree[e2.id]; });
	}

	bool must_ok = 1;
	if  (root == -1) {
		must_ok = 0;
		root = 0;
	}

	vi was(n, 0);
	vll w(m, 0);
	vector<Edge> par(n, Edge{-1, -1, -1});
	vi depth(n, 0);
	dfs1(root, -1, was, w, par, depth);

	forn(v, n) {
		ll sum = 0;
		for (const auto& e : g[v]) {
			sum += w[e.id];
		}
		if  (sum != c[v]) {
			assert(!must_ok);
			return 0;
		}
	}

	puts("YES");
	forn(i, m) {
		printf("%lld\n", w[i]);
	}
	printf("\n");
	return 1;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		if  (!solve()) {
			puts("NO");
		}
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}