#include <bits/stdc++.h>

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

int n;
long long a[5005], b[5005], f[5005];
long long ans;

long long sum(int l, int r)
{
	assert(l - 1 <= r);
	return f[r] - f[l - 1];
}

int main()
{
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= n; ++i) b[i] = read();
	for (int i = 1; i <= n; ++i) f[i] = f[i - 1] + a[i] * b[i];
	ans = f[n];
	for (int mid = 1; mid <= n; ++mid)
	{
		int l = mid, r = mid; long long rev = a[l] * b[l];
	ans = std::max(ans, sum(1, l - 1) + sum(r + 1, n) + rev);

		while (l - 1 >= 1 && r + 1 <= n)
		{
			--l, ++r; rev += a[l] * b[r] + a[r] * b[l];
			ans = std::max(ans, sum(1, l - 1) + sum(r + 1, n) + rev);
		}
	}
	for (int mid = 1; mid < n; ++mid)
	{
		int l = mid, r = mid + 1; long long rev = a[l] * b[r] + a[r] * b[l];
	ans = std::max(ans, sum(1, l - 1) + sum(r + 1, n) + rev);

		while (l - 1 >= 1 && r + 1 <= n)
		{
			--l, ++r; rev += a[l] * b[r] + a[r] * b[l];
			ans = std::max(ans, sum(1, l - 1) + sum(r + 1, n) + rev);
		}
	}
	output(ans);
	return 0;
}