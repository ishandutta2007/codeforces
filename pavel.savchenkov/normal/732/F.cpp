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
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
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

const int MAXN = 4e5 + 10;

int n, m;
vi g[MAXN];
vii es;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	es.clear();
	forn(i, n) {
		g[i].clear();
	}
	forn(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].pb(b);
		g[b].pb(a);
		es.pb(mp(a, b));
	}
	return true;
}

int tin[MAXN];
int fup[MAXN];
int timer;
set<pii> bridges;
set<pii> ans;

void dfs(int v, int p) {
	tin[v] = timer++;
	fup[v] = tin[v];
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		if  (tin[to] != -1) {
			if  (tin[to] < tin[v]) {
				fup[v] = min(fup[v], tin[to]);
				ans.insert(mp(v, to));
			} else {
				fup[v] = min(fup[v], fup[to]);
			}
			continue;
		}
		dfs(to, v);
		if  (fup[to] > tin[v]) {
			bridges.insert(mp(v, to));
			bridges.insert(mp(to, v));
		} else {
			ans.insert(mp(v, to));
		}
		fup[v] = min(fup[v], fup[to]);
	}
}

struct DSU {
	vi par;

	DSU(int n = 0) {
		par.assign(n, -1);
	}

	int get(int x) {
		return par[x] < 0 ? x : par[x] = get(par[x]);
	}

	bool union_set(int x, int y) {
		x = get(x);
		y = get(y);

		if  (x == y) {
			return 0;
		}

		if  (-par[x] < -par[y]) {
			swap(x, y);
		}

		par[x] += par[y];
		par[y] = x;
		return true;
	}

	int size(int x) {
		return -par[get(x)];
	}
};

void dfs2(int v, int p) {
	tin[v] = 1;
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		if  (tin[to]) {
			continue;
		}
		if  (!ans.count(mp(v, to)) && !ans.count(mp(to, v))) {
			ans.insert(mp(to, v));
		}
		dfs2(to, v);
	}
}

void solve() {
	timer = 0;
	memset (tin, -1, sizeof tin);
	dfs(0, -1);

	DSU dsu(n);
	forn(v, n) for (int to : g[v]) {
		if (!bridges.count(mp(v, to))) {
			dsu.union_set(v, to);
		}
	}

	int mx = -1;
	forn(v, n) {
		if  (dsu.get(v) != v) {
			continue;
		}
		if  (mx == -1 || dsu.size(v) > dsu.size(mx)) {
			mx = v;
		}
	}

	memset (tin, 0, sizeof tin);
	dfs2(mx, -1);

	printf("%d\n", dsu.size(mx));
	for (auto e : es) {
		if  (!ans.count(e)) {
			swap(e.fst, e.snd);
		}
		assert(ans.count(e));
		printf("%d %d\n", e.fst + 1, e.snd + 1);
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