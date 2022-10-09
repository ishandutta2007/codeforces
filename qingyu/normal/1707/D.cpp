#include <bits/stdc++.h>

using namespace std; // i don't like it anyway...

const int N = 2050;
int n, mod, f[N][N], g[N][N], fact[N], inv[N];
int s1[N][N], h[N];
vector<int> G[N];

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

void init(int n) {
	fact[0] = 1;
	for (int i = 1; i <= n; ++i)
		fact[i] = mul(i, fact[i - 1]);
	inv[n] = fastpow(fact[n], mod - 2);
	for (int i = n - 1; i >= 0; --i)
		inv[i] = mul(i + 1, inv[i + 1]);
}

void dfs(int x, int fa = 0) {
	vector<int> son;
	for (int y : G[x]) {
		if (y != fa) {
			dfs(y, x);
			son.push_back(y);
		}
	}
	int m = son.size();
	if (x != 1) {
		for (int j = 1; j <= n; ++j) {
			std::vector<int> pre(m), suf(m);
			for (int i = 0; i < m; ++i) {
				pre[i] = mul(i == 0 ? 1 : pre[i - 1], g[son[i]][j]);
			}
			for (int i = m - 1; i >= 0; --i) {
				suf[i] = mul(i == m - 1 ? 1 : suf[i + 1], g[son[i]][j]);
			}
			for (int i = 0; i < m; ++i) {
				int lf = (i == 0 ? 1 : pre[i - 1]);
				int sf = (i == m - 1 ? 1 : suf[i + 1]);
				s1[son[i]][j] = mul(lf, sf);
			}
		}
		for (int i = 1; i <= n; ++i)
			for (int y : son)
				upd(s1[y][i], s1[y][i - 1]);
		for (int i = 1; i <= n; ++i) {
			for (int y : son) {
				upd(f[x][i], mul(f[y][i], s1[y][i - 1]));
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		int ret = 1;
		for (int y : son) {
			pud(ret, g[y][i]);
		}
		upd(f[x][i], ret);
	}
	g[x][0] = f[x][0];
	for (int i = 1; i <= n; ++i) {
		g[x][i] = inc(f[x][i], g[x][i - 1]);
	}
}

int comb(int n, int m) {
	return mul(mul(fact[n], inv[m]), inv[n - m]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> mod;
	init(n);
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	init(n);
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		h[i] = f[1][i];
		for (int j = 0; j < i; ++j)
			dpu(h[i], mul(h[j], comb(i, j)));
	}	
	for (int i = 1; i < n; ++i) {
		std::cout << h[i] << " \n"[i == n];
	}
}