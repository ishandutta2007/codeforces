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

const int MAXN = 150 + 10;

void remax(int& x, int y) {
	if  (x < y) {
		x = y;
	}
}

int n;
char s[MAXN];
int a[MAXN];

bool read() {
	if  (scanf("%d\n", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		scanf("%d", &a[i + 1]);
	}
	scanf("\n");
	scanf("%s\n", s);
	assert((int) strlen(s) == n);
	return 1;
}

int dp[MAXN][MAXN];
int dp_pal[MAXN][MAXN][MAXN];
int dp_full[MAXN][MAXN];

int solve() {
	// puts(s);

	memset (dp, 0, sizeof dp);
	memset (dp_full, -1, sizeof dp_full);
	memset (dp_pal, -1, sizeof dp_pal);

	for (int len = 1; len <= n; ++len) {
		forn(l, n - len + 1) {
			int r = l + len - 1;
			assert(r < n);

			// dp_full
			{
				#define cur_dp dp_full[l][r]
				for (int m = l; m < r; ++m) {
					if  (dp_full[l][m] != -1 && dp_full[m + 1][r] != -1) {
						remax(cur_dp, dp_full[l][m] + dp_full[m + 1][r]);
					}
				}

				if  (s[l] == s[r]) {
					if  (len <= 2) {
						remax(cur_dp, a[len]);
					} else {
						remax(cur_dp, dp_pal[l + 1][r - 1][2]);
					}
				}
				#undef cur_dp
			}

			// dp
			{
				#define cur_dp dp[l][r]
				for (int m = l; m < r; ++m) {
					remax(cur_dp, dp[l][m] + dp[m + 1][r]);
				}

				remax(cur_dp, dp_full[l][r]);
				#undef cur_dp
			}

			// dp_pal
			{
				for (int out = 2; out <= n - len; out += 2) {
					#define cur_dp dp_pal[l][r][out]
					if  (dp_full[l][r] != -1 && a[out] != -1) {
						remax(cur_dp, dp_full[l][r] + a[out]);
					}
					for (int m = l; m < r; ++m) {
						if (dp_pal[l][m][out] != -1 && dp_full[m + 1][r] != -1) {
							remax(cur_dp, dp_pal[l][m][out] + dp_full[m + 1][r]);
						}
					}
					for (int m = l + 1; m <= r; ++m) {
						if  (dp_full[l][m - 1] != -1 && dp_pal[m][r][out] != -1) {
							remax(cur_dp, dp_full[l][m - 1] + dp_pal[m][r][out]);
						}
					}
					if  (s[l] == s[r]) {
						if  (len <= 2) {
							remax(cur_dp, a[out + len]);
						} else {
							remax(cur_dp, dp_pal[l + 1][r - 1][out + 2]);
						}
					}
					#undef cur_dp
				}
			}

			// printf("dp_full[%d, %d] = %d\n", l, r, dp_full[l][r]);
		}
	}

	return dp[0][n - 1];
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