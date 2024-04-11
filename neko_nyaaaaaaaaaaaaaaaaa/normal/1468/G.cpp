#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0) // if parallel
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}

signed main() {
	
	int n, h; cin >> n >> h;
	vector<Point<ll>> p(n);
	vector<ll> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		x[i] = p[i].x; y[i] = p[i].y;
	}

	Point<ll> P(x[n-1], y[n-1] + h);
	Point<ll> mx(x[n-1], y[n-1]);

	double ans = 0;
	for (int i = n-2; i >= 0; i--) {
		if (P.cross(mx, p[i]) > 0) continue;

		if (P.cross(mx, p[i+1]) > 0) {
			Point<double> P1(P.x, P.y);
			Point<double> P2(mx.x, mx.y);
			Point<double> PP(p[i].x, p[i].y);
			Point<double> PQ(p[i+1].x, p[i+1].y);
			Point<double> P3 = lineInter(P1, P2, PP, PQ).second;

			ans += (P3 - PP).dist();

			mx = p[i];
		} else {
			ans += (p[i+1] - p[i]).dist();
			mx = p[i];
		}
	}

	cout << fixed << setprecision(12) << ans << '\n';
	
	return 0;
}