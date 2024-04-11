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

int n, m, h;
vi u;
vi c[2];

bool read() {
	if  (scanf("%d%d%d", &n, &m, &h) < 2) {
		return 0;
	}
	u.resize(n);
	forn(i, n) {
		scanf("%d", &u[i]);
	}
	forn(i, 2) {
		c[i].resize(m);
	}
	forn(i, m) {
		scanf("%d%d", &c[0][i], &c[1][i]);
		--c[0][i];
		--c[1][i];
	}
	return 1;
}

vvi g;
vvi gt;
vi used;
vi comp;

void addE(int v, int to) {
	g[v].pb(to);
	gt[to].pb(v);
	eprintf("%d -> %d\n", v, to);
}

void dfs0(int v, vi& top) {
	assert(!used[v]);
	used[v] = 1;
	for (int to : g[v]) {
		if  (!used[to]) {
			dfs0(to, top);
		}
	}
	top.pb(v);
}

void dfs1(int v) {
	assert(comp[v] != -1);
	for (int from : gt[v]) {
		if  (comp[from] == -1) {
			comp[from] = comp[v];
			dfs1(from);
		}
	}
}

void solve() {
	g.clear();
	g.resize(n);
	gt.clear();
	gt.resize(n);

	forn(i, m) {
		forn(j, 2) {
			const int a = c[j][i];
			const int b = c[(j + 1) % 2][i];
			if  (u[b] == (u[a] + 1) % h) {
				addE(a, b);
			}
		}
	}

	vi top;
	used.assign(n, 0);
	forn(v, n) {
		if  (!used[v]) {
			dfs0(v, top);
		}
	}
	reverse(all(top));

	int comps = 0;
	comp.assign(n, -1);
	for (int v : top) {
		if  (comp[v] == -1) {
			comp[v] = comps++;
			dfs1(v);
		}
	}

	vi sz_comp(comps);
	forn(v, n) {
		++sz_comp[comp[v]];
	}

	vi is_sink(comps, 1);
	forn(v, n) {
		for (int to : g[v]) {
			if (comp[to] != comp[v]) {
				is_sink[comp[v]] = 0;
			}
		}
	}

	int best = -1;
	forn(c, comps) {
		if (is_sink[c]) {
			if (best == -1 || sz_comp[best] > sz_comp[c]) {
				best = c;
			}
		}
	}
	assert(best != -1);

	vi ans;
	forn(v, n) {
		if (comp[v] == best) {
			ans.pb(v);
		}
	}

	printf("%d\n", sz(ans));
	for (int v : ans) {
		printf("%d ", v + 1);
	}
	printf("\n\n");
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
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}