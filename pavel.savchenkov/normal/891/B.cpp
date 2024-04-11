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

#define TEST 0

int n;
vi a;

bool read() {
#if !TEST
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
#else
	n = 1 + rand() % 22;
	a.resize(n);
	forn(i, n) {
		a[i] = rand() % int(1e2);
	}
	sort(all(a));
	a.resize(unique(all(a)) - a.begin());
	// if  (sz(a) % 2 == 1) {
	// 	a.pop_back();
	// }
	n = sz(a);
#endif
	return 1;
}

bool bit(int mask, int i) {
	return (mask >> i) & 1;
} 

bool check(const vi& a, const vi& b) {
	assert(sz(a) == sz(b));
	for (int mask = 1; mask + 1 < (1 << sz(a)); ++mask) {
		ll sum_a = 0;
		ll sum_b = 0;
		forn(i, sz(a)) {
			if  (bit(mask, i)) {
				sum_a += a[i];
				sum_b += b[i];
			}
		}
		if  (sum_a == sum_b) {
			printf("%lld == %lld, in ", sum_a, sum_b);
			cout << bitset<22>(mask) << endl;
			return 0;
		}
	}
	return 1;
}

vi solve() {
	vii aa(n);
	forn(i, n) {
		aa[i].fst = a[i];
		aa[i].snd = i;
	}

	// if  (n % 2 == 0) {
		sort(all(aa));

		vi b(n);
		forn(i, n) {
			b[aa[i].snd] = aa[(i - 1 + n) % n].fst;
		}

		return b;
	// }
	// assert(0);
	// return {};
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		vi b = solve();

#if TEST
		if  (!check(a, b)) {
			printf("FAIL n=%d\n", n);
			forn(i, n) {
				printf("%d ", a[i]);
			}
			printf("\n");
			forn(i, n) {
				printf("%d ", b[i]);
			}
			printf("\n");
			return 0;
		} else {
			printf("OK n=%d\n", n);
		}
#else
		assert(!b.empty());
		
		if  (b.empty()) {
			printf("-1\n");
		} else {
			forn(i, n) {
				printf("%d ", b[i]);
			}
			printf("\n");
		}
#endif
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}