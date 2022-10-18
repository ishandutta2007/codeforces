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

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

struct DSU {
	vi par;

	DSU(int n = 0) {
		par.assign(n, -1);
	}

	int get_set(int x) {
		return par[x] < 0 ? x : par[x] = get_set(par[x]);
	}

	bool union_set(int x, int y) {
		assert(0 <= x && x < sz(par));
		assert(0 <= y && y < sz(par));
		x = get_set(x);
		y = get_set(y);
		assert(0 <= x && x < sz(par));
		assert(0 <= y && y < sz(par));
		if  (x == y) {
			return false;
		}
		if  (-par[x] > -par[y]) {
			swap(x, y);
		}
		par[y] += par[x];
		par[x] = y;
		return true;
	}
};

vvi a;
int n, m;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	a.assign(n, vi(m, 0));
	forn(i, n) forn(j, m) {
		scanf("%d", &a[i][j]);
	}
	return true;
}

int code(int i, int j) {
	return i * m + j;
}

void dfs(int v, vi& was, DSU& dsu, vi& order, const vvi& g) {
	// printf("in %d %d\n", v / m, v % m);
	if  (dsu.get_set(v) != v || was[v]) {
		return;
	}
	was[v] = true;
	assert(0 <= v && v < sz(g));
	for (int to : g[v]) {
		if  (was[to]) {
			continue;
		}
		dfs(to, was, dsu, order, g);
	}
	// printf("pb %d\n", v);
	order.pb(v);
}

void solve() {
	DSU dsu(n * m);

	// init
	forn(i, n) {
		vector<pii> cur;
		forn(j, m) {
			cur.pb(mp(a[i][j], j));
		}
		sort(all(cur));
		int l = 0;
		while (l < sz(cur)) {
			int r = l;
			while (r < sz(cur) && cur[l].fst == cur[r].fst) ++r;
			for (int z = l; z + 1 < r; ++z) {
				int j = cur[z].snd;
				int next_j = cur[z + 1].snd;
				dsu.union_set(code(i, j), code(i, next_j));
			}
			l = r;
		}
	}

	forn(j, m) {
		vector<pii> cur;
		forn(i, n) {
			cur.pb(mp(a[i][j], i));
		}
		sort(all(cur));
		int l = 0;
		while (l < sz(cur)) {
			int r = l;
			while (r < sz(cur) && cur[l].fst == cur[r].fst) ++r;
			for (int z = l; z + 1 < r; ++z) {
				int i = cur[z].snd;
				int next_i = cur[z + 1].snd;
				dsu.union_set(code(i, j), code(next_i, j));
			}
			l = r;
		}
	} 

	vvi gt(n * m);
	vvi g(n * m);

	// build
	forn(i, n) {
		vector<pii> cur;
		forn(j, m) {
			cur.pb(mp(a[i][j], j));
		}
		sort(all(cur));
		int l = 0;
		while (l < sz(cur)) {
			int r = l;
			while (r < sz(cur) && cur[l].fst == cur[r].fst) ++r;
			if  (r < sz(cur)) {
				int j = cur[l].snd;
				int next_j = cur[r].snd;
				int from = dsu.get_set(code(i, j));
				int to = dsu.get_set(code(i, next_j));
				gt[to].pb(from);
				g[from].pb(to);
			}
			l = r;
		}
	}

	forn(j, m) {
		vector<pii> cur;
		forn(i, n) {
			cur.pb(mp(a[i][j], i));
		}
		sort(all(cur));
		int l = 0;
		while (l < sz(cur)) {
			int r = l;
			while (r < sz(cur) && cur[l].fst == cur[r].fst) ++r;
			if  (r < sz(cur)) {
				int i = cur[l].snd;
				int next_i = cur[r].snd;
				int from = dsu.get_set(code(i, j));
				int to = dsu.get_set(code(next_i, j));
				gt[to].pb(from);
				g[from].pb(to);
			}
			l = r;
		}
	} 

	vi was(n * m, 0);
	vi order;
	forn(v, n * m) {
		dfs(v, was, dsu, order, g);
	}

	// printf("comps:\n");
	// forn(i, n) {
	// 	forn(j, m) {
	// 		printf("%d ", dsu.get_set(code(i, j)));
	// 	}
	// 	puts("");
	// }
	// puts("");

	// printf("edges:\n");
	// forn(v, n * m) {
	// 	for (int to : gt[v]) {
	// 		printf("%d -> %d\n", v, to);
	// 	}
	// }
	// puts("");
	// return;

	reverse(all(order));
	vvi val(n, vi(m, 1));
	for (int v : order) {
		int i = v / m;
		int j = v % m;
		// printf("v = %d, %d %d\n", v, i, j);
		int V = dsu.get_set(v);
		for (int from : gt[V]) {
			// printf("%d -> %d\n", from, V);
			int fi = from / m;
			int fj = from % m;
			val[i][j] = max(val[i][j], val[fi][fj] + 1);
		}
		// printf("val[%d] = %d\n", v, val[i][j]);
	}

	forn(v, n * m) {
		int i = v / m;
		int j = v % m;
		int V = dsu.get_set(v);
		int I = V / m;
		int J = V % m;
		val[i][j] = val[I][J];
	}

	forn(i, n) {
		forn(j, m) {
			printf("%d ", val[i][j]);
		}
		printf("\n");
	}
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

	return 0;
}