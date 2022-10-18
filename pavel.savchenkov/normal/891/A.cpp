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

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int solve() {
	int mn = n + 1;
	forn(l, n) {
		int g = 0;
		for (int r = l; r < n; ++r) {
			g = gcd(g, a[r]);
			if  (g == 1) {
				mn = min(mn, r - l + 1);
			}
		}
	}

	if  (mn == n + 1) {
		return -1;
	}

	if  (mn == 1) {
		int ans = 0;
		forn(i, n) {
			ans += a[i] != 1;
		}
		assert(ans < n);
		return ans;
	}

	return (mn - 1) + (n - 1);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		int ans = solve();
		printf("%d\n", ans);
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}