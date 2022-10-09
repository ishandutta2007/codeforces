#include <bits/stdc++.h>

const int N = 1e6 + 50;

int A[N], B[N];

template<int T>
struct fast_io
{
	char p[T], q[T], *p1, *p2, *q1, *q2;

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

inline int64_t read()
{
	int64_t r = 0, neg = 1;
	char ch;
	do
	{
		ch = io.gc();
		if (ch == '-') neg = -1;
	}
	while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r * neg;
}

inline void putint(int x)
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

inline void output(int x, char ch = ' ')
{
	putint(x);
	io.pc(ch);
}
int main()
{
	int a = read(), b = read(), k = read();
	int n = a + b;
	bool check=false;
	if (!k)
	{
		for (int i = 1; i <= b; ++i) A[i] = B[i] = 1;
		for (int i = b + 1; i <= n; ++i) A[i] = B[i] = 0;
		puts("Yes");
		for (int i = 1; i <= n; ++i) putchar(48 + A[i]); putchar('\n');
		for (int i = 1; i <= n; ++i) putchar(48 + B[i]); putchar('\n');
	}
	else if (b == 1 || a == 0 || a + b < k + 2)
	{
		puts("No");
	}
	else
	{
		A[1] = A[2] = B[1] = B[k + 2] = 1;
		int ra = a - 1, rb = b - 2;
		for (int i = 3; i < k + 2; ++i)
			if (ra)
			{
				--ra;
			}
			else
			{
				A[i] = B[i] = 1;
				--rb;
			}
		for (int i = k + 3; i <= n; ++i)
		{
			if (ra) --ra;
			else
			{
				A[i] = B[i] = 1;
				--rb;
			}
		}
		puts("Yes");
		for (int i = 1; i <= n; ++i) putchar(48 + A[i]); putchar('\n');
		for (int i = 1; i <= n; ++i) putchar(48 + B[i]); putchar('\n');
	} 
}