// By Qingyu
#pragma GCC optimize(3)
#include <bits/stdc++.h>

typedef long long ll;
constexpr int mod = 998244353;
constexpr int inv2 = (mod + 1) / 2;
const int N = 6e5 + 50;
const int g = 3;

inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }  
inline int mul(int x, int y) { return 1ll * x * y % mod; }
struct Math
{
	int fact[N], factinv[N], inv_e[N];
	inline int fastpow(int x, ll p)
	{
		int res = 1; 
		while (p)
		{
			if (p & 1) res = mul(res, x);
			x = mul(x, x);
			p >>= 1;
		}
		return res;
	}
	inline int inv(int x)
	{
		if (x < N) return inv_e[x];
		return fastpow(x, mod - 2);
	}
	Math()
	{
		fact[0] = factinv[0] = inv_e[0] = 1;
		for (int i = 1; i < N; ++i) fact[i] = mul(i, fact[i - 1]);
		factinv[N - 1] = fastpow(fact[N - 1], mod - 2);
		for (int i = N - 2; i >= 1; --i) factinv[i] = mul(i + 1, factinv[i + 1]);
		for (int i = 1; i < N; ++i) inv_e[i] = mul(fact[i - 1], factinv[i]);
	}
} mt;
struct Poly
{
	std::vector<int> v;
	Poly() { }
	Poly(std::vector<int> v) : v(v) {}
	Poly(std::initializer_list<int> v) : v(v) {}

	inline int deg() const { return v.size() - 1; }
	inline void redeg(int k) { v.resize(k + 1); }
	inline Poly slice(int k) const
	{
		if (k < v.size())
			return std::vector<int>(v.begin(), v.begin() + k + 1);
		std::vector<int> a(v);
		a.resize(k + 1);
		return a;
	}
	inline Poly clone() const { return slice(deg()); }
	inline void reverse() { std::reverse(v.begin(), v.end()); }
	inline void shrink()
	{
		int c = deg();
		while (c >= 0 && v[c] == 0) --c;
		v.resize(c + 1);
	}

	inline int& operator[](int k)
	{
		if (v.size() <= k) v.resize(k + 1);
		return v[k];
	}
	inline int operator[](int k) const
	{
		return v.size() <= k ? 0 : v[k];
	}
	inline int* base() { return v.begin().base(); }
	inline const int* base() const { return v.begin().base(); }
	inline void print() const
	{
		for (auto x : v) printf("%d ", x);
		putchar('\n');
	}

	inline Poly inv() const;
	inline Poly derivative() const;
	inline Poly integration() const;
	inline Poly ln() const;
	inline Poly exp() const;
	inline Poly reverse() const;
	inline Poly sqrt() const;
	inline std::vector<int> evaluation(const std::vector<int> &vals) const;
	inline void interpolation(const std::vector<std::pair<int, int> > &points);

	Poly(std::vector<std::pair<int, int> > points) { interpolation(points); }
};
struct FFT
{
	int len, k;
	int omega[N], omegaInv[N], rev[N];
	inline void init(int n)
	{
		int last_len = len;
		len = 1, k = 0;
		while (len <= n) len <<= 1, ++k;
		if (last_len == len) return;
		for (int i = 0; i < len; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
		omega[0] = omegaInv[0] = 1;
		const int primitive = mt.fastpow(g, (mod - 1) / len);
		for (int i = 1; i < len; ++i) omega[i] = omegaInv[len - i] = mul(omega[i - 1], primitive);
	}
	inline void operator() (Poly &a, const int *w)
	{
		if (a.v.size() < len) a.v.resize(len);
		for (int i = 0; i < len; ++i) if (i < rev[i]) std::swap(a.v[i], a.v[rev[i]]);
		for (int h = 1; h < len; h <<= 1)
			for (int t = len / (h << 1), j = 0; j < len; j += (h << 1))
			{
				const int *wn = w;
				for (int i = j; i < j + h; ++i)
				{
					const int _1 = a.v[i], _2 = mul(a.v[i + h], *wn);
					a.v[i] = inc(_1, _2);
					a.v[i + h] = dec(_1, _2);
					wn += t;
				}
			}
		if (w == omegaInv)
		{
			const int factor = mod - (mod - 1) / len;
			for (int i = 0; i < len; ++i) a.v[i] = mul(a.v[i], factor);
		}
	}
	inline void operator() (Poly &a, int op)
	{
		if (op == 1) operator()(a, omega);
		if (op == -1) operator()(a, omegaInv);
	}
} ntt;



inline Poly operator+(const Poly &P, const Poly &Q)
{
	Poly R;
	int deg = std::max(P.deg(), Q.deg());
	for (int i = 0; i <= deg; ++i) R[i] = inc(P[i], Q[i]);
	return R;
}

inline Poly operator-(const Poly &P, const Poly &Q)
{
	Poly R;
	int deg = std::max(P.deg(), Q.deg());
	for (int i = 0; i <= deg; ++i) R[i] = dec(P[i], Q[i]);
	return R;
}

inline Poly operator*(const Poly &_P, const Poly &_Q)
{
	Poly P = _P.clone(), Q = _Q.clone();
	int deg = P.deg() + Q.deg();
	Poly R;
	if (P.deg() + Q.deg() <= 100)
	{
		for (int i = 0; i <= P.deg(); ++i)
			for (int j = 0; j <= Q.deg(); ++j)
				R[i + j] = inc(R[i + j], mul(P[i], Q[j]));
		return R.slice(deg);
	}
	else
	{

		ntt.init(P.deg() + Q.deg() );
		ntt(P, 1); ntt(Q, 1);
		for (int i = 0; i < ntt.len; ++i) R[i] = mul(P[i], Q[i]);
		ntt(R, -1);
		return R.slice(deg);
	}
}

inline Poly PolyInv(const Poly &A)
{
	Poly Ax, R;
	
	int n = A.deg();
	if (n == 0) return Poly({ mt.inv(A[0]) });
	R = PolyInv(A.slice(A.deg() >> 1));
	ntt.init(A.deg() << 1);
	Ax = A.clone();
	ntt(Ax, 1); ntt(R, 1);
	for (int i = 0; i < ntt.len; ++i) Ax[i] = dec(mul(Ax[i], R[i]), 1);
	for (int i = 0; i < ntt.len; ++i) R[i] = mul(R[i], dec(1, Ax[i]));
	ntt(R, -1);
	R.redeg(n);
	return R;
}

inline Poly Poly::inv() const
{
	return PolyInv(*this);
}

inline Poly Poly::derivative() const
{
	Poly R;
	for (int i = 0; i < deg(); ++i) R[i] = mul(i + 1, operator[](i + 1));
	return R;
}

inline Poly Poly::integration() const
{
	Poly R;
	for (int i = 1; i <= deg(); ++i) R[i] = mul(mt.inv(i), operator[](i - 1));
	return R;
}

inline Poly Poly::ln() const
{
	return (derivative() * inv()).integration().slice(deg());
}

inline Poly PolyExp(const Poly &A)
{
	Poly Ax, Ay, R;
	int n = A.deg();
	if (n == 0) return Poly({1});
	R = PolyExp(A.slice(n >> 1)).slice(n);
	Ax = R.ln();
	Ay = A.slice(n);
	ntt.init(2 * n);
	ntt(R, 1), ntt(Ax, 1), ntt(Ay, 1);
	for (int i = 0; i < ntt.len; ++i)
		R[i] = mul(R[i], dec(inc(1, Ay[i]), Ax[i]));
	ntt(R, -1);
	return R;
}

inline Poly Poly::exp() const
{
	return PolyExp(*this).slice(deg());
}

inline std::pair<Poly, Poly> PolyDiv(const Poly &F, const Poly &G)
{
	Poly Fx, Gx, GrInv, Px, P, Q;
	int n = F.deg(), m = G.deg(); 
	Fx = F.clone(), Gx = G.clone();
	Fx.reverse(); Gx.reverse(); Fx.redeg(n - m + 1);
	Gx.redeg(std::max(m, n - m)); GrInv = Gx.inv(); 
	P = Fx * GrInv;

	P.redeg(n - m); P.reverse(); Gx = G.clone();
	Q = Gx * P; Q.redeg(m - 1);
	for (int i = 0; i <= m - 1; ++i) Q[i] = dec(F[i], Q[i]);
	return std::make_pair(Q, P);
}

inline Poly PolySqrt(const Poly &A)
{
	int n = A.deg();
	if (n == 0)
	{
		assert(A[0] == 0 || A[0] == 1);
		return Poly({A[0]});
	}
	Poly R = PolySqrt(A.slice(n >> 1));
	R.redeg(n);
       	Poly H = R.inv(), K = (R * R).slice(n);
	for (int i = 0; i <= H.deg(); ++i) H[i] = mul(H[i], inv2);
	return (A + K) * H;
}

inline Poly Poly::sqrt() const
{
	return PolySqrt(*this).slice(deg());
}

inline Poly operator%(const Poly &P, const Poly &Q) { return PolyDiv(P, Q).first; }
inline Poly operator/(const Poly &P, const Poly &Q) { return PolyDiv(P, Q).second; }

inline Poly Mul_T(const Poly &a, const Poly &b)
{
	Poly R, A = a.clone(), B = b.clone();
	if (A.deg() <= 100)
	{
		for (int i = a.deg(); i >= 0; --i)
			for (int j = std::max(0, i - (a.deg() - b.deg())); j <= std::min(i, b.deg()); ++j)
				R[i - j] = inc(R[i - j], mul(a[i], b[j]));
		return R;
	}
	else
	{
		B.reverse();
		ntt.init(A.deg());
		ntt(A, 1); ntt(B, 1);
		for (int i = 0; i < ntt.len; ++i) A[i] = mul(A[i], B[i]);
		ntt(A, -1);
		int c = 0;
		for (int i = b.deg(); i <= a.deg(); ++i) R[c++] = A[i];
		return R;
	}
}


inline std::vector<int> Poly::evaluation(const std::vector<int> &vals) const
{
	std::vector<Poly> T, F;
	int m = vals.size();
	int t = std::max(deg(), (int)vals.size() - 1);
	ntt.init(t);
	T.resize(t * 4); F.resize(t * 4);

	std::function<void(int, int, int)> solve = [&](int o, int l, int r)
	{
		T[0].redeg(-1);
		if (l == r) T[o] = Poly({1, dec(0, vals[l])});
		else
		{
			const int mid = l + r >> 1;
			solve(lc(o), l, mid); solve(rc(o), mid + 1, r);
			T[o] = T[lc(o)] * T[rc(o)];
		}
	};
	std::function<void(int, int, int, std::vector<int>&)> solve2 = [&](int o, int l, int r, std::vector<int> &ans)
	{
		if (l >= m) return;
		if (l == r) ans.push_back(F[o][0]);
		else
		{
			const int mid = l + r >> 1;
			F[lc(o)] = Mul_T(F[o], T[rc(o)]);
			F[rc(o)] = Mul_T(F[o], T[lc(o)]);
			solve2(lc(o), l, mid, ans); solve2(rc(o), mid + 1, r, ans);
		}
	};
	solve(1, 0, t);
	Poly Q = T[1].inv();
	Q.redeg(t); 
	Q.reverse();
	Poly R = Q * *this;
	for (int i = t; i <= R.deg(); ++i) F[1][i - t] = R[i];
	F[1].redeg(t);
	std::vector<int> ans;
	solve2(1, 0, t, ans);
	return ans;
}

inline void Poly::interpolation(const std::vector<std::pair<int, int> > &points)
{
	int n = points.size();
	std::vector<Poly> T(n << 2);
	std::vector<int> vals;
	for (auto v : points) vals.push_back(v.first);
	std::function<void(int, int, int)> solve = [&](int o, int l, int r)
	{
		if (l == r) T[o] = Poly({ dec(0, vals[l]), 1 });
		else
		{
			const int mid = l + r >> 1;
			solve(lc(o), l, mid); solve(rc(o), mid + 1, r);
			T[o] = T[lc(o)] * T[rc(o)];
		}
	};
	solve(1, 0, n - 1);
	Poly g = T[1], dg = g.derivative();
	std::vector<int> ys = dg.evaluation(vals);
	std::function<Poly(int, int, int)> solve2 = [&](int o, int l, int r)
	{
		if (l == r) return Poly({ mul(points[l].second, mt.inv(ys[l])) });
		const int mid = l + r >> 1;
		return solve2(lc(o), l, mid) * T[rc(o)] + solve2(rc(o), mid + 1, r) * T[lc(o)];
	};
	*this = solve2(1, 0, n - 1);
}

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
	int n = read(), m = read();
	Poly P; P.redeg(m);
	for (int i = 1; i <= n; ++i) P[read()] = mod - 4;
	P[0] = 1;
	Poly R = P.sqrt(); R[0] += 1;
	Poly D = R.inv();
	for (int i = 0; i <= D.deg(); ++i) D[i] = mul(D[i], 2);
	for (int i = 1; i <= m; ++i) printf("%d\n", D[i]);
	return 0;
}