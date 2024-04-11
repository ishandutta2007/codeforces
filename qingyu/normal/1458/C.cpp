#include<bits/stdc++.h>

typedef long long ll;
const int N = 1005;

int n, m;
int a[N][N][3], b[N][N], f[3], p[3];

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

inline int read()
{
	int r = 0, neg = 1;
	char ch;
	do
	{
		ch = io.gc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r * neg;
}

inline char readchar()
{
	char ch;
	do ch = io.gc(); while (!isalpha(ch));
	return ch;
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
	int T = read();
	while (T--)
	{
		n = read(), m = read();
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < n; ++j)
				a[i][j][0] = i, a[i][j][1] = j, a[i][j][2] = read() - 1;
		p[0] = 0, p[1] = 1, p[2] = 2;
		f[0] = f[1] = f[2] = 0;
		while (m--)
		{
			char op = readchar();
			switch (op)
			{
				case 'R':
					++f[1];
					break;
				case 'L':
					--f[1];
					break;
				case 'D':
					++f[0];
					break;
				case 'U':
					--f[0];
					break;
				case 'I':
					std::swap(f[1], f[2]), std::swap(p[1], p[2]);
					break;
				case 'C':
					std::swap(f[0], f[2]), std::swap(p[0], p[2]);
					break;
			}
		}
		for (int i = 0; i < 3; ++i) f[i] = (f[i] % n + n) % n;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				int p0 = (a[i][j][p[0]] + f[0]) % n;
				int p1 = (a[i][j][p[1]] + f[1]) % n;
				int p2 = (a[i][j][p[2]] + f[2]) % n;
				b[p0][p1] = p2;
			}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				output(b[i][j] + 1, " \n"[j == n - 1]);
	}
	return 0;
}