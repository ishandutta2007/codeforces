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

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"


const int MAXN = 1e5 + 10;
const ld PI = acos(-1.0);

struct Point {
	int x, y;

	bool read() {
		if  (scanf("%d%d", &x, &y) < 2) {
			return false;
		}
		return true;
	}

	ll sq_dist(const Point& p) const {
		return (x - p.x) * 1ll * (x - p.x) + (y - p.y) * 1ll * (y - p.y);
	}
};

struct Circle {
	Point p;
	int r;

	bool read() {
		if  (!p.read()) {
			return false;
		}
		scanf("%d", &r);
		return true;
	}

	bool contains(const Point& q) {
		return p.sq_dist(q) <= r * 1ll * r;
	}

	ld ang(const Point& p0) const {
		ld a = atan2(p.y - p0.y, p.x - p0.x);
		if  (a < 0) {
			a += 2 * PI;
		}
		return a;
	}
};

vector<Circle> cs;
int n;
Point p0;
int v, T;

bool read() {
	if  (!p0.read()) {
		return false;
	}
	scanf("%d%d", &v, &T);

	scanf("%d", &n);
	cs.resize(n);
	forn(i, n) {
		cs[i].read();
	}
	return true;
}

ld solve() {
	forn(i, sz(cs)) {
		if  (cs[i].contains(p0)) {
			return 1;
		}
	}

	vector<pair<ld, ld>> segs;
	forn(i, sz(cs)) {
		if  (cs[i].r == 0) {
			continue;
		}

		ld ang = cs[i].ang(p0);
		ld D = sqrtl(cs[i].p.sq_dist(p0));
		ld x = cs[i].r / D;
		if  (x < 0) x = 0;
		if  (x > 1) x = 1;
		ld a = asin(x);

		ld l = 0;
		ld r = a;
		forn(it, 50) {
			ld m = (l + r) * 0.5;
			ld sin_beta = D * sin(m) / cs[i].r;
			ld cos_beta = sqrtl(1.0 - sin_beta * sin_beta);
			ld z = D * cosl(m) - cos_beta * cs[i].r;

			if  (z < v * 1ll * T) {
				l = m;
			} else {
				r = m;
			}
		}

		ld diff = l;
		l = ang - diff;
		r = ang + diff;

		if  (l < 0) {
			l += 2 * PI;
			r += 2 * PI;
		}

		if  (r > 2 * PI) {
			segs.pb(mp(l, 2 * PI));
			segs.pb(mp(0, r - 2 * PI));
		} else {
			segs.pb(mp(l, r));
		}
	}

	ld sum = 0;
	sort(all(segs));
	
	// for (auto s : segs) {
	// 	printf("%.5f %.5f\n", (double) s.fst, (double) s.snd);
	// }

	ld r = 0;
	for (auto s : segs) {
		sum += max((ld) 0.0, s.fst - r);
		r = max(r, s.snd);
	}
	sum += 2 * PI - r;

	return 1.0 - sum / (2 * PI);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%.10f\n", (double) solve());
	}

#ifdef LOCAL
	printf("Time: %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}