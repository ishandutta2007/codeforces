#include <bits/stdc++.h>

const int N = 8005;
const int mod = 1e9 + 7;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

int f[2][N], g[N], h[N], *dp[2][N];
int head[N], nxt[N << 1], ver[N << 1], siz[N], cnt;
int fact[N], inv[N];
int n;

inline int fastpow(int x, int p) {
	int r = 1;
	while (p) {
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

inline int comb(int n, int m) {
	if (n < m) return 0;
	return mul(mul(fact[n], inv[m]), inv[n - m]);
}

inline void add(int u, int v) {
	nxt[++cnt] = head[u];
	ver[cnt] = v;
	head[u] = cnt;
}
void dfs(int x, int fa = -1) {
	siz[x] = 1;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y != fa) {
			dfs(y, x);
			siz[x] += siz[y];
		}
	}
}
void solve(int x, int fa = -1) {

	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y != fa) {
			solve(y, x);
		}
	}
	dp[0][x] = new int[siz[x] + 1];
	dp[1][x] = new int[siz[x] + 1];
	dp[0][x][1] = dp[1][x][1] = 1;
	int sz = 1;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (y != fa) {
			int t = sz + siz[y];
			for (int s = 1; s <= t; ++s)
				f[0][s] = f[1][s] = 0;
			for (int u = 1; u <= sz; ++u)
				for (int v = 1; v <= siz[y]; ++v) {
					upd(f[0][u + v], mul(dp[0][x][u], dp[1][y][v]));
					upd(f[1][u + v], mul(dp[1][x][u], dp[1][y][v]));
					upd(f[0][u + v - 1], mul(dp[0][x][u], dp[0][y][v]));
					upd(f[1][u + v - 1], mul(dp[1][x][u], dp[0][y][v]));
					upd(f[1][u + v - 1], mul(dp[0][x][u], dp[1][y][v]));
				}
			sz += siz[y];
			for (int s = 1; s <= t; ++s) {
				dp[0][x][s] = f[0][s];
				dp[1][x][s] = f[1][s];
			}
			delete[] dp[0][y];
			delete[] dp[1][y];
		}
	}
}

template <long long T>
struct fast_io {
	char p[T], q[T], * p1, * p2, * q1, * q2;
	fast_io() {
		p1 = p2 = p;
		q1 = q, q2 = q + T;
	}
	inline char gc() {
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}
	inline void pc(char c) {
		if (q1 == q2) q2 = (q1 = q) + fwrite(q, 1, T, stdout);
		*q1++ = c;
	}
	~fast_io() {
		fwrite(q, 1, q1 - q, stdout);
	}
};
fast_io<1 << 20> io;
inline long long read() {
	long long res = 0, neg = 1;
	char ch;
	do  {
		ch = io.gc();
		if (ch == '-') neg = -1;
	}	while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}
inline char rc() {
	char ch;
	do ch = io.gc(); while (!isalpha(ch));
	return ch;
}
inline void put(int64_t x) {
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) put(x / 10);
	io.pc(48 + x % 10);
}
inline void output(int64_t x, char ch = ' ') {
	put(x);
	io.pc(ch);
}
int main() {
	n = read();
	for (int i = 1; i < n; ++i) {
		int u = read(), v = read();
		add(u, v);
		add(v, u);
	}
	dfs(1);
	solve(1);
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= n; ++i)
		fact[i] = mul(i, fact[i - 1]);
	inv[n] = fastpow(fact[n], mod - 2);
	for (int i = n - 1; i >= 0; --i)
		inv[i] = mul(i + 1, inv[i + 1]);
	int qq = 1ll * fact[n - 1] * inv[n] % mod;
	for (int i = 1; i <= n; ++i) {
		g[n - i] = 1ll * dp[1][1][i] * qq % mod;
		qq = 1ll * qq * n % mod;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			(j - i & 1 ? dpu : upd)(h[i], mul(g[j], comb(j, i)));
		}	
	}
	for (int i = 0; i < n; ++i) output(h[i]);
	return 0;
}