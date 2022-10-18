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

int n, m, k, q;

bool read() {
	if  (scanf("%d%d%d%d", &n, &m, &k, &q) < 4) {
		return 0;
	}
	return 1;
}

vvi sons;
vi sz;
vi par;
vi tin;
vi tout;
int timer;

void addE(int v, int to) {
	sons[to].pb(v);
	assert(par[v] == -1);
	par[v] = to;
} 

void dfs_sz(int v) {
	tin[v] = timer++;
	sz[v] = 1;
	for (int to : sons[v]) {
		dfs_sz(to);
		sz[v] += sz[to];
	}
	tout[v] = timer++;
}

bool is_upper(int a, int b) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

void solve() {
	sz.assign(n, 0);
	par.assign(n, -1);
	sons.assign(n, vi());

	vi last(m, -1);
	forn(it, k) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;

		if  (last[b] != -1) {
			addE(a, last[b]);
		}
		last[b] = a;
	}

	vi roots;
	forn(v, n) {
		if  (par[v] == -1) {
			roots.pb(v);
		}
	}

	tin.assign(n, 0);
	tout.assign(n, 0);
	timer = 0;
	for (int r : roots) {
		dfs_sz(r);
	}

	vi ans(q, 0);
	forn(i, q) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;

		if  (last[b] == -1) {
			continue;
		}

		int v = a;
		int to = last[b];
		if  (!is_upper(v, to)) {
			continue;
		}

		ans[i] = sz[v];
	}

	forn(i, q) {
		printf("%d\n", ans[i]);
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