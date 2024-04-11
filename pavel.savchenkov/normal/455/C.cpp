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

const int MAXN = 3e5 + 10;

struct DSU {
	vi par;
	vi val;

	DSU(int n = 0) {
		par.assign(n, -1);
		val.assign(n, 0);
	}

	int get_set(int x) {
		return par[x] < 0 ? x : par[x] = get_set(par[x]);
	}

	void set_val(int x, int v) {
		val[get_set(x)] = v;
	}

	void union_set(int x, int y) {
		x = get_set(x);
		y = get_set(y);
		if  (x == y) {
			return;
		}
		if  (-par[x] > -par[y]) {
			swap(x, y);
		}
		par[y] += par[x];
		par[x] = y;
	}

	int get_val(int x) {
		return val[get_set(x)];
	}
};

vi g[MAXN];
int n, m, q;
bool was[MAXN];

bool read() {
	if  (scanf("%d%d%d", &n, &m, &q) < 3) {
		return false;
	}
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
	}
	return true;
}

int dfs_far(int v, int p, DSU& dsu, int depth, int& dist) {
	was[v] = true;
	int res = v;
	dist = max(dist, depth);
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		dsu.union_set(v, to);
		int cur_dist = 0;
		int cur_res = dfs_far(to, v, dsu, depth + 1, cur_dist);
		if  (cur_dist > dist) {
			dist = cur_dist;
			res = cur_res;
		}
	}
	return res;
}

int most_far(DSU& dsu, int v, int& dist) {
	return dfs_far(v, -1, dsu, 0, dist);
}

int diam(DSU& dsu, int v) {
	int d = 0;
	int u = most_far(dsu, v, d);
	most_far(dsu, u, d);
	return d;
}

void precalc(DSU& dsu, int v) {
	int d = diam(dsu, v);
	dsu.set_val(v, d);
}

void solve() {
	DSU dsu(n);
	memset (was, 0, sizeof was);
	forn(i, n) {
		if  (!was[i]) {
			precalc(dsu, i);
		}
	}

	forn(it, q) {
		int t;
		scanf("%d", &t);
		if  (t == 1) {
			int x;
			scanf("%d", &x);
			--x;
			printf("%d\n", dsu.get_val(x));
		} else {
			assert(t == 2);
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			if  (dsu.get_set(x) == dsu.get_set(y)) {
				continue;
			}
			int dx = dsu.get_val(x);
			int dy = dsu.get_val(y);
			dsu.union_set(x, y);
			dsu.set_val(x, max(dx, max(dy, (dx + 1) / 2 + (dy + 1) / 2 + 1)));
		}
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