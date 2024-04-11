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

#define FILE_NAME "a"


int n, b;
vvi g;
vi par;
vi c;
vi d;

bool read() {
	if  (scanf("%d%d", &n, &b) < 2) {
		return 0;
	}
	g.clear();
	g.resize(n);
	par.assign(n, -1);
	c.resize(n);
	d.resize(n);
	forn(i, n) {
		scanf("%d%d", &c[i], &d[i]);
		if  (i > 0) {
			scanf("%d", &par[i]);
			--par[i];
			g[par[i]].pb(i);
		}
	}
	return 1;
}

const int INF = 1e9 + 100;

int add(int x, int y) {
	if  (x >= INF || y >= INF) {
		return INF;
	}
	return min(x + y, INF);
}

void remin(int& x, int y) {
	if  (x > y) {
		x = y;
	}
}

void remax(int& x, int y) {
	if  (x < y) {
		x = y;
	}
}

void norm(vi& dyn) {
	while (!dyn.empty() && dyn.back() >= INF) {
		dyn.pop_back();
	}
	ford(i, sz(dyn) - 1) {
		remin(dyn[i], dyn[i + 1]);
	}
}

vi merge(const vi& dp1, const vi& dp2) {
	assert(dp1.at(0) == 0);
	assert(dp2.at(0) == 0);
	vi dp(sz(dp1) + sz(dp2), INF);
	forn(i, sz(dp1)) forn(j, sz(dp2)) {
		remin(dp[i + j], add(dp1[i], dp2[j]));
	}
	norm(dp);
	return dp;
}

vector<vvi> dp;

void dfs(int v) {
	for (int to : g[v]) {
		dfs(to);
	}

	vi use(1, 0);
	for (int to : g[v]) {
		use = merge(dp[to][1], use);
	}

	vi not_use(1, 0);
	for (int to : g[v]) {
		not_use = merge(dp[to][0], not_use);
	}

	const int sz = max(sz(not_use), sz(use));

	dp[v].resize(2);
	
	// 0
	dp[v][0].assign(sz + 1, INF);
	forn(i, sz(not_use)) {
		remin(dp[v][0][i + 1], add(not_use[i], c[v]));
	}
	forn(i, sz(not_use)) {
		remin(dp[v][0][i], not_use[i]);
	}
	norm(dp[v][0]);

	// 1
	dp[v][1].assign(sz + 1, INF);
	forn(i, sz(use)) {
		remin(dp[v][1][i + 1], add(use[i], c[v] - d[v]));
	}
	forn(i, sz(not_use)) {
		remin(dp[v][1][i], not_use[i]);
	}
	norm(dp[v][1]);

	// printf("v=%d\n", v);
	// forn(c, 2) {
	// 	printf("was_par=%d\n", c);
	// 	forn(i, sz(dp[v][c])) {
	// 		printf("i=%d, dp=%d\n", i, dp[v][c][i]);
	// 	}
	// }
	// puts("--");
}

int solve() {
	dp.clear();
	dp.resize(n);

	const int r = 0;
	dfs(r);

	int res = 0;
	forn(i, sz(dp[r][1])) {
		if  (dp[r][1][i] <= b) {
			res = i;
		}
	}
	return res;
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