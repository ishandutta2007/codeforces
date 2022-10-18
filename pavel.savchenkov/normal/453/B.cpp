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

int n;
vi a;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return 1;
}

bool isPrime(int n) {
	if  (n == 1) {
		return 0;
	}
	for (int d = 2; d * d <= n; ++d) {
		if  (n % d == 0) {
			return 0;
		}
	}
	return 1;
}

const int MAX = 58;

int repr[MAX + 1];
vi ps;

void precalc() {
	ps.clear();
	for (int p = 2; p <= MAX; ++p) {
		if  (isPrime(p)) {
			ps.pb(p);
		}
	}

	memset (repr, 0, sizeof repr);
	for (int x = 2; x <= MAX; ++x) {
		int num = x;
		forn(i, sz(ps)) {
			if  (num % ps[i] == 0) {
				repr[x] ^= 1 << i;
			}
			while (num % ps[i] == 0) {
				num /= ps[i];
			}
		}
		assert(num == 1);
	}
}

const int S = 16;
const int INF = 1e9;
const int MAXN = 100 + 5;

int dp[MAXN][1 << S];
int prev[MAXN][1 << S];

void solve() {
	assert(sz(ps) <= S);

	forn(i, n + 1) {
		forn(mask, 1 << sz(ps)) {
			dp[i][mask] = INF;
		}
	}

	dp[0][0] = 0;
	forn(i, n) {
		forn(mask, 1 << sz(ps)) {
			const int cur_dp = dp[i][mask];
			if  (cur_dp >= INF) {
				continue;
			}
			for (int nxt = 1; nxt <= MAX; ++nxt) {
				if  (mask & repr[nxt]) {
					continue;
				}
				const int nmask = mask ^ repr[nxt];
				const int new_dp = cur_dp + abs(a[i] - nxt);
				if  (new_dp < dp[i + 1][nmask]) {
					dp[i + 1][nmask] = new_dp;
					prev[i + 1][nmask] = nxt;
				}
			}
		} 
	}

	int ans = INF;
	int best_mask = 0;
	forn(mask, 1 << sz(ps)) {
		if  (dp[n][mask] < ans) {
			ans = dp[n][mask];
			best_mask = mask;
		}
	}

	vi b(n, -1);
	int mask = best_mask;
	ford(i, n) {
		b[i] = prev[i + 1][mask];
		int prev_mask = mask ^ repr[b[i]];
		mask = prev_mask;
	}

	forn(i, n) {
		printf("%d ", b[i]);
	}
	printf("\n");
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		solve();
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}