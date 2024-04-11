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

	point operator+(const point &p) { return point(x + p.x, y + p.y); }
	point operator-(const point &p) { return point(x - p.x, y - p.y); }
	point operator*(const T &val) { return point(x * val, y * val); }
	point operator/(const T &val) { return point(x / val, y / val); }

	friend point operator*(const T &val, const point &p) { return point(val * p.x, val * p.y); }
	friend bool operator<(const point &a, const point &b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }

	bool operator==(const point &p) const {
		return x == p.x && y == p.y;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<point<int>> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;

	vector<int> p(n);
	iota(p.begin(), p.end(), 0);

	sort(p.begin(), p.end(), [&](int i, int j) {
		return a[i] < a[j];
	});

	auto dist = [&](int i, int j) -> long long {
		auto diff = a[i] - a[j];
		return (long long)diff.x * diff.x + (long long)diff.y * diff.y;
	};

	for (int i = 0; i < n - 1; i++) {
		int best = i + 1;
		for (int j = i + 2; j < n; j++) {
			if (dist(p[i], p[j]) > dist(p[i], p[best])) {
				best = j;
			}
		}
		swap(p[i + 1], p[best]);
	}

	for (int i = 0; i < n; i++) cout << p[i] + 1 << ' '; cout << '\n';
	return 0;
}