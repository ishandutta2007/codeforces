// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

struct point {
	int x, y;
	point(int _x, int _y) : x(_x), y(_y) {}

	point operator+(point const& other) const {
		return point(x + other.x, y + other.y);
	}

	point operator-(point const& other) const {
		return point(x - other.x, y - other.y);
	}

	ll len2() const {
		return (ll) x * x + (ll) y * y;
	}

	bool operator<(point const& other) const {
		return x < other.x || (x == other.x && y < other.y);
	}

	bool operator!=(point const& other) const {
		return x != other.x || y != other.y;
	}

	point ort() const {
		return point(y, -x);
	}
};

ostream& operator<<(ostream& o, point const& p) {
	// o << "(" << p.x << ", " << p.y << ")";
	o << p.x << " " << p.y;
	return o;
}

ll cross(point const& p1, point const& p2) {
	return (ll) p1.x * p2.y - (ll) p1.y * p2.x;
}

vector<point> convex_hull(vector<point> points) {
	int mem = 0;
	for (int i = 0; i < szof(points); ++i) {
		if (points[i] < points[mem]) {
			mem = i;
		}
	}
	point center = points[mem];
	vector<point> ret;
	for (auto p : points) {
		if (p != center) {
			ret.push_back(p - center);
		}
	}
	swap(ret, points);
	sort(points.begin(), points.end(), [&](point const& p1, point const& p2) {
		ll tmp = cross(p1, p2);
		if (tmp) {
			return tmp > 0;
		}
		return p1.len2() < p2.len2();
	});
	ret = {point(0, 0)};
	for (point p : points) {
		while (szof(ret) >= 2 && cross(ret.back() - ret[szof(ret) - 2], p - ret.back()) <= 0) {
			ret.pop_back();
		}
		ret.push_back(p);
	}
	for (auto& p : ret) {
		p = p + center;
	}
	return ret;
}

struct point_d {
	double x, y;
	point_d(double _x, double _y) : x(_x), y(_y) {}
	point_d(point p) : x(p.x), y(p.y) {}

	point_d operator+(point_d const& other) const {
		return point_d(x + other.x, y + other.y);
	}

	point_d operator-(point_d const& other) const {
		return point_d(x - other.x, y - other.y);
	}

	double len() const {
		return sqrt(x * x + y * y);
	}
};

ostream& operator<<(ostream& o, point_d const& p) {
	// o << "(" << p.x << ", " << p.y << ")";
	o << p.x << " " << p.y;
	return o;
}

struct line {
	double a, b, c;
	line(point_d p1, point_d p2) {
		a = p2.y - p1.y;
		b = p1.x - p2.x;
		c = -(a * p1.x + b * p1.y);
		assert(abs(a * p2.x + b * p2.y + c) < 1e-5);
	}
};

point_d intersection(line const& l1, line const& l2) {
	double d = l1.a * l2.b - l1.b * l2.a;
	double d1 = -l1.c * l2.b + l1.b * l2.c;
	double d2 = -l1.a * l2.c + l1.c * l2.a;
	return point_d(d1 / d, d2 / d);
}

void solve() {
	int n;
	cin >> n;
	vector<point> points;
	const int MAXC = 100000;
	for (int i = 0; i < n; ++i) {
		int x, y, v;
		cin >> x >> y >> v;
		if (x - v >= 0) {
			points.push_back(point(x - v, y));
		} else {
			points.push_back(point(0, max(0, y - (v - x))));
			points.push_back(point(0, min(MAXC, y + (v - x))));
		}

		if (x + v <= MAXC) {
			points.push_back(point(x + v, y));
		} else {
			points.push_back(point(MAXC, max(0, y - (v - (MAXC - x)))));
			points.push_back(point(MAXC, min(MAXC, y + (v - (MAXC - x)))));
		}

		if (y - v >= 0) {
			points.push_back(point(x, y - v));
		} else {
			points.push_back(point(max(0, x - (v - y)), 0));
			points.push_back(point(min(MAXC, x + (v - y)), 0));
		}

		if (y + v <= MAXC) {
			points.push_back(point(x, y + v));
		} else {
			points.push_back(point(max(0, x - (v - (MAXC - y))), MAXC));
			points.push_back(point(min(MAXC, x + (v - (MAXC - y))), MAXC));
		}
	}

	auto poly = convex_hull(points);

	double best = 0;
	int mem = -1;

	for (int i = 0; i < szof(poly); ++i) {
		int a = i;
		int b = (i + 1) % szof(poly);
		int c = (i + 2) % szof(poly);
		point_d ab((poly[a].x + poly[b].x) / 2.0, (poly[a].y + poly[b].y) / 2.0);
		point_d bc((poly[b].x + poly[c].x) / 2.0, (poly[b].y + poly[c].y) / 2.0);
		// cerr << ab << " " << bc << endl;
		line l1(ab, ab + (poly[b] - poly[a]).ort());
		line l2(bc, bc + (poly[c] - poly[b]).ort());
		point_d center = intersection(l1, l2);
		// cerr << center << endl;
		double r = (center - poly[a]).len();
		// cerr << poly[a] << "    " << poly[b] << "    " << poly[c] << "    " << r << endl;
		if (r > best) {
			best = r;
			mem = i;
		}
	}

	for (int i = 0; i < 3; ++i) {
		cout << poly[(mem + i) % szof(poly)] << "\n";
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}