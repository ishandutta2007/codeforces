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


const int MAXN = 5000 + 10;
const int INF = 1e9;

vi g[MAXN];
vi gr[MAXN];
int n, m;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	forn(i, n) {
		g[i].clear();
	}
	forn(i, m) {
		int v, to;
		scanf("%d%d", &v, &to);
		--v;
		--to;
		g[v].pb(to);
		gr[to].pb(v);
	}
	return true;
}

int comp[MAXN];
int comps;

vi order;
bool was[MAXN];

bool leaf_comp[MAXN];

void dfs0(int v) {
	was[v] = true;
	for (int to : g[v]) {
		if  (!was[to]) {
			dfs0(to);
		}
	}
	order.pb(v);
}

void dfs1(int v) {
	for (int to : gr[v]) {
		if  (comp[to] == -1) {
			comp[to] = comp[v];
			dfs1(to);
		}
	}
}

bool used_comp[MAXN];
int V, TO;

int Q[2 * MAXN];
int ql, qr;
int dist[MAXN];

int calc_dist(int s, int t) {
	forn(v, n) {
		dist[v] = INF;
	}
	dist[s] = 0;
	ql = qr = 0;
	Q[qr++] = s;
	while (ql != qr) {
		int v = Q[ql++];
		for (int to : g[v]) {
			if  (V == v && TO == to) {
				continue;
			}
			if  (dist[to] > dist[v] + 1) {
				dist[to] = dist[v] + 1;
				Q[qr++] = to;
			}
		}
	}

	return dist[t];
}

void solve_comp(int c, int& cnt_cycles, int& sum_len) {
	vi vs;
	forn(v, n) {
		if  (comp[v] == c) {
			vs.pb(v);
		}
	}

	if  (sz(vs) == 1) {
		return;
	}

	int min_len = INF;
	for (int v : vs) {
		for (int to : g[v]) {
			V = v;
			TO = to;
			min_len = min(min_len, calc_dist(to, v));
		}
	}

	assert(min_len < INF);
	++cnt_cycles;
	sum_len += min_len + 1;
}

int solve() {
	memset (was, false, sizeof was);
	order.clear();
	forn(v, n) {
		if  (!was[v]) {
			dfs0(v);
		}
	}

	memset (comp, -1, sizeof comp);
	comps = 0;
	reverse(all(order));
	for (int v : order) {
		if  (comp[v] == -1) {
			comp[v] = comps++;
			dfs1(v);
		}
	}

	memset (leaf_comp, true, sizeof leaf_comp);
	forn(v, n) for (int to : g[v]) {
		if  (comp[v] == comp[to]) {
			continue;
		}
		leaf_comp[comp[v]] = false;
	}

	int cnt_cycles = 0;
	int sum_len = 0;
	forn(v, n) {
		if  (leaf_comp[comp[v]] && !used_comp[comp[v]]) {
			used_comp[comp[v]] = true;
			solve_comp(comp[v], cnt_cycles, sum_len);
		}
	}

	return (n - sum_len) + cnt_cycles + sum_len * 999;
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