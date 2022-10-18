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

int n, s, m;
vector<vii> g;
vi cnt_node;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	g.clear();
	g.resize(n);
	forn(i, n - 1) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		--a;
		--b;
		g[a].pb(mp(b, w));
		g[b].pb(mp(a, w));
	}
	scanf("%d", &s);
	--s;
	cnt_node.assign(n, 0);

	scanf("%d", &m);
	forn(i, m) {
		int x;
		scanf("%d", &x);
		--x;
		++cnt_node[x];
	} 
	return 1;
}

vvi dp;

void dfs0(int v, int p, int len, int k, vvi& vals) {
	if  (p != -1 && sz(g[v]) == 1) {
		for (int take = 1; take < sz(vals[v]); ++take) {
			if  (dp[v][k - take] != -1) {
				vals[v][take] = len + dp[v][k - take];
			}
		}
	}

	for (const auto& e : g[v]) {
		int to, w;
		tie(to, w) = e;
		if  (to == p) {
			continue;
		}
		dfs0(to, v, len + w, k, vals);
	}
}

int dfs_sum(int v, int p) {
	int sum = cnt_node[v];
	for (const auto& e : g[v]) {
		int to, w;
		tie(to, w) = e;
		if  (to == p) {
			continue;
		}
		sum += dfs_sum(to, v);
	}
	return sum;
}

void remax(int& x, int y) {
	if  (x < y) {
		x = y;
	}
}

int calc_knapsack(const vvi& vals, int k) {
	if  (k == 0) {
		return 0;
	}

	// min -> max
	vi dyn(k + 1, -1);
	forn(v, sz(vals)) {
		vi ndyn(k + 1, -1);
		for (int got = 0; got <= k; ++got) {
			int got_dp = dyn[got];
			remax(ndyn[got], got_dp);
			for (int take = 1; take <= got; ++take) {
				const auto cur_val = vals[v][take];
				if  (cur_val == -1) {
					continue;
				}
				int ndp = got == k ? cur_val : min(got_dp, cur_val);
				if  (ndp == -1) {
					continue;
				}
				remax(ndyn[got - take], ndp);
			}
		}
		dyn.swap(ndyn);
	}
	assert(dyn[0] != -1);
	return dyn[0];
}

void calc_layer(int k) {
	forn(v, n) {
		vvi vals(n, vi(k + 1, -1));
		dfs0(v, -1, 0, k, vals);
	
		// eprintf("v=%d, k=%d, vals:\n", v + 1, k);
		// forn(u, n) {
		// 	forn(take, k + 1) {
		// 		const int val = vals[u][take];
		// 		if (val == -1) {
		// 			continue;
		// 		}
		// 		eprintf("vals[u=%d][take=%d] = %d\n", u + 1, take, val);
		// 	}
		// }

		dp[v][k] = calc_knapsack(vals, k);

		// eprintf("dp[v=%d][k=%d] = %d\n", v + 1, k, dp[v][k]);
	}
}

const int INF = 1e9;

int solve() {
	// if  (n == 1) {
	// 	return 0;
	// }

	dp.assign(n, vi(m + 1, -1));

	forn(v, n) {
		dp[v][0] = 0;
	}

	for (int k = 1; k <= m; ++k) {
		calc_layer(k);
	}

	int ans = INF;
	for (const auto& e : g[s]) {
		int to, w;
		tie(to, w) = e;

		vvi vals(n, vi(m + 1, -1));
		dfs0(to, s, w, m, vals);

		int cur_sum = dfs_sum(to, s);

		if  (cur_sum == 0) {
			continue;
		}
		
		// eprintf("cur_sum = %d, final vals:\n", cur_sum);
		// forn(u, n) {
		// 	forn(take, m + 1) {
		// 		const int val = vals[u][take];
		// 		if (val == -1) {
		// 			continue;
		// 		}
		// 		eprintf("vals[u=%d][take=%d] = %d\n", u + 1, take, val);
		// 	}
		// }

		int cur_dp = calc_knapsack(vals, cur_sum);
		ans = min(ans, cur_dp);
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