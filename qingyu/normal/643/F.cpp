#include <bits/stdc++.h>

const int N = 505;

uint32_t n, p, q;

template<int T>
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
		if (q1 == q2)
		{
			fwrite(q, 1, T, stdout);
			q1 = q;
		}
		*q1++ = c;
	}

	~fast_io()
	{
		fwrite(q, 1, q1 - q, stdout);
	}
};

fast_io<2000000> io;

inline long long read()
{
	long long r = 0, neg = 1;
	char ch;
	do
	{
		ch = io.gc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r * neg;
}

inline int read(char *s)
{
	char ch;
	int len = 0;
	do ch = io.gc(); while (!isalpha(ch));
	do *s++ = ch, ch = io.gc(), ++len; while (isalpha(ch));
	*s = 0;
	return len;
}

inline void putint(long long x)
{
	if (x < 0)
	{
		io.pc('-');
		putint(-x);
		return;
	}
	if (x / 10) putint(x / 10);
	io.pc(48 + x % 10);
}


inline void output(long long x, char ch = ' ')
{
	putint(x);
	io.pc(ch);
}

uint32_t a[N], b[N];
inline void mul(uint32_t *x, uint32_t *y)
{
	uint32_t z[N];
	memset(z, 0, p + 1 << 2);
	for (int i = 0; i <= p; ++i)
		for (int j = 0; i + j <= p; ++j)
			z[i + j] += x[i] * y[j];
	memcpy(x, z, p + 1 << 2);
}

inline void fastpow(uint32_t *a, uint32_t *b, int p)
{
	while (p)
	{
		if (p & 1) mul(b, a);
		mul(a, a);
		p >>= 1;
	}
}

int main()
{
	n = read(), p = read(), q = read();
	p = std::min(p, n - 1);
	a[0] = a[1] = b[0] = 1;
	fastpow(a, b, n);
	uint32_t ans = 0;
	for (int i = 1; i <= q; ++i)
	{
		uint32_t res = 0, w = 1, *t = b;
		int j = 0;
		for (; j + 5 <= p; j += 6)
		{
			res += w * *t++, w *= i;
			res += w * *t++, w *= i;
			res += w * *t++, w *= i;
			res += w * *t++, w *= i;
			res += w * *t++, w *= i;
			res += w * *t++, w *= i;
		}
		for (; j <= p; ++j)
		{
			res += w * *t++, w *= i;
		}
		ans ^= res * i;
	}
	output(ans);
}