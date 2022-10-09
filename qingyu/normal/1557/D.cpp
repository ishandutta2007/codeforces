#include <bits/stdc++.h>

const int N = 1e6 + 50;
const int inf = 0x3f3f3f3f;
std::pair<int, int> infp = std::make_pair(inf, -2);

inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }


std::pair<int, int> min[N << 2], tag[N << 2];

inline void maintain(int o, int l, int r, auto v)
{
	min[o] = std::min(min[o], v);
	tag[o] = std::min(tag[o], v);
}

inline void push_up(int o)
{
	min[o] = std::min(min[lc(o)], min[rc(o)]);
}

inline void push_down(int o, int l, int r)
{
	if (tag[o] <= infp)
	{
		const int mid = l + r >> 1;
		maintain(lc(o), l, mid, tag[o]);
		maintain(rc(o), mid + 1, r, tag[o]);
		tag[o] = infp;
	}
}

void modify(int o, int l, int r, int ql, int qr, auto v)
{
	if (ql <= l && r <= qr)
	{
		maintain(o, l, r, v);
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

auto query(int o, int l, int r, int ql, int qr)
{
	if (ql <= l && r <= qr) return min[o];
	const int mid = l + r >> 1;
	std::pair<int,int> w = std::make_pair(0x3f3f3f3f, -1);
	push_down(o, l, r);
	if (ql <= mid) w = std::min(w, query(lc(o), l, mid, ql, qr));
	if (qr > mid) w = std::min(w, query(rc(o), mid + 1, r, ql, qr));
	return w;
}

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

int buc[N], tot, f[N], pre[N];
std::vector<std::pair<int,int>> vecs[N];
bool ok[N];

int main()
{
	for (int i = 1; i < N; ++i) min[i] = tag[i] = infp;
	memset(f, 0x3f, sizeof f);
	int n = read(), m = read();
	for (int i = 1; i <= m; ++i)
	{
		int w = read(), l = read(), r = read();
		vecs[w].emplace_back(l, r);
		buc[++tot] = l, buc[++tot] = r;
	}
	std::sort(buc + 1, buc + tot + 1);
	tot = std::unique(buc + 1, buc + tot + 1) - (buc + 1);
	for (int i = 1; i <= n; ++i)
		for (auto &[l, r] : vecs[i])
		{
			l = std::lower_bound(buc + 1, buc + tot + 1, l) - buc;
			r = std::lower_bound(buc + 1, buc + tot + 1, r) - buc;
		}
	modify(1, 1, tot, 1, tot, std::make_pair(0, 0));
	f[1] = 0;
	for (auto [l, r] : vecs[1])
	{
		modify(1, 1, tot, l, r, std::make_pair(-1, 1));
	}
	vecs[n + 1].emplace_back(1, tot);
	for (int i = 2; i <= n + 1; ++i)
	{
		int min = 0, trans = 0;
		for (auto [l, r] : vecs[i])
		{
			auto p = query(1, 1, tot, l, r);
			if (min > p.first)
			{
				min = p.first;
				trans = p.second;
			}
			//min = std::min(min, query(1, 1, tot, l, r));

		}
		f[i] = i - 1 + min;
		pre[i] = trans;
		for (auto [l, r] : vecs[i])
		{
			modify(1, 1, tot, l, r, std::make_pair(f[i] - i, i));
		}
	}
	int j = pre[n + 1];
	while (j)
	{
		ok[j] = true;
		j = pre[j];
	}
	printf("%d\n", f[n + 1]);
	for (int i = 1; i <= n; ++i) if (!ok[i]) printf("%d ", i);
	return 0;
}