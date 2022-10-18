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

struct pnt {
	int x, y;

	pnt() {
		x = y = 0;
	}

	pnt(int x, int y) : x(x), y(y) {}

	void read() {
		scanf("%d%d", &x, &y);
	}
};

const int MAXN = 1e5 + 10;

int n;
int x1, x2;
int y1, y2;
pnt v[MAXN];
pnt s[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	forn(i, n) {
		s[i].read();
		v[i].read();
	}
	return 1;
}

struct frac {
	int p, q;

	frac() {
		p = 0;
		q = 1;
	}

	frac(int p, int q) : p(p), q(q) {
		if  (!q) {
			this->q = 1;
		}
		assert(this->q);
	}

	bool operator < (const frac& f) const {
		bool sw = 0;
		if  (q < 0) {
			sw ^= 1;
		}
		if  (f.q < 0) {
			sw ^= 1;
		}
		if  (p * 1ll * f.q == f.p * 1ll * q) {
			return 0;
		}
		return (p * 1ll * f.q < f.p * 1ll * q) ^ sw;
	}

	void print() const {
		printf("%d/%d ~ %.10f\n", p, q, p * 1.0 / q);
	}
};

bool solve() {
	// while (1) {
	// 	frac f1(rand() % 20 - 10, rand() % 20 - 10);
	// 	assert(f1.q);

	// 	frac f2(rand() % 20 - 10, rand() % 20 - 10);
	// 	assert(f2.q);

	// 	ld F1 = f1.p * 1.0 / f1.q;
	// 	ld F2 = f2.p * 1.0 / f2.q;
	
	// 	f1.print();
	// 	f2.print();
	// 	printf("double -> %d\n", F1 < F2);
	// 	printf("me -> %d\n", f1 < f2);
	// 	assert((F1 < F2) == (f1 < f2));
	// }

	frac mx(0, 1);
	frac mn(int(1e6), 1);
	bool bad = 0;
	forn(i, n) {
		auto upd_lower = [&](int s, int v, int L) {
			if  (!v) {
				if  (s <= L) {
					bad = 1;
					return;
				}
				return;
			}
			if  (v < 0) {
				mn = min(mn, frac(L - s, v));
			} else {
				mx = max(mx, frac(L - s, v));
			}
		};

		auto upd_upper = [&](int s, int v, int R) {
			if  (!v) {
				if  (s >= R) {
					bad = 1;
					return;
				}
				return;
			}
			if  (v > 0) {
				mn = min(mn, frac(R - s, v));
			} else {
				mx = max(mx, frac(R - s, v));
			}
		};

		upd_lower(s[i].x, v[i].x, x1);
		upd_upper(s[i].x, v[i].x, x2);

		upd_lower(s[i].y, v[i].y, y1);
		upd_upper(s[i].y, v[i].y, y2);
	} 

	// mx.print();
	// mn.print();

	if  (bad || !(mx < mn)) {
		return 0;
	}

	ld ans = ld(mx.p) / mx.q;
	printf("%.10f\n", (double) ans);
	return 1;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		if  (!solve()) {
			puts("-1");
		}
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}