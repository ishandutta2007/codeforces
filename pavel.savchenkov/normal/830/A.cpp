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

const ll INF = 1e18;

int n, k, p;
vi a;
vi b;

bool read() {
	if  (scanf("%d%d%d", &n, &k, &p) < 3) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	b.resize(k);
	forn(i, k) {
		scanf("%d", &b[i]);
	}
	return 1;
}

void remin(ll& x, ll y) {
	if  (x > y) {
		x = y;
	}
}

ll take(int i, int j) {
	return abs(a[i] - b[j]) + 1ll * abs(b[j] - p);
}

ll solve() {
	sort(all(a));
	sort(all(b));

	ll ans = INF;
	vector<vll> dp(n + 1, vll(k + 1, INF));
	dp[0][0] = 0;
	forn(i, n + 1) forn(j, k + 1) {
		const ll cur_dp = dp[i][j];
		if  (cur_dp >= INF) {
			continue;
		}
		if  (i == n) {
			remin(ans, cur_dp);
			continue;
		}
		if  (j == k) {
			continue;
		}
		remin(dp[i + 1][j + 1], max(cur_dp, take(i, j)));
		remin(dp[i][j + 1], cur_dp);
	}
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%lld\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}