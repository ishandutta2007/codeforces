#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct point {
	T x, y;

	point() : x(), y() {}

	point(T x, T y) : x(x), y(y) {}

	point operator+() const {
		return point(x, y);
	}

	point operator-() const {
		return point(-x, -y);
	}

	point &operator+=(const point &p) {
		return x += p.x, y += p.y, *this;
	}

	point &operator-=(const point &p) {
		return x -= p.x, y -= p.y, *this;
	}

	point &operator*=(const T &val) {
		return x *= val, y *= val, *this;
	}

	point &operator/=(const T &val) {
		return x /= val, y /= val, *this;
	}

	friend point operator+(const point &p, const point &q) {
		return point(p.x + q.x, p.y + q.y);
	}

	friend point operator-(const point &p, const point &q) {
		return point(p.x - q.x, p.y - q.y);
	}

	friend point operator+(const point &p, T val) {
		return point(p.x * val, p.y * val);
	}

	friend point operator/(const point &p, T val) {
		return point(p.x / val, p.y / val);
	}

	friend point operator*(T val, const point &p) {
		return point(val * p.x, val * p.y);
	}

	bool operator==(const point &p) const {
		return x == p.x && y == p.y;
	}

	bool operator!=(const point &p) const {
		return x != p.x || y != p.y;
	}

	bool operator<(const point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}

	bool operator>(const point &p) const {
		return x > p.x || (x == p.x && y > p.y);
	}

	bool operator<=(const point &p) const {
		return !(*this > p);
	}

	bool operator>=(const point &p) const {
		return !(*this < p);
	}

	template<typename U>
	operator point<U>() {
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
	using pt = point<long long>;

	int n, h;
	cin >> n >> h;

	vector<pt> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}

	auto area = [&](const pt &a, const pt &b, const pt &c) -> long long {
		return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
	};

	auto dist = [&](const auto &p, const auto &q) -> double {
		return sqrt(dot(p - q, p - q));
	};

	auto intersection = [&](const pt &p1, const pt &p2, const pt &q1, const pt &q2) -> point<double> {
		double m1 = (double)(p2.y - p1.y) / (p2.x - p1.x);
		double m2 = (double)(q2.y - q1.y) / (q2.x - q1.x);

		double x = (q1.y - m2 * q1.x - p1.y + m1 * p1.x) / (m1 - m2);
		double y = p1.y + m1 * (x - p1.x);
		return point<double>(x, y);
	};

	pt sauron = pt(p[n - 1].x, p[n - 1].y + h);

	double polyline_length = 0;
	double covered_length = 0;

	int last = -1;
	for (int i = n - 1; i > 0; i--) {
		if (last != -1) {
			//check if line from (xn, yn + h) to (x_last, y_last)
			//intersects line connecting (x_i, y_i), (x_(i - 1), y_(i - 1))
			if (area(p[i - 1], p[last], sauron) >= 0) {
				auto inter = intersection(p[i - 1], p[i], p[last], sauron);
				covered_length += dist(inter, point<double>(p[i]));
				last = -1;
			} else {
				covered_length += dist(p[i], p[i - 1]);
			}
		} else if (area(p[i - 1], p[i], sauron) < 0) {
			last = i;
			covered_length += dist(p[i], p[i - 1]);
		}
		polyline_length += dist(p[i], p[i - 1]);
	}

	cout << polyline_length - covered_length << '\n';
	return 0;
}