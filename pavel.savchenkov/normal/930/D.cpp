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

struct pnt {
	int x, y;

	void read() {
		scanf("%d%d", &x, &y);
	}

	pnt transform() {
		return pnt{y - x, y + x};
	}

	int par() const {
		assert(abs(x) % 2 == abs(y) % 2);
		return (abs(x) % 2);
	}

	void print() const {
		eprintf("(%d, %d)\n", x, y);
	}
};

int n;
vector<pnt> ps;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	ps.resize(n);
	forn(i, n) {
		ps[i].read();
		ps[i] = ps[i].transform();
	}
	return 1;
}

const int INF = 1e9;

void remin(int& x, int y) {
	if  (x > y) {
		x = y;
	}
}

void remax(int& x, int y) {
	if  (x < y) {
		x = y;
	}
}

ll solve(vector<pnt> qs, int par) {
	int x0 = INF;
	int x1 = -INF;
	for (const auto& q : qs) {
		remin(x0, q.x);
		remax(x1, q.x);
	}
	--x0;
	++x1;

	// eprintf("x0=%d, x1=%d\n", x0, x1);

	if  (x0 > x1) {
		return 0;
	}

	vi V[2][2];
	forn(c0, 2) {
		forn(c1, 2) {
			const int def = (c1 == 0) ? -INF : INF;
			V[c0][c1] = vi(x1 - x0 + 1, def);
		}
	}

	for (const auto& q : qs) {
		assert(q.x - 1 - x0 >= 0);
		assert(q.x + 1 - x0 < x1 - x0 + 1);

		forn(c0, 2) {
			forn(c1, 2) {
				auto& v = V[c0][c1];
				if  (c0 == 0 && c1 == 0) {
					remax(v[q.x - 1 - x0], q.y - 1);
				} else if  (c0 == 0 && c1 == 1) {
					remin(v[q.x - 1 - x0], q.y + 1);
				} else if  (c0 == 1 && c1 == 0) {
					remax(v[q.x + 1 - x0], q.y - 1);
				} else {
					assert(c0 == 1 && c1 == 1);
					remin(v[q.x + 1 - x0], q.y + 1);
				}
			}
		}
	}

	forn(c0, 2) {
		forn(c1, 2) {
			auto& v = V[c0][c1];
			if  (c0 == 0 && c1 == 0) {
				ford(i, sz(v) - 1) {
					remax(v[i], v[i + 1]);
				}
			} else if  (c0 == 0 && c1 == 1) {
				ford(i, sz(v) - 1) {
					remin(v[i], v[i + 1]);
				}
			} else if  (c0 == 1 && c1 == 0) {
				for (int i = 1; i < sz(v); ++i) {
					remax(v[i], v[i - 1]);
				}
			} else {
				assert(c0 == 1 && c1 == 1);
				for (int i = 1; i < sz(v); ++i) {
					remin(v[i], v[i - 1]);
				}
			}
		}
	}

	ll ans = 0;
	for (int x = x0; x <= x1; ++x) {
		if  (abs(x) % 2 != par) {
			continue;
		}

		const int pos = x - x0;
		int y1 = min(V[0][0][pos], V[1][0][pos]);
		int y0 = max(V[0][1][pos], V[1][1][pos]);

		if  (abs(y1) % 2 == par) {
			++y1;
		}
		if  (abs(y0) % 2 != par) {
			++y0;
		}

		if  (y0 >= y1) {
			continue;
		}

		int cnt = (y1 - y0 + 1) / 2;
		ans += cnt;

		// eprintf("x=%d, y0=%d, y1=%d\n", x, y0, y1);
	}

	return ans;
}

void solve() {
	// eprintf("ps:\n");
	// for (const auto& p : ps) {
	// 	p.print();
	// }
	// eprintf("\n");

	ll ans = 0;
	forn(par, 2) {
		vector<pnt> qs;
		for (const auto& p : ps) {
			if  (p.par() == par) {
				qs.pb(p);
			}
		}

		ll cur = solve(qs, par ^ 1);
		ans += cur;
	}

	printf("%lld\n", ans);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}