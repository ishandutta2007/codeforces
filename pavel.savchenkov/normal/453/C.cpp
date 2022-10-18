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

int n, m;
vi g[MAXN];
int need[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
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
	forn(i, n) {
		scanf("%d", &need[i]);
	}
	return 1;
}

int have[MAXN];
vi path;
vi sons[MAXN];
vi after[MAXN];
bool used[MAXN];

void dfs(int v) {
	path.pb(v);
	assert(!used[v]);
	used[v] = 1;
	for (int to : g[v]) {
		if  (used[to]) {
			continue;
		}
		dfs(to);
		sons[v].pb(to);
		path.pb(v);
	}
}

void dfs_after(int v, int p) {
	// eprintf("dfs_after v=%d, p=%d\n", v + 1, p + 1);

	for (int to : sons[v]) {
		dfs_after(to, v);
	}

	if  (have[v] != need[v] && p != -1) {
		after[v].pb(p);
		have[v] ^= 1;
		have[p] ^= 1;
	}
}

bool solve() {
	forn(v, n) {
		sons[v].clear();
		after[v].clear();
	}
	path.clear();
	memset (used, 0, sizeof used);

	int root = -1;
	forn(v, n) {
		if  (need[v]) {
			root = v;
			dfs(v);
			break;
		}
	}

	forn(v, n) {
		if  (need[v] && !used[v]) {
			return 0;
		}
	}

	// eprintf("initial path:\n");
	// for (int v : path) {
	// 	eprintf("%d ", v + 1);
	// }
	// eprintf("\n");

	memset (have, 0, sizeof have);
	for (int v : path) {
		have[v] ^= 1;
	}

	dfs_after(root, -1);

	vi bad;
	forn(v, n) {
		if  (need[v] != have[v]) {
			bad.pb(v);
		}
	}
	assert(sz(bad) <= 1);

	if  (sz(bad) == 1) {
		assert(bad[0] == root);
		path.pop_back();
		have[root] ^= 1;
	}

	forn(v, n) {
		assert(need[v] == have[v]);
	}

	vi ans;
	for (int v : path) {
		ans.pb(v);
		while (!after[v].empty()) {
			int to = after[v].back();
			after[v].pop_back();
			ans.pb(to);
			ans.pb(v);
		}
	}

	printf("%d\n", sz(ans));
	for (int v : ans) {
		printf("%d ", v + 1);
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
			puts("-1");
		}
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}