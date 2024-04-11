#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""
#define PI 3.141592653589793

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const double eps = 1e-8;

struct point {
  	double x, y;
  	point() {
  	 	x = y = 0;
  	}
  	point(double _x, double _y) {
  	 	x = _x;
  	 	y = _y;
  	}
  	double len() {
  	 	return sqrt(x * x + y * y);
  	}	
  	point operator*(double d) {
  	 	return point(x * d, y * d);
  	}
  	point operator/(double d) {
  	 	return point(x / d, y / d);
  	}
  	point operator-(point p) {
  	 	return point(x - p.x, y - p.y);
  	}
};

struct line {
  	double a, b, c;
  	line() {
  	 	a = c = 0;
  	 	b = 1;
  	}
  	line(point p1, point p2) {
  	 	//a * (p1.x - p2.x) = b * (p2.y - p1.y);
  	 	a = (p2.y - p1.y);
  	 	b = (p1.x - p2.x);
  	 	c = -(a * p1.x + b * p1.y);
  	 	assert(abs(a * p2.x + b * p2.y + c) < eps);
  	}
  	double dist(point p) {
  	 	return (p.x * a + p.y * b + c) / sqrt(a * a + b * b);
  	}
  	point project(point p) {
  		point v = point(a, b);
  	 	point ret = p - (v / v.len()) * dist(p);
  	 	assert(abs(dist(ret)) < eps);
  	 	return ret;
  	}
};

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	int n;
	scanf("%d", &n);

	int x, y;
	scanf("%d%d", &x, &y);

	point center = point(x, y);
	vector<point> arr;

	for (int i = 0; i < n; ++i) {
	 	scanf("%d%d", &x, &y);
	 	arr.puba(point(x, y));
	}

	double ansr = 0;
	double ansl = 1e18;

	for (int i = 0; i < n; ++i) {
	 	ansl = min(ansl, abs((arr[i] - center).len()));
	 	ansr = max(ansr, abs((arr[i] - center).len()));
	 	line l = line(arr[i], arr[(i + 1) % n]);
		point p = l.project(center);
		if ((p.x - arr[i].x) * (arr[(i + 1) % n].x - p.x) >= 0 && (p.y - arr[i].y) * (arr[(i + 1) % n].y - p.y) >= 0) {
		 	ansl = min(ansl, abs(l.dist(center)));
		}
	}

	cerr << ansl << " " << ansr << endl;

	printf("%.10f\n", PI * (ansr * ansr - ansl * ansl));

	return 0;
}