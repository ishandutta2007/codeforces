#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forq(i, q, n) for (int i = int(q); i < int(q); ++i)
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK "dynamic"
#define X first
#define Y second

const int MAXN = (int)1e5 + 7;
const int INF = (int)1e9 + 7;
const ll LINF = (ll)1e12 + 7;
const int MOD = (int)1e9 + 7;

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

struct Point {
	double x, y;
	Point() {}
	Point(double _x, double _y) {
		x = _x, y = _y;
	}
};

struct Line {
	double a, b, c;
	Line() {}
	Line(double _a, double _b, double _c) {
		a = _a, b = _b, c = _c;
	}
	Line(Point p, Point t) {
		a = t.y - p.y;
		b = p.x - t.x;
		c = -a * p.x - b * p.y;
	}
	Point operator^(Line l) {
		double d = a * l.b - b * l.a;
		if (d == 0) {
			return Point(0, -1);
		}
		double x = (b * l.c - l.b * c) / d;
		double y = (c * l.a - l.c * a) / d;
		return Point(x, y);
	}
};

struct Poly {
	vector<Point> A;
	Poly() {}
	void push(Point x) {
		A.push_back(x);
	}
};

int main() {
	file();
	int n;
	ll w, v, u;
	scanf("%d%I64d%I64d%I64d", &n, &w, &v, &u);
	Poly A;
	forn(i, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		A.push(Point(x, y));
	}
	bool f1 = 0, f2 = 0;
	Line c = Line(Point(0, 0), Point(v, u));
	forn(i, n) {
		double x1 = v, y1 = u, x2 = A.A[i].x - v, y2 = A.A[i].y - u;
		double rr = x1 * y2 - x2 * y1;
		if (rr > 0) {
			f2 = 1;
		} else {
			if (rr < 0) {
				f1 = 1;
			}
		}
	}
	if (!f1 || !f2) {
		cout.precision(10);
		cout << fixed << 1.0 * w / u;
		return 0;
	}
	double l = 0;
	forn(i, n) {
		double d = A.A[i].x - (-(c.b * A.A[i].y + c.c) / c.a);
		l = max(l, d);
	}
	cout.precision(10);
	cout << fixed << 1.0 * w / u + l / v;
	return 0;
}