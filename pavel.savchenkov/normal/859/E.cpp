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

const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int mpow(int a, int p) {
	int res = 1;
	for (; p > 0; p >>= 1, a = mul(a, a)) {
		if  (p & 1) {
			res = mul(res, a);
		}
	}
	return res;
}

int inv(int x) {
	int y = mpow(x, MOD - 2);
	assert(mul(x, y) == 1);
	return y;
}

const int MAXN = 2e5 + 10;

int n;
vi g[MAXN];
vi gt[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, 2 * n) {
		g[i].clear();
		gt[i].clear();
	}
	forn(i, n) {
		int v, to;
		scanf("%d%d", &v, &to);
		--v;
		--to;
		g[v].pb(to);
		gt[to].pb(v);
	}
	return 1;
}

void dfs0(int v, vi& was, vi& vs) {
	assert(!was[v]);
	vs.pb(v);
	was[v] = 1;
	for (vi sons : {g[v], gt[v]}) {
		for (int to : sons) {
			if  (!was[to]) {
				dfs0(to, was, vs);
			}
		}
	}
}

int col[MAXN];
int dp[2][MAXN];

bool dfs_cycle(int v) {
	assert(!col[v]);
	col[v] = 1;
	for (int to : g[v]) {
		if  (col[to] == 1) {
			return 1;
		}
		if  (!col[to]) {
			if  (dfs_cycle(to)) {
				return 1;
			}
		}
	}
	col[v] = 2;
	return 0;
}

void dfs_dp(int v) {
	for (int to : gt[v]) {
		dfs_dp(to);
	}

	dp[0][v] = 1;
	for (int to : gt[v]) {
		dp[0][v] = mul(dp[0][v], dp[0][to]);
	}

	dp[1][v] = 0;
	int none = 1;
	for (int to : gt[v]) {
		none = mul(none, dp[0][to]);
	}
	add(dp[1][v], none);
	for (int to : gt[v]) {
		int cur = none;
		cur = mul(cur, inv(dp[0][to]));
		cur = mul(cur, dp[1][to]);
		add(dp[1][v], cur);
	}

	// eprintf("v = %d\n", v + 1);
	// eprintf("dp:\n");
	// forn(c, 2) {
	// 	eprintf("%d ", dp[c][v]);
	// }
	// eprintf("\n");
}

int solve(vi vs) {
	for (int v : vs) {
		for (int to : g[v]) {
			if  (to == v) {
				return 1;
			}
		}
	}

	assert(sz(vs) > 1);
	
	for (int v : vs) {
		col[v] = 0;
	}

	// eprintf("vs:\n");
	// for (int v : vs) {
	// 	eprintf("%d ", v + 1);
	// }
	// eprintf("\n");

	for (int v : vs) {
		if  (!col[v]) {
			if  (dfs_cycle(v)) {
				return 2;
			}
		}
	}

	int root = -1;
	for (int v : vs) {
		if  (g[v].empty()) {
			root = v;
		}
	}

	assert(root != -1);

	dfs_dp(root);

	return dp[1][root];
}

int solve() {
	int ans = 1;
	vi was(2 * n);
	forn(v, 2 * n) {
		if  (!was[v] && !g[v].empty()) {
			vi vs;
			dfs0(v, was, vs);
			ans = mul(ans, solve(vs));
		}
	}
	return ans;
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