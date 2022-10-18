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

const int MAXN = 1e3 + 10;

int n, k;
bool have[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return 0;
	}
	memset (have, 0, sizeof have);
	forn(i, k) {
		int a;
		scanf("%d", &a);
		have[a] = 1;
	}
	return 1;
}

const int INF = 1e9;

int dp[2][MAXN * MAXN];

void remin(int& x, int y) {
	if  (x > y) {
		x = y;
	}
}

void calc(int c, const vi& a) {
	int* d = dp[c];
	forn(i, MAXN * MAXN) {
		dp[c][i] = INF;
	}
	d[0] = 0;
	for (const auto& x : a) {
		// printf("x=%d\n", x);
		for (int i = x; i < MAXN * MAXN; ++i) {
			remin(d[i], d[i - x] + 1);
		}
	}
}

int solve() {
	forn(i, MAXN) {
		if  (have[i] && i == n) {
			return 1;
		}
	}
	forn(i, MAXN) {
		if  (have[i] && n + (n - i) < MAXN && have[n + (n - i)]) {
			return 2;
		}
	}

	vi left;
	vi right;
	forn(i, MAXN) {
		if  (!have[i]) {
			continue;
		}
		if  (i - n < 0) {
			left.pb(n - i);
		}
		if  (i - n > 0) {
			right.pb(i - n);
		}
	}

	calc(0, left);
	calc(1, right);

	int ans = INF;
	forn(i, MAXN * MAXN) {
		if  (i && dp[0][i] + dp[1][i] < ans) {
			ans = dp[0][i] + dp[1][i];
			// printf("i=%d, ans=%d\n", i, ans);
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