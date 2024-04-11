#include <bits/stdc++.h>

typedef long long ll;
const int N = 5e5 + 50;

int n, m, same[N], tag[N], cover[N];
ll sum[N], add[N];

inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }

void push_up(int o)
{
	sum[o] = sum[lc(o)] + sum[rc(o)];
	int vl = same[lc(o)], vr = same[rc(o)];
	if (vl == vr) same[o] = vl;
	else same[o] = -1;
}
void cover_range(int o, int l, int r, int v)
{
	if (same[o] != -1)
	{
		sum[o] += 1ll * abs(same[o] - v) * (r - l + 1);
		add[o] += abs(same[o] - v);
		tag[o] = same[o] = v;
	}
	else
	{
		const int mid = l + r >> 1;
		tag[o] = -1;
		cover_range(lc(o), l, mid, v);
		cover_range(rc(o), mid + 1, r, v);
		push_up(o);
		assert(same[o] != -1);
	}
}

void maintain(int o, int l, int r, int v)
{
	tag[o] = v; same[o] = v;
}

void maintain_add(int o, int l, int r, ll v)
{
	sum[o] += 1ll * (r - l + 1) * v;
	add[o] += v;
}

void push_down(int o, int l, int r)
{
	if (tag[o] != -1)
	{
		const int mid = l + r >> 1;
		maintain(lc(o), l, mid, tag[o]);
		maintain(rc(o), mid + 1, r, tag[o]);
		tag[o] = -1;
	}
	if (add[o])
	{
		const int mid = l + r >> 1;
		maintain_add(lc(o), l, mid, add[o]);
		maintain_add(rc(o), mid + 1, r, add[o]);
		add[o] = 0;
	}
}

void build(int o, int l, int r)
{
	if (l == r) same[o] = l;
	else
	{
		const int mid = l + r >> 1;
		build(lc(o), l, mid);
		build(rc(o), mid + 1, r);
		push_up(o);
	}
}

void modify(int o, int l, int r, int ql, int qr, int v)
{
	if (ql <= l && r <= qr)
	{
		cover_range(o, l, r, v);
	}
	else
	{
		const int mid = l + r >> 1;
		push_down(o, l, r);
		if (ql <= mid) modify(lc(o), l, mid, ql, qr, v);
		if (qr > mid) modify(rc(o), mid + 1, r, ql, qr, v);
		push_up(o);
	}
}

ll query(int o, int l, int r, int ql, int qr)
{
	if (ql <= l && r <= qr) return sum[o];
	push_down(o, l, r);
	const int mid = l + r >> 1;
	ll a = 0;
	if (ql <= mid) a += query(lc(o), l, mid, ql, qr);
	if (qr > mid) a += query(rc(o), mid + 1, r, ql, qr);
	return a;
}

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
	int res = 0, neg = 1;
	char ch;
	do 
	{
		ch = io.gc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

void putll(ll x)
{
	if (x / 10) putll(x / 10);
	io.pc(48 + x % 10);
}

void output(ll x)
{
	putll(x);
	io.pc('\n');
}

int main()
{ 
	memset(tag, -1, sizeof tag); memset(cover, -1, sizeof cover);
	n = read(), m = read();
	build(1, 1, n);
	while (m--)
	{
		int o = read(), l = read(), r = read();
		if (o == 1)
		{
			int x = read();
			modify(1, 1, n, l, r, x);
		}
		else
		{
			output(query(1, 1, n, l, r)); 
		}
	}
	return 0;
}