#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int mod = 998244353, G = 3, iG = (mod + 1) / G, N = 5e5 + 7, inv2 = (mod + 1) / 2;
#define add(a, b) (a + b >= mod ? a + b - mod : a + b)
#define dec(a, b) (a < b ? a - b + mod : a - b)
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int n, m, fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
}
int rt[N], Lim;
void Pinit(int x) {
	for(Lim = 1; Lim <= x; Lim <<= 1) ;
	int sG = qpow(G, (mod - 1) / Lim); rt[0] = 1;
	L(i, 1, Lim) rt[i] = (ll) rt[i - 1] * sG % mod;
}
int C(int x, int y) {
	return y < 0 || x < y ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

int rev[N];
void initrev(int n) {
	L(i, 0, n - 1) rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) * (n >> 1)));
}
struct poly {
	vector<int> a;
	int size() { return sz(a); }
	int & operator [] (int x) { return a[x]; }
	int v(int x) { return x < 0 || x >= sz(a) ? 0 : a[x]; }
	void clear() { vector<int> ().swap(a); }
	void rs(int x = 0) { a.resize(x); }
	poly (int n = 0) { rs(n); }
	poly (vector<int> o) { a = o; }
	poly (const poly &o) { a = o.a; }
	poly Rs(int x = 0) { vi res = a; res.resize(x); return res; }
	void ntt(int op, int t = true) {
		int n = sz(a);
		if(t) initrev(n);
		L(i, 0, n - 1) if(rev[i] < i) swap(a[rev[i]], a[i]);
		for(int i = 2; i <= n; i <<= 1) 
			for(int j = 0, l = (i >> 1), ch = Lim / i; j < n; j += i) 
				for(int k = j, now = 0; k < j + l; k++) {
					int pa = a[k], pb = (ll) a[k + l] * (op == 1 ? rt[now] : rt[Lim - now]) % mod;
					a[k] = add(pa, pb), a[k + l] = dec(pa, pb), now += ch;
				}
		if(op != 1) for(int i = 0, iv = qpow(n); i < n; i++) a[i] = (ll) a[i] * iv % mod;
	}
	
	friend poly operator * (poly aa, poly bb) {
		if(!sz(aa) || !sz(bb)) return {};
		int lim, all = sz(aa) + sz(bb) - 1;
		for(lim = 1; lim < all; lim <<= 1);
		initrev(lim), aa.rs(lim), bb.rs(lim), aa.ntt(1, false), bb.ntt(1, false);
		L(i, 0, lim - 1) aa[i] = (ll) aa[i] * bb[i] % mod;
		aa.ntt(-1, false), aa.a.resize(all);
		return aa;
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
		poly res, f, g;
		res.rs(1), res[0] = qpow(a[0]);
		for(int m = 1, pn; m < sz(a); m <<= 1) {
			pn = m << 1, f = res, g.rs(pn), f.rs(pn), initrev(pn);
			for(int i = 0; i < pn; i++) g[i] = (*this).v(i);
			f.ntt(1, false), g.ntt(1, false);
			for(int i = 0; i < pn; i++) g[i] = (ll) f[i] * g[i] % mod;
			g.ntt(-1, false);
			for(int i = 0; i < m; i++) g[i] = 0;
			g.ntt(1, false);
			for(int i = 0; i < pn; i++) g[i] = (ll) f[i] * g[i] % mod;
			g.ntt(-1, false), res.rs(pn);
			for(int i = m; i < min(pn, sz(a)); i++) res[i] = (mod - g[i]) % mod;
		}
		return res;
	}
	poly Integ() {
		if(!sz(a)) return poly();
		poly res(sz(a) + 1);
		L(i, 1, sz(a)) res[i] = (ll) a[i - 1] * inv[i] % mod;
		return res;
	}
	poly Deriv() {
		if(!sz(a)) return poly();
		poly res(sz(a) - 1); 
		L(i, 1, sz(a) - 1) res[i - 1] = (ll) a[i] * i % mod;
		return res;
	}
	poly Ln() {
		poly g = ((*this).Inv() * (*this).Deriv()).Integ();
		return g.rs(sz(a)), g;
	}
	poly Exp() {
		poly res(1), f; 
		res[0] = 1;
		for(int m = 1, pn; m < sz(a); m <<= 1) {
			pn = min(m << 1, sz(a)), f.rs(pn), res.rs(pn);
			for(int i = 0; i < pn; i++) f[i] = (*this).v(i);
			f -= res.Ln(), (f[0] += 1) %= mod, res *= f, res.rs(pn); 
		}
		return res.rs(sz(a)), res;
	}
	poly pow(int x) {
		poly res = (*this).Ln();
		L(i, 0, sz(res) - 1) res[i] = (ll) res[i] * x % mod;
		res = res.Exp();
		return res;
	}
	poly sqrt() {
		poly res(1), f; 
		res[0] = 1;
		for(int m = 1, pn; m < sz(a); m <<= 1) {
			pn = min(m << 1, sz(a)), f.rs(pn);
			for(int i = 0; i < pn; i++) f[i] = (*this).v(i);
			f += res * res, f.rs(pn), res.rs(pn), res = f * res.Inv(), res.rs(pn);
			for(int i = 0; i < pn; i++) res[i] = (ll) res[i] * inv2 % mod;
		} 
		return res;
	}
	void Rev() {
		reverse(a.begin(), a.end());
	}
} ;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m, init(m * 2 + 2), Pinit(m * 2 + 2);
	poly a(m + 1), b(m + 1);
	L(i, 0, m) a[i] = (ll) qpow(i, m) * ifac[i] % mod;
	L(i, 0, m) b[i] = (i & 1) ? mod - ifac[i] : ifac[i];
	a = a * b;
	int ns = 0, now = 1;
	L(i, 1, min(m, n)) 
		now = (ll) now * (n - i + 1) % mod, (ns += (ll) a[i] * now % mod * qpow(n + 1, n - i) % mod) %= mod;
	cout << ns << "\n";
	return 0;
}