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
const int MAXLOG = 19;

vi g[MAXN];
int par[MAXN][MAXLOG];
int n, m;
int tin[MAXN];
int tout[MAXN];
int timer;
int depth[MAXN];
ll sum[MAXN];
ll sum2[MAXN];
int sz[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
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

bool upper(int a, int b) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

void dfs0(int v, int p) {
	par[v][0] = p;
	for (int i = 1; i < MAXLOG; ++i) {
		par[v][i] = par[par[v][i - 1]][i - 1];
	}
	tin[v] = timer++;
	sz[v] = 1;
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		depth[to] = depth[v] + 1;
		dfs0(to, v);
		sz[v] += sz[to];
	}
	tout[v] = timer;
}

int lca(int a, int b) {
	if  (upper(a, b)) return a;
	if  (upper(b, a)) return b;
	ford(l, MAXLOG) {
		if  (!upper(par[a][l], b)) {
			a = par[a][l];
		}
	}
	return par[a][0];
}

void dfs1(int v, int p) {
	sum[v] = 0;
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		dfs1(to, v);
		sum[v] += sum[to] + sz[to];
	}
}

void dfs2(int v, int p, ll sum_up) {
	sum2[v] = sum_up;
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		ll cur_sum = sum[v] - (sum[to] + sz[to]);
		dfs2(to, v, sum_up + cur_sum + (n - sz[to]));
	}
}

void precalc() {
	timer = 0;
	depth[0] = 0;
	dfs0(0, 0);
	dfs1(0, 0);
	dfs2(0, 0, 0);
}

ld solve(int u, int v) {
	int z = lca(u, v);
	int len = depth[u] - depth[z] + depth[v] - depth[z];
	++len;
	if  (z == u) {
		swap(v, u);
	}

	ll sum_v = sum[v];
	int sz_v = sz[v];
	if  (z == v) {
		int uu = u;
		ford(l, MAXLOG) {
			if  (!upper(par[uu][l], v)) {
				uu = par[uu][l];
			}
		}
		sum_v = sum2[v] + (sum[v] - (sum[uu] + sz[uu]));
		sz_v = n - sz[uu];
	}
	// printf("u=%d, v=%d, su=%lld, sv=%lld\n", u + 1, v + 1, sum[u], sum_v);
	return len + (double) sum[u] / sz[u] + (double) sum_v / sz_v;
}

void solve() {
	precalc();

	// forn(i, n) {
	// 	printf("sum[%d] = %lld, sum_up = %lld\n", i + 1, sum[i], sum2[i]);
	// }

	forn(i, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		printf("%.15f\n", (double) solve(u, v));
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