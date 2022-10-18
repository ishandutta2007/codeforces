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
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
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

const int MAXN = 100 + 10;
const int MAXK = 20 + 3;
const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int n, k;
vi g[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return 0;
	}
	forn(i, n) {
		g[i].clear();
	}
	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	return 1;
}

int dp[MAXN][MAXK+1][MAXK+1];
int ndp[MAXK+1][MAXK+1];

void dfs(int v, int p) {
	for (int to : g[v]) {
		if  (to != p) {
			dfs(to, v);
		}
	}

	memset (dp[v], 0, sizeof dp[v]);
	dp[v][0][MAXK] = 1;
	dp[v][MAXK][0] = 1;
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		memset (ndp, 0, sizeof ndp);
		forn(d_w, MAXK + 1) forn(d_b, MAXK + 1) {
			int cur = dp[v][d_w][d_b];
			if  (!cur) {
				continue;
			}
			forn(c_d_w, MAXK + 1) forn(c_d_b, MAXK + 1) {
				int dp_to = dp[to][c_d_w][c_d_b];
				if  (!dp_to) {
					continue;
				}
				if  (c_d_w != MAXK && c_d_w + 1 > k) {
					continue;
				}
				int n_d_b = min(d_b, c_d_b + 1);
				int n_d_w = -1;
				if  (d_w + 1 + c_d_b > k && d_w < MAXK) {
					n_d_w = max(n_d_w, d_w);
				}
				if  (c_d_w + 1 + d_b > k && c_d_w < MAXK) {
					n_d_w = max(n_d_w, c_d_w + 1);
				}
				if  (n_d_w > k) {
					continue;
				}
				if  (n_d_w == -1) {
					n_d_w = MAXK;
				}
				add(ndp[n_d_w][n_d_b], mul(dp_to, cur));
			}
		}
		memcpy(dp[v], ndp, sizeof ndp);
	}

	// forn(d_w, MAXK+1) forn(d_b, MAXK+1) {
	// 	int c = dp[v][d_w][d_b];
	// 	if  (c) {
	// 		printf("dp[v=%d][d_w=%d][d_b=%d] = %d\n", v, d_w, d_b, c);
	// 	}
	// }
}

int solve() {
	dfs(0, -1);

	int ans = 0;
	forn(d_b, MAXK+1) {
		add(ans, dp[0][MAXK][d_b]);
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