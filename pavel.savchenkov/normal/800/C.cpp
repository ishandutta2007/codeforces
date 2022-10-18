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

const int MAXN = 2e5 + 10;

int n, m;
bool is_bad[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	memset (is_bad, 0, sizeof is_bad);
	forn(i, n) {
		int x;
		scanf("%d", &x);
		is_bad[x] = 1;
	}
	return 1;
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int gcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}

	int xx, yy;
	int g = gcd(b, a % b, xx, yy);
	x = yy;
	y = xx - (a / b) * yy;

	assert(a * x + b * y == g);
	return g;
}

int mul(int x, int y) {
	return x * 1ll * y % m;
}

vi divs[MAXN];

void precalc() {
	for (int i = 1; i < MAXN; ++i) {
		for (int j = i; j < MAXN; j += i) {
			divs[j].pb(i);
		}
	}
}

int gcd_m[MAXN];
int cnt_gcd[MAXN];

int dp[MAXN];
int prev[MAXN];

bool good_g[MAXN];

int go_to(int a, int b) {
	assert(b % gcd_m[a] == 0);
	int x, y;
	int g = gcd(a, m, x, y);
	x = (x % m + m) % m;
	assert(g == gcd_m[g]);
	// printf("a=%d, x=%d, g=%d, m=%d\n", a, x, g, m);
	assert(mul(a, x) == g);
	x = mul(x, b / g);
	assert(mul(a, x) == b);
	return x;
}

void solve() {
	forn(i, m) {
		gcd_m[i] = gcd(i, m);
	}

	memset (cnt_gcd, 0, sizeof cnt_gcd);
	for (int i = 1; i < m; ++i) {
		if  (!is_bad[i]) {
			int g = gcd_m[i];
			++cnt_gcd[g];
		}
	}

	memset (dp, -1, sizeof dp);
	memset (prev, -1, sizeof prev);
	int best_g = -1;
	for (int g = 1; g < m; ++g) {
		dp[g] = cnt_gcd[g];
		prev[g] = -1;

		for (int d : divs[g]) {
			if  (d == g) {
				continue;
			}

			if  (dp[g] < cnt_gcd[g] + dp[d]) {
				dp[g] = cnt_gcd[g] + dp[d];
				prev[g] = d;
			}
		}

		if  (best_g == -1 || dp[g] > dp[best_g]) {
			best_g = g;
		}
	}

	memset (good_g, 0, sizeof good_g);
	vi gs;
	int g = best_g;
	while (g != -1) {
		good_g[g] = 1;
		g = prev[g];
	}
	reverse(all(gs));

	vi prefs;
	for (int i = 1; i < m; ++i) {
		if  (!is_bad[i]) {
			int g = gcd_m[i];
			if  (good_g[g]) {
				prefs.pb(i);
			}
		}
	}

	sort(all(prefs), [&](int a, int b) { return gcd_m[a] < gcd_m[b]; });

	// printf("prefs:\n");
	// for (int x : prefs) {
	// 	printf("%d ", x);
	// }
	// puts("");

	vi ans;
	if  (!prefs.empty()) {
		ans.pb(prefs[0]);
		for (int i = 1; i < sz(prefs); ++i) {
			ans.pb(go_to(prefs[i - 1], prefs[i]));
		}
	}
	
	if  (!is_bad[0]) {
		ans.pb(0);
	}

	printf("%d\n", sz(ans));
	for (int x : ans) {
		printf("%d ", x);
	}
	puts("");
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
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}