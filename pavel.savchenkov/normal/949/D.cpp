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

int n, d, b;
vi a;

bool read() {
#if !TEST
	if  (scanf("%d%d%d", &n, &d, &b) < 3) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
#else
	n = int(1e5);
	d = 1 + rand() % 20;
	b = 100;
	a.resize(n);
	forn(i, n) {
		a[i] = 0;
	}
	forn(it, 10) {
		int pos = rand() % n;
		a[pos] = rand() % int(1e3);
	}
#endif
	return 1;
}

int last_left;

bool can_go(int from, int to) {
	if  (from == to) {
		return 1;
	}

	if  (from < to) {
		if  (to <= last_left) {
			return 1;
		}
		const int can_steps = n - to;
		if  (to - from <= can_steps * 1ll * d) {
			return 1;
		}
		return 0;
	}

	assert(from > to);
	if  (to > last_left) {
		return 1;
	}

	const int can_steps = to + 1;
	if  (from - to <= can_steps * 1ll * d) {
		return 1;
	}
	return 0;
}

bool check(vi a, int D) {
	int pl = 0;
	int pr = n - 1;

	int l = D;
	int r = n - D - 1;
	while (l <= r) {
		while (pl < n && !a[pl]) {
			++pl;
		}
		while (pr >= 0 && !a[pr]) {
			--pr;
		}

		assert(pl >= 0);
		assert(pr <= n - 1);

		// eprintf("l=%d, r=%d, pl=%d, pr=%d\n", l, r, pl, pr);

		if  (l <= last_left) {
			int got = 0;
			int last = -1;
			for (int i = pl; i <= l; ++i) {
				got += a[i];
				if  (got >= b) {
					last = i;
					break;
				}
			}

			if  (last != -1) {
				int rest = b;
				for (int i = pl; i <= l && rest; ++i) {
					int now = min(rest, a[i]);
					a[i] -= now;
					rest -= now;
					pl = i;
				}
				assert(rest == 0);
				assert(pl >= last);
				++l;
				continue;
			}

			a[l] = 0;
			int need = b - got;
			pl = max(pl, l + 1);
			for (int i = pl; i <= pr && need && can_go(i, l); ++i) {
				int now = min(need, a[i]);
				a[i] -= now;
				need -= now;
				pl = i;
			}

			if  (need > 0) {
				return 0;
			}

			++l;
		} else {
			int got = 0;
			int last = -1;
			for (int i = pr; i >= r; --i) {
				got += a[i];
				if  (got >= b) {
					last = i;
					break;
				}
			}

			if  (last != -1) {
				int rest = b;
				for (int i = pr; i >= r && rest; --i) {
					int now = min(rest, a[i]);
					a[i] -= now;
					rest -= now;
					pr = i;
				}
				assert(rest == 0);
				assert(pr <= last);
				--r;
				continue;
			}

			a[r] = 0;
			int need = b - got;
			pr = min(pr, r - 1);
			for (int i = pr; i >= pl && need && can_go(i, r); --i) {
				int now = min(need, a[i]);
				a[i] -= now;
				need -= now;
				pr = i;
			}

			if  (need > 0) {
				return 0;
			}

			--r;
		}
	}

	return 1;
}

int solve() {
	last_left = (n + 1) / 2 - 1;

	int L = -1;
	int R = (n + 1) / 2 + 1;
	while (L != R - 1) {
		int M = (L + R) / 2;
		if  (check(a, M)) {
			R = M;
		} else {
			L = M;
		}
	}
	assert(check(a, R));
	return R;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

#if TEST
	while (read()) {
		double st = clock() * 1.0 / CLOCKS_PER_SEC;
		solve();
		eprintf("Time: %.10f\n", clock() * 1.0 / CLOCKS_PER_SEC - st);
	}
#endif

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}