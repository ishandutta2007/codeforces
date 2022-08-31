#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct rational {
	static_assert(std::is_integral<T>::value, "Type must be integral");

	T a, b;
	rational(int a = 0, int b = 1) : a(a), b(b) {
		normalize();
	}

	void normalize() {
		if (b < 0) a *= -1, b *= -1;
		T d = std::abs(std::__gcd(a, b));
		a /= d, b /= d;
	}

	rational operator+() const {
		return *this;
	}

	rational operator-() const {
		return rational(-a, b);
	}

	rational &operator+=(const rational &x) {
		tie(a, b) = make_pair(a * x.b + b * x.a, b * x.b);
		return normalize(), *this;
	}

	rational &operator-=(const rational &x) {
		tie(a, b) = make_pair(a * x.b - b * x.a, b * x.b);
		return normalize(), *this;
	}

	rational &operator*=(const rational &x) {
		a *= x.a, b *= x.b;
		return normalize(), *this;
	}

	rational &operator/=(const rational &x) {
		a *= x.b, b *= x.a;
		return normalize(), *this;
	}

	friend rational operator+(const rational &x, const rational &y) {
		return rational(x) += y;
	}

	friend rational operator-(const rational &x, const rational &y) {
		return rational(x) -= y;
	}

	friend rational operator*(const rational &x, const rational &y) {
		return rational(x) *= y;
	}

	friend rational operator/(const rational &x, const rational &y) {
		return rational(x) /= y;
	}

	friend std::ostream &operator<<(std::ostream &os, const rational &x) {
		return os << x.a << '/' << x.b;
	}

	friend bool operator==(const rational &x, const rational &y) {
		return x.a == y.a && x.b == y.b;
	}

	friend bool operator!=(const rational &x, const rational &y) {
		return !(x == y);
	}

	friend bool operator<(const rational &x, const rational &y) {
		return (__int128_t)x.a * y.b < (__int128_t)x.b * y.a;
	}

	friend bool operator>(const rational &x, const rational &y) {
		return (__int128_t)x.a * y.b > (__int128_t)x.b * y.a;
	}

	friend bool operator<=(const rational &x, const rational &y) {
		return !(x > y);
	}

	friend bool operator>=(const rational &x, const rational &y) {
		return !(x < y);
	}
};

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

struct graph {
	struct edge {
		int u, v;
		edge(int u, int v): u(u), v(v) {}
	};

	int n, m;
	std::vector<edge> edges;
	std::vector<std::vector<int>> adj;

	graph(): n(), m() {}
	graph(int n, int m = 0): n(n), m(), adj(n) {
		edges.reserve(m);
	}

	int add_edge(int u, int v) {
		adj[u].push_back(m);
		adj[v].push_back(m);
		edges.emplace_back(u, v);
		return m++;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using fraction = rational<long long>;

	int n;
	cin >> n;

	vector<point<fraction>> a(n);
	vector<fraction> slopes(2 * n);
	for (int i = 0, x, y; i < n; i++) {
		cin >> x >> y, a[i].x = fraction(x, y);
		cin >> x >> y, a[i].y = fraction(x, y);
		slopes[2 * i] = a[i].y / (1 + a[i].x);
		slopes[2 * i + 1] = (1 + a[i].y) / a[i].x;
	}

	sort(slopes.begin(), slopes.end());
	slopes.erase(unique(slopes.begin(), slopes.end()), slopes.end());
	int m = slopes.size();

	graph g(m, n);
	for (int i = 0; i < n; i++) {
		auto slope1 = a[i].y / (1 + a[i].x);
		int idx1 = lower_bound(slopes.begin(), slopes.end(), slope1) - slopes.begin();

		auto slope2 = (1 + a[i].y) / a[i].x;
		int idx2 = lower_bound(slopes.begin(), slopes.end(), slope2) - slopes.begin();

		g.add_edge(idx1, idx2);
	}

	vector<bool> visited(m);
	vector<int> matched(n, -1);

	auto dfs = [&](int u, const auto &self) -> int {
		if (visited[u])
			return -1;
		visited[u] = true;

		for (int i : g.adj[u]) {
			if (matched[i] == -1) {
				matched[i] = n + u;
			}
		}

		for (int i : g.adj[u]) {
			if (matched[i] == n + u) {
				int v = u ^ g.edges[i].u ^ g.edges[i].v;
				int j = self(v, self);
				if (j != -1) {
					matched[i] = j;
					matched[j] = i;
				}
			}
		}

		int j = -1;
		for (int i : g.adj[u]) {
			if (matched[i] == n + u) {
				if (j == -1) {
					j = i;
					matched[i] = -1;
				} else {
					matched[j] = i;
					matched[i] = j;
					j = -1;
				}
			}
		}
		return j;
	};

	for (int i = 0; i < m; i++) {
		dfs(i, dfs);
	}

	int c = (n - count(matched.begin(), matched.end(), -1)) / 2;
	cout << c << '\n';
	for (int i = 0; i < n; i++) {
		if (matched[i] != -1 && matched[i] < i) {
			cout << matched[i] + 1 << ' ' << i + 1 << '\n';
		}
	}
	return 0;
}