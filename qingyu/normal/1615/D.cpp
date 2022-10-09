#include <bits/stdc++.h>

const int mod = 998244353;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); } 
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

const int N = 5e5 + 50;

int n, m, col[N], f[N], fa[N], ex[N], ey[N], ew[N];
std::vector<std::pair<int, int>> G[N];
std::vector<int> H[N];
bool ok;

void dfs(int x, int c) {
	col[x] = c;
	for (int y : H[x]) {
		if (col[y] == -1) {
			dfs(y, c);
		}
	}
}

void dfst(int x, int f) {
	fa[x] = f;
	for (auto [y, _] : G[x])
		if (y != f) {
			dfst(y, x);
		}
}

void add(int x, int y) {
	H[x].push_back(y);
	H[y].push_back(x);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		std::cin >> n >> m;
		for (int i = 1; i < n; ++i) {
			int x, y, w;
			std::cin >> x >> y >> w;
			if (x > y) std::swap(x, y);
			ex[i] = x, ey[i] = y, ew[i] = w;
			G[x].emplace_back(y, w);
			G[y].emplace_back(x, w);
			if (w != -1) {
				w = __builtin_popcount(w) % 2;
			}
			if (w == 0) {
				add(x, y);
				add(x + n, y + n);
			}
			if (w == 1) {
				add(x, y + n);
				add(y, x + n);
			}
		}
		for (int i = 1; i <= m; ++i) {
			int x, y, w;
			std::cin >> x >> y >> w;
			if (w == 0) {
				add(x, y);
				add(x + n, y + n);
			}
			else {
				add(x, y + n);
				add(x + n, y);
			}
		}
		dfst(1, 0);
		ok = true;
		for (int i = 1; i <= n + n; ++i) {
			col[i] = -1;
		}
		int tot = 0;
		for (int i = 1; i <= n + n; ++i) {
			if (col[i] == -1) {
				dfs(i, ++tot);
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (col[i] == col[i + n]) {
				ok = false;
			}
			else {
				f[i] = (col[i] < col[i + n]);
			}
		}
		if (ok) {
			puts("YES");
			for (int i = 1; i < n; ++i) {
				int x = ex[i], y = ey[i], w = ew[i];
				if (w != -1) {
					printf("%d %d %d\n", x, y, w);
				}
				else {
					w = f[x] ^ f[y];
					printf("%d %d %d\n", x, y, w);
				}
			}
		}
		else {
			puts("NO");
		}
		for (int i = 1; i <= n; ++i) G[i].clear();
		for (int i = 1; i <= n + n; ++i)
			H[i].clear();
	}
}