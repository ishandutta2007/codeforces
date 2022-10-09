#include <bits/stdc++.h>

const int N = 55;
const long long inf = 1ll << 60;
long long dp[N][N][N][2][2][2][2], f[N][2], c[N];
int n, k;

void upd(long long &x, long long y) { x = std::min(x, y); }

long long shift(long long x, long long w) {
	return (x >> w) << w;
}

long long dfs(int x, int l, int r, int o1, int o2, int o3, int o4) {
	if (x == k) {
		return l > r ? 0 : inf;
	}
	long long &s = dp[x][l][r][o1][o2][o3][o4];
	if (s != -1)
		return s;
	s = inf;
	long long coef = o2 ^ o4 ^ (f[l - 1][o1] >> x & 1) ^ (f[r + 1][o3] >> x & 1);
	long long ret = dfs(x + 1, l, r, o1, 0, o3, 0);
	if (l > 1 && r < n && coef)
		ret += c[x];	
	upd(s, ret);
	for (int i = l; i <= r; ++i) 
		for (int j = 0; j < 2; ++j) {
			if (!x) {
				long long lf = dfs(0, l, i - 1, o1, o2, j, 0);
				long long rf = dfs(x, i + 1, r, j, 0, o3, o4);
				upd(s, lf + rf);
			}
			long long wl = f[i][j] ^ (1ll << x);
			wl = shift(wl, x);
			long long wr = wl | ((1ll << x) - 1);
			if (f[i][0] <= wl && wr <= f[i][1])	{
				long long lf = dfs(x, l, i - 1, o1, o2, j, 1);
				long long rf = dfs(x, i + 1, r, j, 1, o3, o4);
				upd(s, lf + rf);
			}
		}
	return s;
}

template <int T>
struct fast_io {
	char p[T], *p1, *p2, q[T], *q1, *q2;
	fast_io() {
		p1 = p2 = p; q1 = q; q2 = q + T;
	}
	char gc() {
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}
	void pc(char ch) {
		if (q1 == q2) {
			fwrite(q, 1, T, stdout);
			q1 = q;
		}
		*q1++ = ch;
	}
	~fast_io() {
		fwrite(q, 1, q1 - q, stdout);
	}
};
fast_io<1024768> io;

long long read() {
	long long r = 0, neg = 1;
	char ch;
	do {
		ch = io.gc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r * neg;
}

void write(long long x) {
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) write(x / 10);
	io.pc(48 + x % 10);
}

void output(long long x, char ch = ' ') {
	write(x);
	io.pc(ch);
}
int main() {
	n = read(), k = read();
	for(int i = 1; i <= n; ++i) 
		for (int j = 0; j < 2; ++j)
			f[i][j] = read();
	for (int i = 0; i < k; ++i)
		c[i] = read();
	memset(dp, -1, sizeof dp);
	output(dfs(0, 1, n, 0, 0, 0, 0), '\n');
}