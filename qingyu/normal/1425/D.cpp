// By Qingyu
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#include <bits/stdc++.h>

const int mod = 1e9 + 7;
const int N = 3005;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }  
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline int fastpow(int x, int p)
{
	int r = 1;
	while (p)
	{
		if (p & 1) r = mul(r, x);
		x = mul(x, x);
		p >>= 1;
	}
	return r;
}

int n, m, r, fact[N], inv[N];
int S[N][N];
std::vector<int> x, y, w, nt;

template <int T>
struct fast_io
{
	char ib[T], ob[T], * p1, * p2, * q1, * q2;
	fast_io()
	{
		p1 = p2 = ib;
		q1 = ob;
		q2 = ob + T;
	}
	inline char gc()
	{
		return p1 == p2 && (p2 = (p1 = ib) + fread(ib, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}
	inline void pc(char ch)
	{
		if (q1 == q2) q2 = (q1 = ob) + fwrite(ob, 1, T, stdout);
		*q1++ = ch;
	}
	~fast_io()
	{
		fwrite(ob, 1, q1 - ob, stdout);
	}
};
fast_io<1000000> io;

inline int read()
{
	int res = 0;
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res;
}
inline void readstr(char *s)
{
	char ch;
	do ch = io.gc(); while (!isalpha(ch));
	do *s++ = ch, ch = io.gc(); while (isalpha(ch));
}
inline void putint(int x)
{
	if (x / 10) putint(x / 10);
	io.pc(48 + x % 10);
}

inline void output(int x, char c = ' ')
{
	putint(x);
	io.pc(c);
}

inline int comb(int n, int m)
{
	if (n < m) return 0;
	if (m < 0) return 0;
	return mul(mul(fact[n], inv[m]), inv[n - m]);
}

inline int sum(int x1, int y1, int x2, int y2)
{
	if (x1 > x2) return 0;
	if (y1 > y2) return 0;
	if (x1 <= 0) x1 = 1;
	if (y1 <= 0) y1 = 1;
	if (x2 >= N) x2 = N - 1;
	if (y2 >= N) y2 = N - 1;
	return S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1];
}

inline int in(int x, int y)
{
	return sum(x - r, y - r, x + r, y + r);
}

int main()
{
	n = read(), m = read(), r = read();
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = mul(i, fact[i - 1]);
	inv[n] = fastpow(fact[n], mod - 2);
	for (int i = n - 1; i >= 0; --i) inv[i] = mul(i + 1, inv[i + 1]);
	for (int i = 0; i < n; ++i)
	{
		x.emplace_back(read());
		y.emplace_back(read());
		w.emplace_back(read());
		++S[x.back()][y.back()];
	}
	for (int i = 1; i < N; ++i)
		for (int j = 1; j < N; ++j)
			S[i][j] = S[i][j] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
	for (int i = 0; i < n; ++i) nt.emplace_back(in(x[i], y[i]));
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			int t = mul(w[i], w[j]);
			int x1 = std::max(x[i], x[j]) - r;
			int y1 = std::max(y[i], y[j]) - r;
			int x2 = std::min(x[i], x[j]) + r;
			int y2 = std::min(y[i], y[j]) + r;
			int inside_cnt = sum(x1, y1, x2, y2);
			
			// Case 1: inside only
			int case1 = dec(comb(n, m), comb(n - inside_cnt, m));
			// Case 2: outter inside
			int case2 = comb(n - inside_cnt, m);
			case2 = dec(case2, comb(n - (nt[i]), m));
			case2 = dec(case2, comb(n - (nt[j]), m));
			case2 = inc(case2, comb(n - (nt[i] + nt[j] - inside_cnt), m));

			ans = inc(ans, mul(t, inc(case1, case2)));
		}
	output(ans);
	return 0;
}