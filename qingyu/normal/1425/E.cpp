// By Qingyu
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#include <bits/stdc++.h>

const int mod = 1e9 + 7;
const int N = 1e5 + 50;

int n, k, a[N], d[N], min, min2, premin[N], sufmin[N];
int64_t pre[N], suf[N], p_min[N], s_m[N], p_m[N];

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
inline void putint(int64_t x)
{
	if (x / 10) putint(x / 10);
	io.pc(48 + x % 10);
}

inline void output(int64_t x, char c = ' ')
{
	putint(x);
	io.pc(c);
}

int main()
{
	n = read(), k = read();
	min = 0x3f3f3f3f, min2 = min;
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= n; ++i) 
	{
		d[i] = read();
	       	if (d[i] <= min) min2 = min, min = std::min(min, d[i]);
		else if (d[i] < min2) min2 = d[i];
	}
	premin[0] = sufmin[n + 1] = 0x3f3f3f3f;
	for (int i = n; i >= 1; --i) suf[i] = suf[i + 1] + a[i], sufmin[i] = std::min(sufmin[i + 1], d[i]);
	for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i], premin[i] = std::min(premin[i - 1], d[i]);
	for (int i = n; i >= 1; --i) s_m[i] = std::max(s_m[i + 1], suf[i] - d[i]);
	p_m[0] = -1e15;
	for (int i = 1; i <= n; ++i) p_m[i] = std::max(p_m[i - 1] + a[i], 1ll * a[i] - d[i]);
	int64_t ans = 0;
	if (k == 0)
	{
		ans = std::max(ans, s_m[1]);
		output(ans);
	}
	else if (k == 1)
	{
		int min_d = 0x3f3f3f3f;
		for (int i = 1; i < n; ++i) 
		{
			min_d = std::min(d[i], min_d);
			ans = std::max(ans, std::max(pre[i] - min_d, 0ll) + s_m[i + 1]);
		}
		for (int i = 1; i <= n - 2; ++i)
		{
			ans = std::max(ans, p_m[i] + suf[i + 2]);
		}
		output(ans);
	}
	else if (k >= 2)
	{
		ans = std::max(ans, suf[1] - premin[n - 1]);
		ans = std::max(ans, 1ll * a[n] - d[n]);
		output(ans);
	}
	return 0;
}