#include <bits/stdc++.h>

const int mod = 998244353;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

inline int fastpow(int x, int p) {
	int r = 1;
	while (p) {
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

const int N = 1e6 + 50;
int n, d, f[N], siz[N];
std::set<std::pair<int, int>> set;

inline int find(int x) {
	while (x != f[x])
		x = f[x] = f[f[x]];
	return x;
}

inline void merge(int x, int y) {
	x = find(x), y = find(y);
	set.erase(std::make_pair(siz[x], x));
	set.erase(std::make_pair(siz[y], y));
	f[x] = y; siz[y] += siz[x]; siz[x] = 0;
	set.emplace(siz[y], y);
	assert(find(x) == y);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		f[i] = i;
		siz[i] = 1;
		set.emplace(1, i);
	}
	int fo = 0;
	for (int i = 1; i <= d; ++i) {
		int x, y;
		std::cin >> x >> y;
		x = find(x), y = find(y);
		if (x == y) ++fo;
		else merge(x, y);
		int ans = 0, t = fo;
		for (auto it = set.rbegin(); it != set.rend() && t >= 0; --t, ++it) {
			ans += it->first;
		}
		printf("%d\n", ans - 1);
	}

	return 0;
}