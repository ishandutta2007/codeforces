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

const int MAXN = 4e3 + 10;
const int INF = 2e9;

int n;
int a[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return 1;
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

int pref[MAXN];
int suff[MAXN];

void precalc() {
	pref[0] = 0;
	forn(i, n) {
		pref[i + 1] = pref[i] + a[i];
	}

	suff[n] = 0;
	ford(i, n) {
		suff[i] = suff[i + 1] + a[i];
	}
}

const int MAXK = 95;
const int MAX_DIFF = 100;
const int M = 100;

int dp[M][MAX_DIFF * 2][MAXK][2];

int solve() {
	precalc();

	for (int left = n; left >= 0; --left) {
		for (int diff = -MAX_DIFF; diff < MAX_DIFF; ++diff) {
			int right = left - diff;
			if  (left + right > n || right < 0) {
				continue;
			}
			for (int k = 1; k < MAXK; ++k) {
				forn(w, 2) {
					int& cur_dp = dp[left % M][MAX_DIFF + diff][k][w];
					if  (k > n - left - right) {
						cur_dp = pref[left] - suff[n - right];
						// printf("dp[left=%d][right=%d][k=%d][who=%d] = %d\n", left, left - diff, k, w, cur_dp);
						continue;
					}
					if  (w == 0) {
						cur_dp = -INF;
						for (int nk = k; nk <= k + 1; ++nk) {
							int ndiff = diff + nk;
							if  (ndiff < MAX_DIFF && n - left - right >= nk) {
								remax(cur_dp, dp[(left + nk) % M][MAX_DIFF + ndiff][nk][1]);
							}
						}
					} else {
						cur_dp = INF;
						for (int nk = k; nk <= k + 1; ++nk) {
							int ndiff = diff - nk;
							if  (ndiff >= -MAX_DIFF && n - left - right >= nk) {
								remin(cur_dp, dp[left % M][MAX_DIFF + ndiff][nk][0]);
							}
						}
					}
					// printf("dp[left=%d][right=%d][k=%d][who=%d] = %d\n", left, left - diff, k, w, cur_dp);
				}
			}
		}
	}

	return dp[0][MAX_DIFF][1][0];
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