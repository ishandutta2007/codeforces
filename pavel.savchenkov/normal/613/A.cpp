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

const ld PI = acosl(-1.0);

struct Point {
	ld x, y;

	Point() {}

	Point(ld x, ld y) : x(x), y(y) {}

	bool read() {
		double tx, ty;
		if  (scanf("%lf%lf", &tx, &ty) < 2) {
			return false;
		}
		x = tx;
		y = ty;
		return true;
	}

	ld dist(const Point& p) const {
		return sqrtl((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
	}
};

Point operator + (const Point& p, const Point& q) {
	return Point(p.x + q.x, p.y + q.y); 
}

Point operator - (const Point& p, const Point& q) {
	return Point(p.x - q.x, p.y - q.y); 
}

Point operator * (const Point& p, ld t) {
	return Point(p.x * t, p.y * t);
}

ld get_dist(const Point& p1, const Point& p2, ld t, Point& p) {
	Point mid = p1 + (p2 - p1) * t;
	return mid.dist(p);
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	Point p;
	assert(p.read());
	vector<Point> ps(n);
	forn(i, n) {
		assert(ps[i].read());
	}	

	ld max_rad = 0;
	ld min_rad = 1e10;
	forn(i, n) {
		max_rad = max(max_rad, ps[i].dist(p));

		Point p1 = ps[i];
		Point p2 = ps[(i + 1) % n];
		ld l = 0;
		ld r = 1;
		forn(it, 80) {
			ld m1 = (2 * l + r) / 3;
			ld m2 = (l + 2 * r) / 3;
			ld d1 = get_dist(p1, p2, m1, p);
			ld d2 = get_dist(p1, p2, m2, p);
			if  (d1 < d2) {
				r = m2;
			} else {
				l = m1;
			}
		}
		min_rad = min(min_rad, get_dist(p1, p2, l, p));
	}

	printf("%.20f\n", double(PI * max_rad * max_rad - PI * min_rad * min_rad));
	return 0;
}