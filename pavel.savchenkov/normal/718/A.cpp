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

const int MAXN = 2e5 + 10;
const int INF = 2e9;

int n, t;
char s[MAXN];

bool read() {
	if  (scanf("%d%d\n", &n, &t) < 2) {
		return false;
	}
	gets(s);
	return true;
}

int p;

void precalc() {
	forn(i, n) {
		if  (s[i] == '.') {
			for (int j = i; j + 1 < n; ++j) {
				s[j] = s[j + 1];
			}
			p = i;
			--n;
			return;
		}
	}
	assert(false);
}

int dp[MAXN][11];

void restore_max(int i, int have, vi& res) {
	if  (i == n) {
		return;
	}
	int c = s[i] - '0';
	int D = dp[i][c + 1];
	if  (D <= have) {
		if  (i >= p - 1) {
			for (int nd = 5; nd < 10; ++nd) {
				if  (D == dp[i + 1][nd] + 1) {
					restore_max(i + 1, have - 1, res);
					res.clear();
					res.pb(c + 1);
					return;
				}
			}
		}
		assert(dp[i][c + 1] == dp[i + 1][10]);
		restore_max(i + 1, have, res);
		if  (res.back() == 10) {
			res.back() = 0;
		}
		res.pb(c + 1);
		return;
	}
	restore_max(i + 1, have, res);
	res.pb(c);
}

void solve() {
	precalc();

	forn(i, n + 1) forn(d, 11) dp[i][d] = INF;
	dp[n][0] = 0;
	ford(i, n) forn(d, 11) {
		int c = s[i] - '0';
		if  (d == c) {
			dp[i][d] = 0;
			continue;
		}
		if  (d == c + 1) {
			if  (i >= p - 1) {
				for (int nd = 5; nd < 10; ++nd) {
					dp[i][d] = min(dp[i][d], dp[i + 1][nd] + 1);
				}
			}
			if  (dp[i + 1][10] < INF) {
				dp[i][d] = min(dp[i][d], dp[i + 1][10]);
			}
		}
	}

	vi res;
	restore_max(0, t, res);
	
	assert(!res.empty());
	if  (res.back() == 10) {
		res.back() = 0;
		res.pb(1);
		++p;
	}
	reverse(all(res));
	forn(i, sz(res)) {
		if  (i == p) {
			printf(".");
		}
		printf("%d", res[i]);
	}
	puts("");
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}