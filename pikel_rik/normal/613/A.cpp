#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct point {
	T x, y;
	point() : x(), y() { }
	point(T x, T y) : x(x), y(y) { }

	point operator+() const { return point(x, y); }
	point operator-() const { return point(-x, -y); }

	point &operator+=(const point &p) { return x += p.x, y += p.y, *this; }
	point &operator-=(const point &p) { return x -= p.x, y -= p.y, *this; }
	point &operator*=(const T &val) { return x *= val, y *= val, *this; }
	point &operator/=(const T &val) { return x /= val, y /= val, *this; }

	point operator+(const point &p) const { return point(x + p.x, y + p.y); }
	point operator-(const point &p) const { return point(x - p.x, y - p.y); }
	point operator*(const T &val) const { return point(x * val, y * val); }
	point operator/(const T &val) const { return point(x / val, y / val); }

	friend point operator*(const T &val, const point &p) {
		return point(val * p.x, val * p.y);
	}

	bool operator==(const point &p) const { return x == p.x && y == p.y; }
	bool operator!=(const point &p) const { return x != p.x || y != p.y; }
	bool operator< (const point &p) const { return x < p.x || (x == p.x && y < p.y); }
	bool operator> (const point &p) const { return x > p.x || (x == p.x && y > p.y); }
	bool operator<=(const point &p) const { return !(*this > p); }
	bool operator>=(const point &p) const { return !(*this < p); }

	template <typename U> operator point<U>() {
		return point<U>(x, y);
	}

	friend T dot(const point &a, const point &b) {
		return a.x * b.x + a.y * b.y;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(12);

	int n; point<int> p;
	cin >> n >> p.x >> p.y;

	vector<point<long long>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].x -= p.x, a[i].y -= p.y;
	}

	double mx = 0, mn = 1e18;
	for (int i = 0; i < n; i++) {
		mx = max(mx, (double)dot(a[i], a[i]));
		mn = min(mn, (double)dot(a[i], a[i]));
	}

	for (int i = 0; i < n; i++) {
		point<double> prev = a[i == 0 ? n - 1 : i - 1];
		point<double> now = a[i];

		auto f = [&](double ratio) -> double {
			point<double> pt = ratio * prev + (1 - ratio) * now;
			return dot(pt, pt);
		};

		double lo = 0, hi = 1;
		for (int iter = 0; iter < 100; iter++) {
			double mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
			if (f(mid1) <= f(mid2))
				hi = mid2;
			else lo = mid1;
		}
		mn = min(mn, f(lo));
	}

	cout << acos(-1.0) * (mx - mn) << '\n';
	return 0;
}