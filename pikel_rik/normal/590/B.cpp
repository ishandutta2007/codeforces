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

	T norm() const {
		return dot(*this, *this);
	}

	friend T norm(const point &p) {
		return p.norm();
	}

	double abs() const {
		return std::sqrt(norm());
	}
};

template <typename T>
double abs(const point<T> &p) {
	return p.abs();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(12);

	point<double> a, b;
	cin >> a.x >> a.y >> b.x >> b.y;

	double v_max, t;
	cin >> v_max >> t;

	point<double> v, w;
	cin >> v.x >> v.y >> w.x >> w.y;

	double lo = 0, hi = 1e9;
	for (int i = 0; i < 50; i++) {
		double mid = (lo + hi) / 2;

		double time = min(mid, t);

		point<double> c_a(a.x + v.x * time, a.y + v.y * time);
		double r_a = time * v_max;

		if (mid <= t) {
			if (abs(b - c_a) <= r_a) {
				hi = mid;
			} else lo = mid;
			continue;
		}

		time = mid - t;

		point<double> c_b(b.x - w.x * time, b.y - w.y * time);
		double r_b = time * v_max;

		if (abs(c_a - c_b) <= r_a + r_b) {
			hi = mid;
		} else lo = mid;
	}
	cout << lo << '\n';
	return 0;
}