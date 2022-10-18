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
const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int n;
int s[MAXN];

bool read() {
	// n = 75;
	// forn(i, n) {
	// 	s[i] = rand() & 1;
	// }
	// return 1;

	if  (scanf("%d\n", &n) < 1) {
		return 0;
	}
	static char t[MAXN];
	scanf("%s\n", t);
	forn(i, n) {
		s[i] = (t[i] == '1');
	}
	return 1;
}

const int B = 20;

int dp[MAXN][1 << B];
bool good[1 << B];

int solve() {
	memset (good, 0, sizeof good);
	for (int m = 1; m <= B; ++m) {
		int mask = 0;
		ford(i, m) {
			mask |= 1 << i;
		}
		good[mask] = 1;
	}

	memset (dp, 0, sizeof dp);
	dp[0][0] = 1;
	int ans = 0;
	forn(i, n + 1) forn(mask, 1 << B) {
		int cur_dp = dp[i][mask];

		if  (!mask) {
			add(dp[i + 1][0], cur_dp);
		}

		if  (good[mask]) {
			add(ans, cur_dp);
		}

		int num = 0;
		for (int j = i; j < n; ++j) {
			num = num * 2 + s[j];
			if  (num > B) {
				break;
			}
			if  (!num) {
				continue;
			}
			int nmask = mask | (1 << (num - 1));
			add(dp[j + 1][nmask], cur_dp);
		}
	}

	return ans;
}

int len2(int x) {
	int len = 0;
	while (x) {
		++len;
		x /= 2;
	}
	return max(len, 1);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	// int s = 0;
	// for (int i = 1; i <= 100; ++i) {
	// 	s += len2(i);
	// 	printf("i=%d, len=%d, len2=%d\n", i, s, len2(i));
	// }
	// return 0;


	while (read()) {
		printf("%d\n", solve());

		// break;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}