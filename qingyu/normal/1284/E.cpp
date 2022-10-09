#include <bits/stdc++.h>

const int N = 5050;

int n;

struct pt {
	int64_t x, y;
} p[N];

int64_t cross(const pt &a, const pt &b) {
	return a.x * b.y - a.y * b.x;
}

inline bool operator<(const pt &a, const pt &b) {
	int _a = (a.y < 0) || (a.y == 0 && a.x > 0);
	int _b = (b.y < 0) || (b.y == 0 && b.x > 0);
	if (_a != _b) return _a < _b;
	return cross(a, b) > 0;
}

long long x[N], y[N];

inline long long sel(long long x) {
	return x * (x - 1) * (x - 2) / 6;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> x[i] >> y[i];
	long long ans = 1ll * n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4);
	for (int i = 1; i <= n; ++i) {
		int tot = 0;
		for (int j = 1; j <= n; ++j)
			if (i != j) {
				++tot;
				p[tot].x = x[j] - x[i];
				p[tot].y = y[j] - y[i];
			}
		std::sort(p + 1, p + tot + 1);
		for (int i = 1; i <= tot; ++i)
			p[tot + i] = p[i];
		int l = 1, r = tot + 1;
		for (; r <= tot + tot; ++r) {
			while ((r - l + 1) > tot || cross(p[r], p[l]) > 0) ++l;
			ans -= sel(r - l);
		}
	}
	std::cout << ans;
	return 0;
}