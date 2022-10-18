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

int n, m;
vvi g;
int k, x;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	g.clear();
	g.resize(n);
	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	scanf("%d%d", &k, &x);
	return 1;
}

vector<vvi> dp;

void dfs(int v, int p) {
	vector<vvi> cur_dp(3, vvi(x + 1, vi(2, 0)));
	cur_dp[0][0][0] = 1;

	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}

		dfs(to, v);

		vector<vvi> new_cur_dp(3, vvi(x + 1, vi(2, 0)));
		forn(was_c, 3) {
			forn(was_cnt, x + 1) {
				forn(was_k, 2) {
					const int cur_coef = cur_dp[was_c][was_cnt][was_k];
					if  (!cur_coef) {
						continue;
					}

					forn(cur_c, 3) {
						forn(cur_cnt, x + 1 - was_cnt) {
							add(new_cur_dp[max(was_c, cur_c)][was_cnt + cur_cnt][was_k || cur_c == 1], mul(cur_coef, dp[to][cur_c][cur_cnt]));
						}
					}
				}
			}
		}

		cur_dp.swap(new_cur_dp);
	}

	forn(cnt, x + 1) {
		// < k
		forn(max_c, 3) {
			forn(was_k, 2) {
				add(dp[v][0][cnt], mul(cur_dp[max_c][cnt][was_k], k - 1));
			}
		}

		// == k
		if  (cnt + 1 <= x) {
			add(dp[v][1][cnt + 1], cur_dp[0][cnt][0]);
		}

		// > k
		forn(max_c, 3) {
			add(dp[v][2][cnt], mul(cur_dp[max_c][cnt][0], m - k));
		}
	}
}

int solve() {
	dp.assign(n, vvi(3, vi(x + 1, 0)));

	const int r = 0;
	dfs(r, r);

	int ans = 0;
	forn(c, 3) {
		forn(cnt, x + 1) {
			add(ans, dp[r][c][cnt]);
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