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

int n, L;
vll c;

bool read() {
	if  (scanf("%d%d", &n, &L) < 2) {
		return 0;
	}
	c.resize(n);
	forn(i, n) {
		scanf("%lld", &c[i]);
	}
	while (n <= 30) {
		ll last = c.back();
		c.pb(last * 2);
		++n;
	}
	return 1;
}

ll solve() {
	assert((1 << (n - 1)) >= int(1e9));

	forn(i, n - 1) {
		c[i + 1] = min(c[i + 1], 2 * c[i]);
	}

	// eprintf("c:\n");
	// forn(i, n) {
	// 	eprintf("%lld ", c[i]);
	// }
	// eprintf("\n");

	ll res = c.back();
	ll have = 0;
	while (L > 0) {
		forn(i, n) {
			if  ((1 << i) >= L) {
				res = min(res, have + c[i]);
			}
		}

		ford(i, n) {
			if  ((1 << i) <= L) {
				L -= 1 << i;
				have += c[i];
				assert(L < (1 << i));
				break;
			}
		}
	}

	return res;
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
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}