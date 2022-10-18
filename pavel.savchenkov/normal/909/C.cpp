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
const int MAXN = 5e3 + 10;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

vi isLoop;
int n;

bool read() {
	if  (scanf("%d\n", &n) < 1) {
		return 0;
	}
	isLoop.resize(n);
	forn(i, n) {
		char ch;
		scanf("%c\n", &ch);
		if  (ch == 'f') {
			isLoop[i] = 1;
		} else if  (ch == 's') {
			isLoop[i] = 0;
		} else {
			assert(0);
		}
	} 
	return 1;
}

int dp[MAXN][MAXN];

int solve() {
	memset (dp, 0, sizeof dp);

	dp[0][0] = 1;

	static int pref[MAXN];
	forn(i, n) {
		memset (pref, 0, sizeof pref);
		const bool loopPar = i > 0 && isLoop[i - 1];
		forn(par, i + 1) {
			const int cur_dp = dp[i][par];
			if  (loopPar) {
				add(dp[i + 1][par + 1], cur_dp);
			} else {
				add(pref[par], cur_dp);
			}
		}

		int sum = 0;
		ford(par, n + 1) {
			add(sum, pref[par]);
			add(dp[i + 1][par], sum);
		}
	}

	int ans = 0;
	forn(par, n + 1) {
		add(ans, dp[n][par]);
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
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}