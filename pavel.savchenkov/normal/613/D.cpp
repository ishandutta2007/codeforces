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

const int MAXN = 1e5 + 10;
const int LOG = 19;

vi g[MAXN];
int n;
int par[MAXN][LOG];
int tin[MAXN];
int tout[MAXN];
int timer;
vi g_cur[MAXN];
int time_mark[MAXN];
int depth[MAXN];

void clear_mark() {
	++timer;
}

bool is_mark(int v) {
	return time_mark[v] == timer;
}

void put_mark(int v) {
	time_mark[v] = timer;
}

void dfs0(int v, int p) {
	par[v][0] = p;
	for (int i = 1; i < LOG; ++i) {
		par[v][i] = par[par[v][i - 1]][i - 1];
	}
	tin[v] = timer++;
	for (int to : g[v]) {
		if  (to != p) {
			depth[to] = depth[v] + 1;
			dfs0(to, v);
		}  
	}
	tout[v] = timer++;
}

bool upper(int a, int b) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
	ford(l, LOG) {
		if  (!upper(par[a][l], b)) {
			a = par[a][l];
		}
	}
	if  (!upper(a, b)) {
		a = par[a][0];
	}
	return a;
}

void precalc() {
	forn(v, n) {
		sort(all(g[v]));
	}
	depth[0] = 0;
	timer = 0;
	dfs0(0, 0);
}

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	return true;
}

bool haveE(int a, int b) {
	int pos = lower_bound(all(g[a]), b) - g[a].begin();
	return pos < sz(g[a]) && g[a][pos] == b;
}

int dfs(int v, int& have) {
	have = 0;
	int cnt_need = 0;
	for (int to : g_cur[v]) {
		int cur_have = 0;
		cnt_need += dfs(to, cur_have);
		have += cur_have;
	}

	if  (is_mark(v)) {
		have += cnt_need;
		return 1;
	}

	if  (cnt_need > 1) {
		have += 1;
		return 0;
	}

	return cnt_need;
}

int solve_q() {
	int k;
	scanf("%d", &k);
	vi vers(k);
	forn(i, k) {
		assert(scanf("%d", &vers[i]));
		--vers[i];
	}

	sort(all(vers), [](int a, int b) { return tin[a] < tin[b]; });
	clear_mark();
	for (int a : vers) {
		put_mark(a);
	}
	vi aux_vers;
	forn(i, sz(vers) - 1) {
		int a = vers[i];
		int b = vers[i + 1];
		aux_vers.pb(lca(a, b));
	}
	for (int a : aux_vers) {
		vers.pb(a);
	}
	sort(all(vers));
	vers.resize(unique(all(vers)) - vers.begin());

	for (int a : vers) {
		g_cur[a].clear();
	}

	set<pii> S;
	for (int a : vers) {
		S.insert(mp(tin[a], a));
	}
	sort(all(vers), [](int a, int b) { return depth[a] > depth[b]; });
	for (int a : vers) {
		while (1) {
			auto it = S.upper_bound(mp(tin[a], n));
			if  (it == S.end()) {
				break;
			}
			int to = it->snd;
			if  (!upper(a, to)) {
				break;
			}
			g_cur[a].pb(to);
			// printf("%d -> %d\n", a + 1, to + 1);
			S.erase(it);
		}
	}

	int root = vers[0];
	for (int a : vers) {
		if  (tin[a] < tin[root]) {
			root = a;
		}
	}

	for (int a : vers) {
		for (int to : g_cur[a]) {
			if  (is_mark(a) && is_mark(to) && haveE(a, to)) {
				return -1;
			}
		}
	}

	int have = 0;
	dfs(root, have);
	return have;
}

void solve() {
	precalc();

	timer = 0;
	forn(i, n) {
		time_mark[i] = -1;
	}

	int q;
	scanf("%d", &q);
	forn(i, q) {
		printf("%d\n", solve_q());
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