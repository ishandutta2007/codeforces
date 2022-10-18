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

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	return 1;
}

inline bool bit(int mask, int i) {
	return (mask >> i) & 1;
}

bool checkP(const vi& p) {
	for (int i = 1; i <= n; ++i) {
		if  (!(p[i] != i && (p[i] & i) == 0)) {
			return 0;
		}
	}
	return 1;
}

vi brutP() {
	vi p(n + 1);
	iota(all(p), 0);
	do {
		if  (checkP(p)) {
			return p;
		}
	} while (next_permutation(p.begin() + 1, p.end()));
	return {};
}

bool checkQ(const vi& q) {
	for (int i = 1; i <= n; ++i) {
		if  (!(q[i] != i && (q[i] & i) != 0)) {
			return 0;
		}
	}
	return 1;
}

vi brutQ() {
	vi q(n + 1);
	iota(all(q), 0);
	do {
		if  (checkQ(q)) {
			return q;
		}
	} while (next_permutation(all(q)));
	return {};
}

vi getP() {
	if  (n & 1) {
		return {};
	}

	vi p(n + 1);
	iota(all(p), 0);

	int r = n;
	while (r >= 1) {
		int hb = 31;
		while (!bit(r, hb)) {
			--hb;
		}

		int suff = 1;
		while (bit(r - suff, hb)) {
			++suff;
		}
		suff *= 2;

		assert(r >= suff);
		reverse(p.begin() + (r - suff + 1), p.begin() + r + 1);
		r -= suff;
	}

	// eprintf("n = %d\n", n);
	// for (int i = 1; i < sz(p); ++i) {
	// 	eprintf("%d ", p[i]);
	// }
	// eprintf("\n");

	assert(checkP(p));

	return p;
}

void shift(vi& arr) {
	assert(sz(arr) >= 2);
	int last = arr.back();
	arr.pop_back();
	reverse(all(arr));
	arr.pb(last);
	reverse(all(arr));
}

vi getQ() {
	vi q(n + 1);
	iota(all(q), 0);

	int r = n;
	while (r >= 1) {
		int hb = 31;
		while (!bit(r, hb)) {
			--hb;
		}

		if  (r == (1 << hb)) {
			return {};
		}

		if  (r == (1 << hb) + 1) {
			swap(q[r - 1], q[r]);
			r -= 2;
			continue;
		}

		if  (r == 1) {
			return {};
		}

		int pos1 = 1 << hb;
		++pos1;
		swap(q[1], q[pos1]);

		int ptr = r;
		for (int h = hb; h >= 1; --h) {
			while (!bit(ptr, h)) {
				--ptr;
			}
			assert(ptr >= 2);

			int l = ptr;
			while (l - 1 >= 2 && bit(l - 1, h)) {
				--l;
			}

			// [l, ptr]
			vi ids;
			vi vals;
			// eprintf("h=%d, l=%d, ptr=%d\n", h, l, ptr);
			for (int i = l; i <= ptr; ++i) {
				if  (i != pos1) {
					ids.pb(i);
					vals.pb(q[i]);
				}
			}

			assert(sz(ids) >= 2);
			assert(sz(vals) == sz(ids));

			shift(ids);
			// shift(vals);

			forn(i, sz(ids)) {
				q[ids[i]] = vals[i];
			}
			ptr = l - 1;
		}

		break;
	}

	// eprintf("n = %d\n", n);
	// for (int i = 1; i < sz(q); ++i) {
	// 	eprintf("%d ", q[i]);
	// }
	// eprintf("\n");
	assert(checkQ(q));

	return q;
}

void solve() {
	{
		auto p = getP();
		if  (p.empty()) {
			printf("NO\n");
		} else {
			printf("YES\n");
			for (int i = 1; i <= n; ++i) {
				printf("%d ", p[i]);
			}
			printf("\n");
		}
	}

	{
		auto q = getQ();
		if  (q.empty()) {
			printf("NO\n");
		} else {
			printf("YES\n");
			for (int i = 1; i <= n; ++i) {
				printf("%d ", q[i]);
			}
			printf("\n");
		}	
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}
	return 0;

	// for (n = 1; n <= int(1e5); ++n) {
	// 	getP();
	// }
	// return 0;

	for (n = 1; n <= int(1e5); ++n) {
		getQ();
	}
	return 0;

	for (n = 1; n <= 14; ++n) {
		// auto p = brutP();
		auto q = brutQ();

		eprintf("n = %d\n", n);

		// eprintf("p:\n");
		// for (int i = 1; i < sz(p); ++i) {
		// 	eprintf("%d ", p[i]);
		// }
		// eprintf("\n");

		eprintf("q:\n");
		for (int i = 1; i < sz(q); ++i) {
			eprintf("%d ", q[i]);
		}
		eprintf("\n\n");
	}
	return 0;


#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}