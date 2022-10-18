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

vii g[MAXN];
int n, m;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	forn(i, n) g[i].clear();
	forn(i, m) {
		int u, v;
		char c;
		scanf("%d %d %c\n", &u, &v, &c);
		--v;
		--u;
		g[v].pb(mp(u, c == 'B'));
		g[u].pb(mp(v, c == 'B'));
	}
	return true;
}

vi g_eq[MAXN];
int comp[MAXN];
int comps;

vi gc[MAXN];
int sz_comp[MAXN];
int color_comp[MAXN];

void dfs0(int v) {
	assert(comp[v] != -1);
	for (int to : g_eq[v]) {
		if  (comp[to] == -1) {
			comp[to] = comp[v];
			dfs0(to);
		}
	}
}

bool dfs1(int v, vi& vs) {
	vs.pb(v);
	assert(color_comp[v] != -1);
	for (int to : gc[v]) {
		if  (color_comp[to] == -1) {
			color_comp[to] = color_comp[v] ^ 1;
			if  (!dfs1(to, vs)) {
				return false;
			}
		}
		if  (color_comp[to] != (color_comp[v] ^ 1)) {
			return false;
		}
	}
	return true;
}

bool paint_from(int vc) {
	vi vs;
	color_comp[vc] = 0;
	if  (!dfs1(vc, vs)) {
		return false;
	}

	vi sum(2, 0);
	for (int v : vs) {
		sum[color_comp[v]] += sz_comp[v];
	}
	if  (sum[1] > sum[0]) {
		for (int v : vs) {
			color_comp[v] ^= 1;
		}
	}
	return true;
}

vi solve(int need) {
	forn(i, n) {
		g_eq[i].clear();
	}

	forn(v, n) {
		for (const auto& e : g[v]) {
			int to = e.fst;
			int c = e.snd;
			if  (c == need) {
				g_eq[v].pb(to);
			}
		}
	}

	memset (comp, -1, sizeof comp);
	comps = 0;
	forn(v, n) {
		if  (comp[v] == -1) {
			comp[v] = comps++;
			dfs0(v);
		}
	}

	memset (sz_comp, 0, sizeof sz_comp);
	forn(v, n) {
		++sz_comp[comp[v]];
	}

	forn(v, n) {
		gc[v].clear();
	}
	forn(v, n) {
		for (const auto& e : g[v]) {
			int to = e.fst;
			int c = e.snd;
			if  (c != need) {
				gc[comp[v]].pb(comp[to]);
			}
		}
	}

	forn(v, comps) {
		sort(all(gc[v]));
		gc[v].resize(unique(all(gc[v])) - gc[v].begin());
	}

	memset (color_comp, -1, sizeof color_comp);
	forn(v, comps) {
		if  (color_comp[v] == -1) {
			if  (!paint_from(v)) {
				return vi(n + 1);
			}
		}
	}

	vi ans;
	forn(v, n) {
		if  (color_comp[comp[v]] == 1) {
			ans.pb(v);
		}
	}

	return ans;
}

void solve() {
	vi ans0 = solve(0);
	vi ans1 = solve(1);

	vi ans = ans0;
	if  (sz(ans1) < sz(ans)) {
		ans = ans1;
	}

	if  (sz(ans) > n) {
		puts("-1");
		return;
	}

	printf("%d\n", sz(ans));
	for (int v : ans) {
		printf("%d ", v + 1);
	}
	puts("");
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