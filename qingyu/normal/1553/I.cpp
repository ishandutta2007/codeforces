#include <bits/stdc++.h>

const int N = 4e5 + 50;
const int mod = 998244353;
const int g = 3;
const int inv2 = (mod + 1) / 2;

int a[N], b[N], tot, fact[N], inv[N];

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }

inline int fastpow(int x, int p)
{
	int r = 1;
	while (p)
	{
		if (p & 1) r = mul(r, x);
		x = mul(x, x);
		p >>= 1;
	}
	return r;
}

struct NTT
{
	int omega[N], omegaInv[N], rev[N], len, k;
	inline void init(int n)
	{
		len = 1, k = 0;
		while (len <= n) len <<= 1, ++k;
		for (int i = 0; i < len; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
		const int t = fastpow(g, (mod - 1) / len);
		omega[0] = omegaInv[0] = 1;
		for (int i = 1; i < len; ++i) omega[i] = omegaInv[len - i] = mul(omega[i - 1], t);
	}
	inline void DFT(int *a, const int *w)
	{
		for (int i = 1; i < len; ++i) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
		for (int h = 1; h < len; h <<= 1)
			for (int t = len / (h << 1), j = 0; j < len; j += (h << 1))
			{
				const int *wn = w; int *x = a + j, *y = a + j + h;
				for (int i = j; i < j + h; ++i)
				{
					int _1 = *x, _2 = mul(*y, *wn);
					*x++ = inc(_1, _2);
					*y++ = dec(_1, _2);
					wn += t;
				}
			}
		if (w == omegaInv)
		{
			const int t = mod - (mod - 1) / len;
			for (int i = 0; i < len; ++i) a[i] = mul(a[i], t);
		}
	}
	inline void operator()(std::vector<int> &_, int op)
	{
		if (_.size() < len) _.resize(len);
		if (op == 1) DFT(_.data(), omega);
		else DFT(_.data(), omegaInv);
		assert(_.size() >= len);
	}
} ntt;

struct Poly
{
	std::vector<int> _;
	Poly(){}
	Poly(const std::vector<int> &_) : _(_) {}
	Poly(std::initializer_list<int> _) : _(_) {}
	inline int& operator[](int k)
	{
		if (_.size() <= k) _.resize(k + 1);
		return _[k];
	}
	inline int operator[](int k) const
	{
		if (_.size() <= k) return 0;
		return _[k];
	}
	inline int deg() const
	{
		return (int)_.size() - 1;
	}
	inline void print() const
	{
		for (int i = 0; i < _.size(); ++i) printf("%d ", _[i]);
		putchar('\n');
	}
};


template <int T>
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
inline int read()
{
	int res = 0;
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

inline Poly operator*(const Poly &A, const Poly &B)
{
	int d1 = A.deg(), d2 = B.deg();
	std::vector<int> a = A._, b = B._;
	ntt.init(d1 + d2 + 1);
	ntt(a, 1), ntt(b, 1);
	std::vector<int> c(ntt.len);
	for (int i = 0; i < ntt.len; ++i) c[i] = mul(a[i], b[i]);	
	ntt(c, -1);
	return Poly(c);
}

Poly f[N << 2][2][2];

inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }

void solve(int o, int l, int r)
{
	if (l == r)
	{
		f[o][0][0] = { 0, b[l] == 1 ? inv2 : 1 };
		f[o][0][1] = f[o][1][0] = f[o][1][1] = {0, 1};
	}
	else
	{
		const int mid = l + r >> 1;
		solve(lc(o), l, mid);
		solve(rc(o), mid + 1, r);
		for (int x : {0, 1})
			for (int y : {0, 1})
				for (int z : {0, 1})
				{
					auto R = f[lc(o)][x][y] * f[rc(o)][y][z];
					for (int i = y; i <= R.deg(); ++i)
						upd(f[o][x][z][i - y], R[i]);
				}
	}
}

int main()
{
	int n = read();
	fact[0] = 1;	
	for (int i = 1; i <= n; ++i) fact[i] = mul(i, fact[i - 1]);
	inv[n] = fastpow(fact[n], mod - 2);
	for (int i = n - 1; i >= 0; --i) inv[i] = mul(i + 1, inv[i + 1]);
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= n; i += a[i])
	{
		b[++tot] = a[i];
		for (int j = i; j < i + a[i]; ++j)
			if (a[i] != a[j])
			{
				output(0);
				return 0;
			}
	}
	solve(1, 1, tot);
	int ans = 0;
	for (int i = 1; i <= tot; ++i)
	{
		(tot - i & 1 ? dpu : upd)(ans, mul(fact[i], mul(f[1][0][0][i], fastpow(2, i))));
	}
	output(ans);
	return 0;
}