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

const int MAXN = 75 + 10;
const int INF = 1e9;

int n;
int a[MAXN];

bool read() {
	if  (scanf("%d\n", &n) < 1) {
		return 0;
	}
	static char s[MAXN];
	scanf("%s\n", s);
	assert(n == (int) strlen(s));
	forn(i, n) {
		if  (s[i] == 'V') {
			a[i] = 0;
		} else if  (s[i] == 'K') {
			a[i] = 1;
		} else {
			a[i] = 2;
		}
	}
	return 1;
}

int dp[3][MAXN][MAXN][MAXN];
int cnt[3][MAXN];
vi pos[3];

void precalc() {
	forn(c, 3) {
		forn(i, n) {
			if  (i > 0) {
				cnt[c][i] = cnt[c][i - 1];
			}
			if  (a[i] == c) {
				++cnt[c][i];
			}
		}
	}

	forn(c, 3) {
		pos[c].clear();
	}
	forn(i, n) {
		pos[a[i]].pb(i);
	}
}

void remin(int& x, int y) {
	if  (x > y) {
		x = y;
	}
}

int solve() {
	precalc();


	forn(c, 3) forn(i, MAXN) forn(j, MAXN) forn(k, MAXN) dp[c][i][j][k] = INF;
	dp[1][0][0][0] = 0;

	for (int len = 0; len < n; ++len) {
		forn(last, 3) forn(c0, len + 1) forn(c1, len + 1 - c0) {
			int c2 = len - (c0 + c1);
			assert(c2 >= 0);
			int cur_dp = dp[last][c0][c1][c2];
			if  (cur_dp >= INF) {
				continue;
			}

			// printf("len=%d, last=%d, c0=%d, c1=%d, c2=%d -> %d\n", len, last, c0, c1, c2, cur_dp);

			static int was[3];
			was[0] = c0;
			was[1] = c1;
			was[2] = c2;

			forn(next, 3) {
				if  (last == 0 && next == 1) {
					continue;
				}
				if  (was[next] == sz(pos[next])) {
					continue;
				}
				int pos_next = pos[next][was[next]];
				int aux = 0;
				forn(other, 3) {
					if  (other != next) {
						aux += max(0, cnt[other][pos_next] - was[other]);
					}
				}

				++was[next];
				remin(dp[next][was[0]][was[1]][was[2]], cur_dp + aux);
				--was[next];
			}
		}
	}

	int ans = INF;
	forn(last, 3) {
		remin(ans, dp[last][sz(pos[0])][sz(pos[1])][sz(pos[2])]);
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