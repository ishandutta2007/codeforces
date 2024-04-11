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
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const int MAXN = 1e3 + 10;
const int MAXD = 15;

int n, d, MOD;
int phi;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

bool read() {
	if  (scanf("%d%d%d", &n, &d, &MOD) < 3) {
		return false;
	}
	return true;
}

int dp[MAXD][MAXN][MAXN];

int mpow(int a, int p) {
	int res = 1;
	for (; p > 0; a = mul(a, a), p >>= 1) {
		if  (p & 1) {
			res = mul(res, a);
		}
	}
	return res;
}

int inv[MAXD];

void precalc() {
	for (int i = 1; i < MAXD; ++i) {
		inv[i] = mpow(i, MOD - 2);
		assert(mul(i, inv[i]) == 1);
	}
}

int solve() {
	if  (n <= 2) {
		return 1;
	}

	int ans = 0;

	memset (dp, 0, sizeof dp);
	forn(last, n + 1) {
		dp[0][0][last] = 1;
	}
	for (int sum = 0; sum <= n; ++sum) {
		for (int sons = 1; sons <= d; ++sons) {
			for (int cur = 1; cur <= n; ++cur) {
				add(dp[sons][sum][cur], dp[sons][sum][cur - 1]);
				if  (cur * 2 > n) {
					continue;
				}
				int A = cur == 1 ? 1 : dp[d - 1][cur - 1][n];
				int B = 1;
				int C = A / B;
				for (int cnt_cur = 1; sum - cnt_cur * cur >= 0 && sons - cnt_cur >= 0; ++cnt_cur) {
					int aux = mul(dp[sons - cnt_cur][sum - cnt_cur * cur][cur - 1], C);
					add(dp[sons][sum][cur], aux);
					if  (sons == d && sum == n - 1) {
						if  ((n - cur) * 2 > n) {
							add(ans, aux);
						}
					}
					add(A, 1);
					add(B, 1);
					C = mul(C, A);
					C = mul(C, inv[B]);
				}
			}
		}
	}

	for (int left = d - 1; left <= n - 2; ++left) {
		int right = n - 2 - left;
		if  (right < d - 1 || left > right) {
			continue;
		} 
		if  ((left + 1) * 2 > n || (right + 1) * 2 > n) {
			continue;
		}
		int cur_ans = mul(dp[d - 1][left][n], dp[d - 1][right][n]);
		if  (left == right) {
			cur_ans = mul(dp[d - 1][left][n], dp[d - 1][left][n] + 1);
			cur_ans = mul(cur_ans, inv[2]);
		}
		add(ans, cur_ans);
	}

	// forn(i, d + 1) forn(j, n + 1) forn(k, n + 1) {
	// 	int d = dp[i][j][k];
	// 	if  (!d) {
	// 		continue;
	// 	}
	// 	printf("dp[sons=%d][sum=%d][upper=%d] = %d\n", i, j, k, d);
	// }

	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		precalc();
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}