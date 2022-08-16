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

	using pt = point<long long>;

	int n;
	cin >> n;

	pt zero = pt(0, 0);

	pt p1, p2;
	cin >> p1.x >> p1.y >> p2.x >> p2.y;

	long long det = p1.x * p2.y - p2.x * p1.y;
	if (abs(det) != n) {
		return cout << "NO\n", 0;
	}

	pt p3 = p1 + p2;

	int mxy = max({0ll, p1.y, p2.y, p3.y});
	int mny = min({0ll, p1.y, p2.y, p3.y});

	auto within_range = [&](int x, int l, int r) -> bool {
		return min(l, r) <= x && x <= max(l, r);
	};

	auto intersection = [&](int y, const pt &p, const pt &q) -> double {
		return p.x + (double)(q.x - p.x) / (q.y - p.y) * (y - p.y);
	};

	auto area = [&](const pt &a, const pt &b, const pt &c) -> long long {
		return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
	};

	auto inside = [&](const pt &p) -> bool {
		if (area(p, p1, p3) == 0 || area(p, p2, p3) == 0) {
			return false;
		}
		bool positive = false, negative = false;
		positive |= area(p, zero, p1) > 0;
		negative |= area(p, zero, p1) < 0;

		positive |= area(p, p1, p3) > 0;
		negative |= area(p, p1, p3) < 0;

		positive |= area(p, p3, p2) > 0;
		negative |= area(p, p3, p2) < 0;

		positive |= area(p, p2, zero) > 0;
		negative |= area(p, p2, zero) < 0;
		return !(positive && negative);
	};

	vector<pt> ans;
	ans.reserve(n);

	for (int y = mny; y <= mxy; y++) {
		double mn = 1e8;
		double mx = -1e8;
		if (p1.y != 0 && within_range(y, 0, p1.y)) {
			mx = max(mx, intersection(y, zero, p1));
			mn = min(mn, intersection(y, zero, p1));
		}
		if (p2.y != 0 && within_range(y, 0, p2.y)) {
			mx = max(mx, intersection(y, zero, p2));
			mn = min(mn, intersection(y, zero, p2));
		}
		if (p1.y != p3.y && within_range(y, p1.y, p3.y)) {
			mx = max(mx, intersection(y, p1, p3));
			mn = min(mn, intersection(y, p1, p3));
		}
		if (p2.y != p3.y && within_range(y, p2.y, p3.y)) {
			mx = max(mx, intersection(y, p2, p3));
			mn = min(mn, intersection(y, p2, p3));
		}

		if (mn == 1e8) {
			continue;
		}

		int mn_x = round(ceil(mn)) - 2, mx_x = round(floor(mx)) + 2;
		for (int x = mn_x; x <= mx_x; x++) {
			pt p = pt(x, y);
			if (inside(p)) {
				ans.emplace_back(p);
			}
		}
	}

	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << ans[i].x << ' ' << ans[i].y << '\n';
	}
	return 0;
}