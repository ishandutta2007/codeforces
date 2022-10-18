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

vi n;
int k;

bool read() {
	string s;
	if  (!getline(cin, s)) {
		return 0;
	}
	scanf("%d\n", &k);
	n.resize(sz(s));
	forn(i, sz(s)) {
		n[i] = s[i] - '0';
	}
	return 1;
}

const int MAXN = 1e3 + 10;

int to_1[MAXN];

int pop1(int i) {
	int ans = 0;
	while (i) {
		ans += i & 1;
		i /= 2;
	}
	return ans;
}

void precalc() {
	to_1[0] = -1;
	to_1[1] = 0;
	for (int i = 2; i < MAXN; ++i) {
		int cnt = pop1(i);
		to_1[i] = to_1[cnt] + 1;
	}
}

int dp[2][MAXN][MAXN];

int solve() {
	if  (k == 0) {
		return 1;
	}

	memset (dp, 0, sizeof dp);
	dp[0][0][0] = 1;
	forn(i, sz(n)) {
		forn(ls, 2) {
			forn(cnt, i + 1) {
				const int cur_dp = dp[ls][i][cnt];
				if  (!cur_dp) {
					continue;
				}
				forn(cur, 2) {
					if  (!ls && cur > n[i]) {
						continue;
					}
					const int nls = ls | (cur < n[i]);
					const int ncnt = cnt + cur;
					add(dp[nls][i + 1][ncnt], cur_dp);
				}
			}
		}
	}

	int ans = 0;
	forn(cnt, sz(n) + 1) {
		int cur = 0;
		forn(ls, 2) {
			add(cur, dp[ls][sz(n)][cnt]);
		}

		int moves = to_1[cnt] + 1;
		if  (cnt == 1) {
			add(cur, -1 + MOD);
		}

		// eprintf("moves=%d, cur=%d\n", moves, cur);

		if  (moves == k) {
			add(ans, cur);
		}
	}

	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}