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

const int MAXN = 80 + 10;
const int INF = 1e9;

int n, k;
int m;
int cost[MAXN][MAXN];

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return 0;
	}
	scanf("%d", &m);
	forn(i, n) forn(j, n) {
		cost[i][j] = INF;
	}
	forn(i, m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		if  (a != b) {
			cost[a][b] = min(cost[a][b], c);
		}
	}
	return 1;
}

void remin(int& x, int y) {
	if  (x > y) {
		x = y;
	}
}

int dp[MAXN][MAXN][MAXN][2];

void remin(int l, int r, int was, int end, int nw) {
	if  (l > r) {
		return;
	}
	remin(dp[l][r][was][end], nw);
}

int solve() {
	forn(l, n) forn(r, n) forn(was, k + 1) forn(end, 2) {
		dp[l][r][was][end] = INF;
	}

	if  (k == 1) {
		return 0;
	}

	int ans = INF;
	forn(v, n) forn(to, n) {
		int C = cost[v][to];
		if  (C >= INF) {
			continue;
		}
		if  (k == 2) {
			remin(ans, C);
		}
		assert(v != to);
		if  (v < to) {
			remin(v + 1, to - 1, 1, 1, C);
			remin(to + 1, n - 1, 1, 0, C);
		} else {
			remin(to + 1, v - 1, 1, 0, C);
			remin(0, to - 1, 1, 1, C);
		}
	}

	for (int was = 1; was <= k; ++was) {
		forn(end, 2) forn(l, n) for (int r = l; r < n; ++r) {
			int cur_dp = dp[l][r][was][end];
			if  (cur_dp >= INF) {
				continue;
			}

			// printf("dp[l=%d][r=%d][was=%d][end=%d] -> %d\n", l, r, was, end, cur_dp);

			int from = end ? r + 1 : l - 1;
			assert(from >= 0);
			assert(from < n);
			for (int m = l; m <= r; ++m) {
				int nw = cur_dp + cost[from][m];
				if  (nw >= INF) {
					continue;
				}
				remin(l, m - 1, was + 1, 1, nw);
				remin(m + 1, r, was + 1, 0, nw);

				if  (was + 1 == k - 1) {
					remin(ans, nw);
				}
			}
		}
	}

	return ans >= INF ? -1 : ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		cout << solve() << endl;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}