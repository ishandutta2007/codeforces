// O(n \log^2 n) solution!

#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size()) 
#define vi vector<int>

#define db double
using namespace std;
const int N = (1 << 19);
const db pi = acos(-1);
int mod;
#define add(a, b) (a + b >= mod ? a + b - mod : a + b)
#define dec(a, b) (a < b ? a - b + mod : a - b)
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
struct CP {
	db x, y; 
	CP (db xx = 0, db yy = 0) {
		x = xx, y = yy;
	}
	inline CP rev() {
		return CP(x, -y);
	}
} ;
inline CP operator + (CP aa, CP bb) {
	return CP(aa.x + bb.x, aa.y + bb.y);
}
inline CP operator - (CP aa, CP bb) {
	return CP(aa.x - bb.x, aa.y - bb.y);
}
inline CP operator * (CP aa, CP bb) {
	return CP(aa.x * bb.x - aa.y * bb.y, aa.x * bb.y + aa.y * bb.x);
}
CP Pow[N], iPow[N];
int Lim, rev[N], lim;
void revlim() {
	L(i, 0, lim - 1) rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) * (lim >> 1)));
}
void up(int x) {
	for(lim = 1; lim <= x; lim <<= 1) ;
}
void FFT(CP *f, int op) {
	L(i, 0, lim - 1) if(rev[i] < i) swap(f[rev[i]], f[i]);
	for(int i = 2; i <= lim; i <<= 1) {
		for(int j = 0, l = (i >> 1), ch = Lim / i; j < lim; j += i) {
			for(int k = j, now = 0; k < j + l; k++) {
				CP pa = f[k], pb = f[k + l] * (op == 1 ? Pow[now] : iPow[now]);
				f[k] = pa + pb, f[k + l] = pa - pb, now += ch;
			}
		}
	}
	if(op == -1) L(i, 0, lim - 1) f[i].x /= lim, f[i].y /= lim;
}
CP _f[N], _g[N], A0[N], A1[N];
vi Mul(vi f, vi g) {
	int n = sz(f), m = sz(g);
	up(n + m - 1), revlim();
	L(i, 0, lim - 1) _f[i] = _g[i] = 0;
	L(i, 0, n - 1) _f[i] = CP(f[i] & 32767, f[i] >> 15);
	L(i, 0, m - 1) _g[i] = CP(g[i] & 32767, g[i] >> 15);
	FFT(_f, 1), FFT(_g, 1);
	L(i, 0, lim - 1) {
		int o = (i == 0 ? 0 : lim - i);
		CP aa, bb, cc, dd, rvf = _f[o].rev(), rvg = _g[o].rev();
		aa = (_f[i] + rvf) * CP(0.5, 0), bb = (_f[i] - rvf) * CP(0, -0.5);
		cc = (_g[i] + rvg) * CP(0.5, 0), dd = (_g[i] - rvg) * CP(0, -0.5);
		A0[i] = aa * cc + CP(0, 1) * aa * dd, A1[i] = bb * cc + CP(0, 1) * bb * dd;
	}
	vi ans;
	FFT(A0, -1), FFT(A1, -1), ans.resize(n + m - 1);
	L(i, 0, n + m - 2) ans[i] = 
	((ll) (A0[i].x + 0.49) + ((ll) (A0[i].y + 0.49) % mod << 15) + 
	((ll) (A1[i].x + 0.49) % mod << 15) + ((ll) (A1[i].y + 0.49) % mod << 30)) % mod;
	return ans;
}
int n, m, fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
}
void Pinit(int x) {
	up(x), Lim = lim;
	L(i, 0, Lim - 1) Pow[i] = CP(cos(pi * 2 / Lim * i), sin(pi * 2 / Lim * i)), iPow[i] = Pow[i].rev();
}
int C(int x, int y) {
	return y < 0 || x < y ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
struct poly {
	vi a;
	void rs(int x = 0) { a.resize(x); }
	poly (int x = 0) { rs(x); }
	poly (const poly &o) { a = o.a; }
	poly (vi o) { a = o; }
	poly RS(int x) { vi res = a; res.resize(x); return poly(res); }
	int & operator [] (int x) { return a[x]; }
	int v(int x) { return x < 0 || x >= sz(a) ? 0 : a[x]; }
	int size() { return sz(a); }
	friend poly operator * (poly aa, poly bb) {
		if(!sz(aa) || !sz(bb)) return {};
		return Mul(aa.a, bb.a);
	}
	friend poly operator * (poly aa, int bb) {
		poly res(sz(aa));
		L(i, 0, sz(aa) - 1) res[i] = (ll) aa[i] * bb % mod;
		return res;
	}
	friend poly operator + (poly aa, poly bb) {
		vector<int> res(max(sz(aa), sz(bb)));
		L(i, 0, sz(res) - 1) res[i] = add(aa.v(i), bb.v(i));
		return poly(res);
	}
	friend poly operator - (poly aa, poly bb) {
		vector<int> res(max(sz(aa), sz(bb)));
		L(i, 0, sz(res) - 1) res[i] = dec(aa.v(i), bb.v(i));
		return poly(res);
	}
	poly & operator += (poly o) {
		rs(max(sz(a), sz(o)));
		L(i, 0, sz(a) - 1) (a[i] += o.v(i)) %= mod;
		return (*this);
	}
	poly & operator -= (poly o) {
		rs(max(sz(a), sz(o)));
		L(i, 0, sz(a) - 1) (a[i] += mod - o.v(i)) %= mod;
		return (*this);
	}
	poly & operator *= (poly o) {
		return (*this) = (*this) * o;
	}
	poly Inv() {
		poly res(1), o;
		res[0] = qpow(a[0]);
		for(int m = 1, pn; m < sz(a); m <<= 1) {
			pn = (m << 1), o.rs(pn);
			L(i, 0, pn - 1) o[i] = (*this).v(i);
			res = res * 2 - res * res * o, res.rs(min(m << 1, n)); 
		}
		return res;
	}
	poly Integ() {
		poly res(sz(a) + 1);
		L(i, 0, sz(a) - 1) res[i + 1] = (ll) a[i] * inv[i + 1] % mod;
		return res;
	}
	poly Deriv() {
		poly res(sz(a) - 1); 
		L(i, 0, sz(a) - 2) res[i] = (ll) a[i + 1] * (i + 1) % mod;
		return res;
	}
	poly Ln() {
		int n = sz(a); return ((*this).Deriv() * (*this).Inv()).Integ().RS(n);
	}
	poly Exp() {
		int n = sz(a);
		poly res(1), f;
		res[0] = 1;
		for(int m = 1, pn; m < n; m <<= 1) {
			pn = min(m << 1, n), f = res, f.rs(pn);
			f = f.Ln(), (f[0] += mod - 1) %= mod;
			L(i, 0, pn - 1) f[i] = ((*this).v(i) + mod - f[i]) % mod;
			res = res * f, res.rs(pn);
		}
		return res;
	}
} ;
int ns[N];
poly fz[N << 2], afz[N << 2], fm[N << 2];
void divide(int id, int l, int r) {
	if(l == r) return afz[id] = fz[id] = vi {0, 0, l}, fm[id] = vi {1, mod - 2 * l}, void();
	int mid = (l + r) >> 1;
	divide(id << 1, l, mid), divide(id << 1 | 1, mid + 1, r);
	afz[id] = afz[id << 1] * fm[id << 1 | 1] + fz[id << 1] * afz[id << 1 | 1];
	fz[id] = fz[id << 1] * fz[id << 1 | 1];
	fm[id] = fm[id << 1] * fm[id << 1 | 1]; 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> mod;
	++n, Pinit(n << 2), init(n << 2);
	divide(1, 1, n / 2), fm[1].rs(n + 1);
	poly qwq = afz[1] * fm[1].Inv();
	cout << qwq[n] << "\n";
	return 0;
} // 100000 1000000007