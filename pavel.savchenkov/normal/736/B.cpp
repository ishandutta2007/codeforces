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

const int MAXN = 1e5 + 10;
const int INF = 1e9;

int n;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	return 1;
}

bool prime(int x) {
	if  (x == 2) {
		return 1;
	}
	for (int i = 2; i * i <= x; ++i) {
		if  (x % i == 0) {
			return 0;
		}
	}
	return 1;
}

int solve() {
	if  (prime(n)) {
		return 1;
	}

	if  (n % 2 == 0 && n >= 4) {
		return 2;
	}

	assert(n > 4);
	assert(n & 1);

	if  (n - 2 >= 2 && prime(n - 2)) {
		return 2;
	}

	if  (n - 3 >= 4) {
		return 3;
	}

	assert(false);
	return -1;
}

int max_div(int x) {
	for (int i = x - 1; i >= 1; --i) {
		if  (x % i == 0) {
			return i;
		}
	}
	assert(0);
	return -1;
}

int brut() {
	vi dp(n + 1, INF);
	dp[0] = 0;
	dp[1] = INF;
	for (int x = 2; x <= n; ++x) {
		for (int px = 2; px <= x; ++px) {
			dp[x] = min(dp[x], dp[x - px] + max_div(px));
		}
	}
	return dp[n];
} 

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	// for (n = 2; n <= 100; ++n) {
	// 	int my = solve();
	// 	int br = brut();
	// 	if  (my != br) {
	// 		printf("n=%d, my=%d, br=%d\n", n, my, br);
	// 	} else {
	// 		printf("n=%d OK\n", n);
	// 	}
	// }

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}