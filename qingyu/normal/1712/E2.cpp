#include <bits/stdc++.h>

const int N = 4e5 + 50;

long long ans[N];

std::vector<int> dv[N];

inline int lowbit(int x) { return x & -x; }

struct fenwick_t {
	int t[N];
	void add(int p, int v) {
		++p;
		for (; p < N; p += lowbit(p)) t[p] += v;
	}
	int query(int p) {
		int r = 0;
		++p;
		for (; p; p -= lowbit(p)) r += t[p];
		return r;
	}
	int query(int l, int r) {
		int ret = query(r);
		if (l) ret -= query(l - 1);
		return ret;
	}
} T;

struct query_t {
	int x, l, r, id, sgn;
	query_t(int x, int l, int r, int id, int sgn) : x(x), l(l), r(r), id(id), sgn(sgn) {

	}
	inline bool operator<(const query_t &rhs) const {
		return x < rhs.x;
	}
};

struct point_t {
	int x, y, w;
	point_t(int x, int y, int w) : x(x), y(y), w(w) {

	}
	inline bool operator<(const point_t &rhs) const {
		return x < rhs.x;
	}
};

inline long long lcm(long long x, long long y) {
	return 1ll * x / std::gcd(x, y) * y;
}

inline long long s3(long long x) {
	return x * (x - 1) / 2 * (x - 2) / 3;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::vector<point_t> pts;
	auto init = [&](int n) {
		for (int d = 1; d <= n; ++d)
			for (int i = d; i <= n; i += d)
				dv[i].push_back(d);
		for (int k = 1; k <= n / 2; ++k) {
			auto &d = dv[2 * k];
			for (int di = 0; di < d.size(); ++di) {
				if (d[di] >= k) break;
				int i = d[di], w = 0;
				for (int dj = di + 1; dj < d.size(); ++dj) {
					if (d[dj] >= k) break;
					int j = d[dj];
					if (i + j + k > lcm(lcm(i, j), k)) {
						++w;
					}
				}
				if (w) pts.emplace_back(i, k, w);
			}
		}
	};
	init(4e5);
	int q;
	std::cin >> q;
	std::vector<query_t> qu;
	for (int i = 1; i <= q; ++i) {
		int l, r;
		std::cin >> l >> r;
		qu.emplace_back(l - 1, l, r, i, 1);
		qu.emplace_back(r, l, r, i, -1);
		ans[i] = s3(r - l + 1);
	}
	std::sort(qu.begin(), qu.end());
	std::sort(pts.begin(), pts.end());
	int p = 0;
	for (auto [x, l, r, id, sgn] : qu) {
		while (p < pts.size() && pts[p].x <= x) {
			T.add(pts[p].y, pts[p].w);
			++p;
		}
		int ret = T.query(l, r);
		ans[id] += sgn * ret;
	}
	for (int i = 1; i <= q; ++i) {
		std::cout << ans[i] << '\n';
	}
	return 0;
}