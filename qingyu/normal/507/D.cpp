#include <bits/stdc++.h>

const int N = 1050;
const int K = 150;

int n, k, mod, pw10[N];
int dp[N][K][2];

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline void upd(int &x, int y) { x = inc(x, y); } 

template <long long T>
struct fast_io
{
	char p[T], q[T], * p1, * p2, * q1, * q2;
	fast_io()
	{
		p1 = p2 = p;
		q1 = q, q2 = q + T;
	}
	inline char gc()
	{
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}
	inline void pc(char c)
	{
		if (q1 == q2) q2 = (q1 = q) + fwrite(q, 1, T, stdout);
		*q1++ = c;
	}
	~fast_io()
	{
		fwrite(q, 1, q1 - q, stdout);
	}
};
fast_io<1 << 20> io;
inline long long read()
{
	long long res = 0;
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res;
}
inline void put(int64_t x)
{
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) put(x / 10);
	io.pc(48 + x % 10);
}
inline void output(int64_t x, char ch = ' ')
{
	put(x);
	io.pc(ch);
}

int main()
{
	n = read(), k = read(), mod = read();
	pw10[0] = 1;
	for (int i = 1; i <= n; ++i) pw10[i] = pw10[i - 1] * 10 % k;
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < k; ++j)
			for (int p = (i != n ? 0 : 1); p < 10; ++p)
			{
				int nj = (j + p * pw10[i - 1]) % k;
				if (nj == 0 && p != 0)
				{
					upd(dp[i][nj][1], dp[i - 1][j][0]);
				}
				else
				{
					upd(dp[i][nj][0], dp[i - 1][j][0]);
				}
				upd(dp[i][nj][1], dp[i - 1][nj][1]);			
			}
	}
	int ans = 0;
	for (int i = 0; i < k; ++i) upd(ans, dp[n][i][1]);
	output(ans, '\n');
	return 0;
}