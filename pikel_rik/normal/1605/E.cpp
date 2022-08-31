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

	int n;
	cin >> n;

	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	vector<point<long long>> current_value(n + 1);
	for (int i = 1; i <= n; i++) {
		current_value[i] = point<long long>(a[i], 0);
	}

	constexpr int N = 1000 * 1000;

	vector<point<long long>> sum(N + 1);

	for (int i = 1; i <= n; i++) {
		point<long long> diff = (i == 1 ? point<long long>(0, 1) - current_value[i] : point<long long>(b[i], 0) - current_value[i]);
		for (int j = i; j <= n; j += i) {
			current_value[j] += diff;
		}
		if (diff.y == 0) {
			sum[0] += point<long long>(abs(diff.x), 0);
		} else {
			if (diff.y < 0) {
				diff = -diff;
			}
			if (diff.x >= 0) {
				sum[0] += diff;
			} else {
				long long cross_point = (-diff.x + diff.y - 1) / diff.y;
				sum[0] += -diff;
				if (cross_point <= N) {
					sum[cross_point] += 2 * diff;
				}
			}
		}
	}

	partial_sum(sum.begin(), sum.end(), sum.begin());

	int q;
	cin >> q;

	while (q--) {
		int x;
		cin >> x;

		cout << sum[x].x + x * sum[x].y << '\n';
	}
	return 0;
}