#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
#define mp make_pair
#define pi 3.1415926535897932384626433832795

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int B = 524288;

struct Point {
	double x;
	double y;
	Point(double _x, double _y) :x(_x), y(_y) {}
	Point() { x = y = 0; }
	Point add(const Point& p) const{
		return Point(x + p.x, y + p.y);
	}
};
struct Matrix {
	double a, b;
	double c, d;
	Matrix(double _a, double _b, double _c, double _d) :a(_a), b(_b), c(_c), d(_d) {}
	Matrix() { a = d = 1; b = c = 0; }
	Point apply(const Point &p) const  {
		return Point(a*p.x + b*p.y, c*p.x + d*p.y);
	}
	Matrix multiply(const Matrix &m) const {
		double A = a*m.a + b*m.c;
		double B = a*m.b + b*m.d;
		double C = c*m.a + d*m.c;
		double D = c*m.b + d*m.d;
		return Matrix(A, B, C, D);
	}
};

typedef pair<Matrix, Point> pmp;

pmp tr[2 * B];
int modified[2 * B];

void push(int nd) {
	if (!modified[nd]) return;
	if (nd >= B) return;
	modified[nd] = 0;
	Matrix &m = tr[nd].first;
	Point& p = tr[nd].second;
	tr[2 * nd].first = m.multiply(tr[2 * nd].first);
	tr[2*nd].second = m.apply(tr[2 * nd].second).add(p);
	tr[2 * nd + 1].first = m.multiply(tr[2 * nd + 1].first);
	tr[2*nd+1].second = m.apply(tr[2 * nd + 1].second).add(p);
	modified[2 * nd] = modified[2 * nd + 1] = 1;
	tr[nd].first = Matrix();
	tr[nd].second = Point();
}
void upd(int nd, int ndl, int ndr, int l, int r, const Matrix& m, const Point& p) {
	if (l > ndr || ndl > r) return;
	else if (l <= ndl && ndr <= r) {
		modified[nd] = 1;
		tr[nd].first = m.multiply(tr[nd].first);
		tr[nd].second = m.apply(tr[nd].second).add(p);
	}
	else {
		int mid = (ndl + ndr) / 2;
		push(nd);
		upd(2 * nd, ndl, mid, l, r, m, p);
		upd(2 * nd + 1, mid + 1, ndr, l, r, m, p);
	}
}
void update_node(int nd) {
	if (nd > 1)update_node(nd / 2);
	push(nd);
}

double eudis(Point &x, Point &y) {
	double dx = x.x - y.x;
	double dy = x.y - y.y;
	return sqrt(dx*dx + dy*dy);
}
Point app2(const pmp& S, const Point &p) {
	return (S.first).apply(p).add(S.second);
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d ", &x, &y, &z);
		if (x == 1) {
			update_node(B + (y - 1));
			update_node(B + y);
			Point Red = app2(tr[B + y - 1], Point(y - 1, 0));
			Point Blue = app2(tr[B + y], Point(y, 0));
			double dd = eudis(Red, Blue);
			double scale = z / dd;
			double trxx = scale*(Blue.x - Red.x);
			double tryy = scale*(Blue.y - Red.y);
			upd(1, 0, B - 1, y, n, Matrix(), Point(trxx, tryy));
		}
		else{
			update_node(B + (y - 1));
			Point Red = app2(tr[B + y - 1], Point(y - 1, 0));
			double cs = cos((double)z / 180 * pi);
			double sn = sin((double)z / 180 * pi);
			upd(1, 0, B - 1, y, n, Matrix(cs, sn, -sn, cs), Matrix(-cs + 1, -sn, sn, -cs + 1).apply(Red));
		}
		update_node(B + n);
		Point End = app2(tr[B + n], Point(n, 0));
		printf("%.15f %.15f\n", End.x, End.y);
	}
	
	return 0;
}