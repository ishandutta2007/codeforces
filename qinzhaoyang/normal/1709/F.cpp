#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(X) (X).begin(), (X).end()
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

namespace POLY {
	const int p_P = 998244353;
	inline int p_add(int x, int y) {return x + y >= p_P ? x + y - p_P : x + y;}
	inline int p_sub(int x, int y) {return x < y ? x - y + p_P : x - y;}
	inline int p_mul(int x, int y) {return 1ll * x * y % p_P;}
	inline int p_Pow(int x, int y) {int r = 1; for (; y; y >>= 1, x = p_mul(x, x)) if (y & 1) r = p_mul(r, x); return r;}
	const int G = 3, Gi = p_Pow(3, p_P - 2);
	using Poly = vector<int>;
	Poly r; int lim, l;
	void Dft(Poly &a, int type) {
		for (int i = 0; i < lim; i++)
			if (i < r[i]) swap(a[i], a[r[i]]);
		for (int i = 1; i < lim; i <<= 1) {
			int w = p_Pow(type == 1 ? G : Gi, p_P / (i << 1));
			for (int j = 0; j < lim; j += (i << 1))
				for (int k = 0, t = 1; k < i; k++, t = p_mul(t, w)) {
					int tx = a[j + k], ty = p_mul(t, a[i + j + k]);
					a[j + k] = p_add(tx, ty), a[i + j + k] = p_sub(tx, ty);
				}
		}
		if (type == -1) {
			int inv = p_Pow(lim, p_P - 2);
			for (int i = 0; i < lim; i++) a[i] = p_mul(a[i], inv);
		}
	}
	void init(int len) {
		lim = 2, l = 1; while (lim < len) lim <<= 1, l++; r.resize(lim);
		for (int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	}
	Poly operator + (const Poly x, const Poly y) {
		Poly ret(max(x.size(), y.size()), 0);
		for (int i = 0; i < x.size(); i++) ret[i] = p_add(ret[i], x[i]);
		for (int i = 0; i < y.size(); i++) ret[i] = p_add(ret[i], y[i]);
		return ret;
	}
	Poly operator - (const Poly x, const Poly y) {
		Poly ret = x; ret.resize(max(x.size(), y.size()));
		for (int i = 0; i < y.size(); i++) ret[i] = p_sub(ret[i], y[i]);
		while (ret.size() && !ret.back()) ret.pop_back();
		return ret;
	}
	Poly operator * (const Poly x, int y) {
		if (!y) return Poly(0);
		Poly ret = x;
		for (int i = 0; i < ret.size(); i++) ret[i] = p_mul(ret[i], y);
		return ret;
	}
	Poly operator * (const Poly x, const Poly y) {
		if (!x.size() || !y.size()) return Poly(0);
		init(x.size() + y.size() - 1); Poly a(lim, 0), b(lim, 0);
		for (int i = 0; i < x.size(); i++) a[i] = x[i]; Dft(a, 1);
		for (int i = 0; i < y.size(); i++) b[i] = y[i]; Dft(b, 1);
		for (int i = 0; i < lim; i++) a[i] = p_mul(a[i], b[i]); Dft(a, -1);
		Poly ret(x.size() + y.size() - 1);
		for (int i = 0; i < x.size() + y.size() - 1; i++) ret[i] = a[i];
		return ret;
	}
	Poly get_Inv(int len, const Poly &x) {
		if (len == 1) return Poly(1, p_Pow(x[0], p_P - 2));
		Poly y = get_Inv((len + 1) / 2, x), ret(len, 0);
		init(len << 1); Poly a(lim, 0), b(lim, 0);
		for (int i = 0; i < min(len, (int)x.size()); i++) a[i] = x[i]; Dft(a, 1);
		for (int i = 0; i < y.size(); i++) b[i] = y[i]; Dft(b, 1);
		for (int i = 0; i < lim; i++) a[i] = (1ll * b[i] * (2ll - 1ll * a[i] * b[i] % p_P) % p_P + p_P) % p_P; Dft(a, -1);
		for (int i = 0; i < len; i++) ret[i] = a[i];
		return ret;
	}
	Poly Inv(const Poly &x) {
		Poly ret = get_Inv(x.size(), x);
		return ret;
	}
	Poly get_Sqrt(int len, const Poly &x) {
		if (len == 1) return Poly(1, 1);
		Poly y = get_Sqrt((len + 1) >> 1, x), ret(len, 0);
		Poly iy = y; iy.resize(len), iy = Inv(iy);
		init(len << 1); Poly a(lim, 0), b(lim, 0);
		for (int i = 0; i < min(len, (int)x.size()); i++) a[i] = x[i]; Dft(a, 1);
		for (int i = 0; i < iy.size(); i++) b[i] = iy[i]; Dft(b, 1);
		for (int i = 0; i < lim; i++) a[i] = p_mul(a[i], b[i]); Dft(a, -1);
		int inv2 = p_Pow(2, p_P - 2);
		for (int i = 0; i < len; i++) ret[i] = p_mul(a[i], inv2);
		for (int i = 0; i < (len + 1) / 2; i++) ret[i] = p_add(ret[i], p_mul(inv2, y[i]));
		return ret;
	}
	Poly Sqrt(const Poly &x) {
		Poly ret = get_Sqrt(x.size(), x);
		return ret;
	}	//only x[0]=1
	Poly Der(const Poly &x) {
		Poly ret;
		for (int i = 1; i < x.size(); i++)
			ret.push_back(p_mul(i, x[i]));
		return ret;
	}
	Poly Int(const Poly &x) {
		 Poly inv(x.size() + 1), ret(1, 0);
		 inv[0] = inv[1] = 1;
		 for (int i = 2; i < inv.size(); i++) inv[i] = p_mul(inv[p_P % i], p_P - p_P / i);
		 for (int i = 0; i < x.size(); i++) ret.push_back(p_mul(inv[i + 1], x[i]));
		 return ret;
	}
	Poly Ln(const Poly &x) {
		if (x.size() == 1) return Poly(0);
		Poly ret = Int(Der(x) * Inv(x));
		return ret.resize(x.size()), ret;
	}	//x[0] = 1
	Poly get_Exp(int len, const Poly &x) {
		if (len == 1) return Poly(1, 1);
		Poly y = get_Exp((len + 1) >> 1, x), ret(len, 0);
		Poly ly = y; ly.resize(len); ly = Ln(ly);
		init(len << 1); Poly a(lim, 0), b(lim, 0), c(lim, 0);
		for (int i = 0; i < y.size(); i++) a[i] = y[i]; Dft(a, 1);
		for (int i = 0; i < ly.size(); i++) b[i] = ly[i]; Dft(b, 1);
		for (int i = 0; i < len; i++) c[i] = x[i]; Dft(c, 1);
		for (int i = 0; i < lim; i++) a[i] = (1ll * a[i] * (1 - b[i] + c[i]) % p_P + p_P) % p_P; Dft(a, -1);
		for (int i = 0; i < len; i++) ret[i] = a[i];
		return ret;
	}
	Poly Exp(const Poly &x) {
		Poly ret = get_Exp(x.size(), x);
		return ret;
	}	//only x[0]=0
};
using namespace POLY;

namespace MOD {
	const int P = 998244353;
	inline int add(int x, int y) {return x + y >= P ? x + y - P : x + y;}
	inline int sub(int x, int y) {return x < y ? x - y + P : x - y;}
	inline int mul(int x, int y) {return (long long)x * y % P;}
	inline void inc(int &x, int y) {x = add(x, y);}
	inline void dec(int &x, int y) {x = sub(x, y);}
	inline void upd(int &x, int y) {x = mul(x, y);}
	inline int Pow(int x, int y) {int r = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) r = mul(r, x); return r;}
};
using namespace MOD;

int n, k, f;

int main() {
	read(n), read(k), read(f);
	Poly x(k + 1);
	for (int i = 0; i <= k; i++)
		x[i] = 1;
	for (int i = 2; i <= n; i++) {
		Poly y = x * x;
		Poly z(k + 1, 0);
		for (int j = 0; j <= k; j++)
			inc(z[j], mul(k - j + 1, y[j]));
		int s = 0;
		while (y.size() > k + 1) {
			inc(s, y.back());
			y.pop_back();
		}
		for (int j = k; j >= 0; j--) {
			inc(z[j], s);
			inc(s, y.back());
			y.pop_back();
		}
		x = z;
	}
	int ans = 0;
	for (int i = 0; i <= f; i++) {
		if (i <= k && 0 <= f - i && f - i <= k)
			inc(ans, mul(x[i], x[f - i]));
	}
	printf("%d\n", ans);
	return 0;
}