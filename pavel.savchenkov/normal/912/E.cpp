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

bool isPrime(int x) {
	if  (x == 1) {
		return 0;
	}
	for (int y = 2; y * y <= x; ++y) {
		if  (x % y == 0) {
			return 0;
		}
	}
	return 1;
}

#define TEST 0

int n;
vi ps;
ll k;

bool read() {
#if !TEST
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	ps.resize(n);
	forn(i, n) {
		scanf("%d", &ps[i]);
	}
	scanf("%lld", &k);
#else
	n = 6;
	ps.clear();
	for (int p = 2; sz(ps) < n; ++p) {
		if  (isPrime(p)) {
			ps.pb(p);
		}
	}
	// reverse(all(ps));
	// ps.resize(10);
	// n = sz(ps);
	k = 1;
#endif
	return 1;
}

const ull LIM = ull(1e18);

ull mul(ull a, ull b) {
	if  (a > LIM || b > LIM) {
		return LIM + 1;
	}

	const ull c = a * b;
	if  (c > LIM || c / a != b || c / b != a) {
		return LIM + 1;
	}

	return c;
}

vll nums;

void rec(const vi& ps, ull num, const int ptr) {
	if  (ptr == sz(ps)) {
		nums.pb(num);
		// if  (sz(nums) % 1000 == 0) {
		// 	eprintf("%d %lld\n", sz(nums), num);
		// }
		return;
	}

	while (num <= LIM) {
		rec(ps, num, ptr + 1);
		num = mul(num, ps[ptr]);
	}
}

vll get_all(int l, int r) {
	nums.clear();
	vi nps;
	for (int i = l; i <= r; ++i) {
		nps.pb(ps[i]);
	}
	rec(nps, 1, 0);
	return nums;
}

ull solve() {
	const int K = min(6, n - 1);
	vll left = get_all(0, K - 1);
	vll right = get_all(K, n - 1);
	sort(all(left));
	sort(all(right));

	// eprintf("left:\n");

	auto cnt_less = [&](ull num) -> ull {
		int ptr = sz(right);
		ull ans = 0;
		forn(i, sz(left)) {
			while (ptr - 1 >= 0 && mul(left[i], right[ptr - 1]) >= num) {
				--ptr;
			}
			ans += ptr;
		}
		// eprintf("num=%llu, cnt_less=%llu\n", num, ans);
		return ans;
	};

	ull L = 0;
	ull R = LIM + 1;
	while (L + 1 != R) {
		const ull M = (L + R) / 2;
		if  (cnt_less(M) < ull(k)) {
			L = M;
		} else {
			R = M;
		}
	}

	return L;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%llu\n", solve());

		// break;
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}