#include <bits/stdc++.h>

const int N = 3e5 + 50;
const int mod = 1e9 + 9;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline void upd(int &x, int y) { x = inc(x, y); }
inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }

int n, q, f[N], S[N], sum[N << 2];

struct matrix_t
{
	int x00, x01, x10, x11;
	matrix_t()
	{
		x00 = x01 = x10 = x11 = 0;
	}
	inline matrix_t operator*(const matrix_t &rhs) const
	{
		matrix_t r;
		r.x00 = (1ll * x00 * rhs.x00 + 1ll * x01 * rhs.x10) % mod;
		r.x01 = (1ll * x00 * rhs.x01 + 1ll * x01 * rhs.x11) % mod;
		r.x10 = (1ll * x10 * rhs.x00 + 1ll * x11 * rhs.x10) % mod;
		r.x11 = (1ll * x10 * rhs.x01 + 1ll * x11 * rhs.x11) % mod;
		return r;
	}
};
inline int fib(int a, int b, int p) // calc X^{p-2} * v * [1, 0]
{
	if (p == 1) return a;
	if (p == 2) return b;
	if (p <= n + 10) return inc(mul(b, f[p - 1]), mul(a, f[p - 2]));
	p -= 2;
	matrix_t R, X; 
	R.x00 = R.x11 = X.x00 = X.x01 = X.x10 = 1;
	while (p)
	{
		if (p & 1) R = R * X;
		X = X * X;
		p >>= 1;
	}
	return inc(mul(b, R.x00), mul(a, R.x01));
}

inline void get_ab(int p, int &a, int &b)
{
	if (p == 1) a = 1, b = 2;
	else
	{
		matrix_t R, X; 
		R.x00 = R.x11 = X.x00 = X.x01 = X.x10 = 1;
		while (p)
		{
			if (p & 1) R = R * X;
			X = X * X;
			p >>= 1;
		}
		b = inc(R.x00, R.x01);
		a = inc(R.x10, R.x11);
	}
}

inline int su(int a, int b, int n)
{
	return dec(fib(a, b, n + 2), b);
}

inline int su(int a, int b, int l, int r)
{
	return dec(su(a, b, r), su(a, b, l - 1));
}

struct fib_t
{
	int a, b;
	fib_t() : a(0), b(0) { }
} t[N << 2], s[N << 2];

inline void push_up(int o)
{
	sum[o] = inc(sum[lc(o)], sum[rc(o)]);
}

inline void maintain(int o, int l, int r, int a, int b)
{
	upd(t[o].a, a); upd(t[o].b, b);
	upd(sum[o], su(a, b, 1, r - l + 1));
}

inline void push_down(int o, int l, int r)
{
	if (t[o].a || t[o].b)
	{
		const int mid = l + r >> 1;
		maintain(lc(o), l, mid, t[o].a, t[o].b);
		maintain(rc(o), mid + 1, r, fib(t[o].a, t[o].b, mid - l + 2), fib(t[o].a, t[o].b, mid - l + 3));
		t[o].a = t[o].b = 0;
	}
}

void modify(int o, int l, int r, int ql, int qr, int a, int b)
{
	if (ql <= l && r <= qr)
	{
		maintain(o, l, r, fib(a, b, l - ql + 1), fib(a, b, l - ql + 2));
	}
	else
	{
		const int mid = l + r >> 1;
		push_down(o, l, r);
		if (ql <= mid) modify(lc(o), l, mid, ql, qr, a, b);
		if (qr > mid) modify(rc(o), mid + 1, r, ql, qr, a, b);
		push_up(o);
	}
}

int query(int o, int l, int r, int ql, int qr)
{
	if (ql <= l && r <= qr)
	{
		return sum[o];
	}
	else
	{
		const int mid = l + r >> 1;
		push_down(o, l, r);
		int ans = 0;
		if (ql <= mid) upd(ans, query(lc(o), l, mid, ql, qr));
		if (qr > mid) upd(ans, query(rc(o), mid + 1, r, ql, qr));
		return ans;
	}
}

template <int T>
struct fast_io
{
	char *p1, *p2, *q1, *q2, p[T], q[T];
	fast_io()
	{
		p1 = p2 = p, q1 = q, q2 = q + T;
	}
	inline char gc()
	{
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}
	inline void pc(char ch)
	{
		if (q1 == q2)
		{
			fwrite(q, 1, T, stdout);
			q1 = q;
		}
		*q1++ = ch;
	}
	~fast_io()
	{
		fwrite(q, 1, q1 - q, stdout);
	}
};
fast_io<1024768> io;

inline int read()
{
	int res = 0;
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res;
}

inline int read(char *s)
{
	int len = 0; char ch;
	do ch = io.gc(); while (!isalpha(ch));
	do ++len, *s++ = ch, ch = io.gc(); while (isalpha(ch));
	*s = 0; return len;
}

inline void putint(int x)
{
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) putint(x / 10);
	io.pc(48 + x % 10);
}

inline void output(int x, char ch = ' ')
{
	putint(x);
	io.pc(ch);
}

inline void output(const char *s)
{
	while (*s) io.pc(*s++);
	io.pc(' ');
}

int main()
{
	n = read(), q = read();
	for (int i = 1; i <= n; ++i) S[i] = inc(S[i - 1], read());
	f[1] = 1, f[2] = 1; for (int i = 3; i <= n + 10; ++i) f[i] = inc(f[i - 1], f[i - 2]);
	while (q--)
	{
		int opt = read();
		if (opt == 1)
		{
			int l = read(), r = read(), a, b;
			get_ab(0, a, b);
			modify(1, 1, n, l, r, a, b);
		}
		else
		{
			int l = read(), r = read();
			output(inc(S[r], dec(query(1, 1, n, l, r), S[l - 1])), '\n');
		}
	}
	return 0;
}