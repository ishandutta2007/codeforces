#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>

constexpr int N = 2e5 + 50;

int n, q, a[N], b[N];

inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }

struct Basis
{
	unsigned a[30], siz;
	Basis() { memset(a, 0, sizeof a); siz = 0; }
	Basis(unsigned v)
	{
		memset(a, 0, sizeof a); siz = 0;
		for (int i = 29; i >= 0; --i)
			if (v >> i & 1)
			{
				++siz;
				a[i] = v;
				break;
			}
	}
	inline void insert(unsigned v)
	{
		for (int i = 29; i >= 0; --i)
		{
			if (v >> i & 1)
			{
				if (a[i]) v ^= a[i];
				else
				{
					a[i] = v, ++siz;
					break;
				}
			}
		}
	}
};

inline Basis operator+(const Basis &x, const Basis &y)
{
	if (x.siz == 0) return y;
	if (y.siz == 0) return x;
	if (x.siz == 30) return x;
	if (y.siz == 30) return y;
	Basis z = x;
	for (int i = 29; i >= 0; --i)
	{
		if (y.a[i])
		{
			if (z.a[i]) z.insert(y.a[i]);
			else z.a[i] = y.a[i], ++z.siz;
			if (z.siz == 30) break;
		}
	}
	return z;
}

struct Seg1
{
	unsigned sum[N << 2];
	inline void push_down(int o)
	{
		if (sum[o])
		{
			sum[lc(o)] ^= sum[o];
			sum[rc(o)] ^= sum[o];
			sum[o] = 0;
		}
	}
	void build(int o, int l, int r)
	{
		if (l == r) sum[o] = a[l];
		else
		{
			const int mid = l + r >> 1;
			build(lc(o), l, mid);
			build(rc(o), mid + 1, r);
		}
	}
	void modify(int o, int l, int r, int ql, int qr, unsigned v)
	{
		if (ql <= l && r <= qr) sum[o] ^= v;
		else
		{
			const int mid = l + r >> 1;
			if (ql <= mid) modify(lc(o), l, mid, ql, qr, v);
			if (qr > mid) modify(rc(o), mid + 1, r, ql, qr, v);
		}
	}
	int query(int o, int l, int r, int p)
	{
		if (l == r) return sum[o];
		push_down(o);
		const int mid = l + r >> 1;
		if (p <= mid) return query(lc(o), l, mid, p);
		else return query(rc(o), mid + 1, r, p);
	}
} T1;

struct Seg2
{
	Basis tree[N << 2];
	inline void push_up(int o)
	{
		tree[o] = tree[lc(o)] + tree[rc(o)];
	}
	void build(int o, int l, int r)
	{
		if (l == r) tree[o] = Basis(b[l]);
		else
		{
			const int mid = l + r >> 1;
			build(lc(o), l, mid);
			build(rc(o), mid + 1, r);
			push_up(o);
		}
	}
	void modify(int o, int l, int r, int p)
	{
		if (l == r) tree[o] = Basis(b[l]);
		else
		{
			const int mid = l + r >> 1;
			if (p <= mid) modify(lc(o), l, mid, p);
			else modify(rc(o), mid + 1, r, p);
			push_up(o);
		}
	}
	Basis query(int o, int l, int r, int ql, int qr)
	{
		if (ql <= l && r <= qr) return tree[o];
		const int mid = l + r >> 1;
		Basis z;
		if (ql <= mid) z = query(lc(o), l, mid, ql, qr);
		if (qr > mid) z = z + query(rc(o), mid + 1, r, ql, qr);
		return z;
	}
} T2;

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

int main()
{
	n = read(), q = read();
	for (int i = 1; i <= n; ++i) a[i] = read(), b[i] = a[i] xor a[i - 1];
	T1.build(1, 1, n); T2.build(1, 1, n);
	for (int i = 1; i <= q; ++i)
	{
		int o = read(), l = read(), r = read();
		if (o == 1)
		{
			int v = read();
			T1.modify(1, 1, n, l, r, v);
			b[l] ^= v; T2.modify(1, 1, n, l);
			if (r != n) b[r + 1] ^= v, T2.modify(1, 1, n, r + 1);
		}
		else
		{
			if (l == r)
			{
				puts(T1.query(1, 1, n, l) ? "2" : "1");
			}
			else
			{
				printf("%d\n", 1 << (T2.query(1, 1, n, l + 1, r) + Basis(T1.query(1, 1, n, l)) ).siz);
			}
		}
	}
	return 0;

}