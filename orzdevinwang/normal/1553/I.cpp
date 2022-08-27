#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int mod = 998244353, _G = 3, N = (1 << 19), inv2 = (mod + 1) / 2;
#define add(a, b) (a + b >= mod ? a + b - mod : a + b)
#define dec(a, b) (a < b ? a - b + mod : a - b)
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int n, fn, m, fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
}
int rt[N], Lim;
void Pinit(int x) {
	for(Lim = 1; Lim <= x; Lim <<= 1) ;
	int sG = qpow(_G, (mod - 1) / Lim); rt[0] = 1;
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
	inline void ntt(int op, int t = true) {
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
	poly Shift (int x) {
		poly zm (max(sz(a) + x, 0));
		L(i, max(0, -x), sz(a) - 1) zm[i + x] = a[i];
		return zm; 
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
	poly sqrt(int rt = 1) {
		poly res(1), f; 
		res[0] = rt;
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
int W[N], f[N];
poly s[N][2][2];
void divide (int x, int l, int r) {
	if(l == r) {
		L(i, 0, 1) L(j, 0, 1) s[x][i][j] = vi {0, 1};
		if(f[l] == 1) s[x][0][0] = vi {0, inv2};
		return ;
	}
	int mid = (l + r) >> 1;
	divide (x * 2, l, mid);
	divide (x * 2 + 1, mid + 1, r);
	L(a, 0, 1) L(b, 0, 1) s[x][a][b] += (s[x * 2][a][1] * s[x * 2 + 1][1][b]).Shift(-1);
	L(a, 0, 1) L(b, 0, 1) s[x][a][b] += s[x * 2][a][0] * s[x * 2 + 1][0][b];
}
int main() { 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n, init(n * 4), Pinit (n * 4);
	L(i, 1, n) cin >> W[i];
	int cnt = 0;
	L(i, 1, n) {
		++cnt;
		if(W[i] != W[i + 1]) {
			if(cnt % W[i]) return cout << 0 << "\n", 0;
			L(t, 1, cnt / W[i]) f[++m] = W[i];
			cnt = 0;
		}
	}
//	L(i, 1, m) cout << f[i] << " ";
//	cout << "\n";
	divide(1, 1, m);
	int res = 0;
	L(i, 0, sz(s[1][0][0]) - 1) (res += (ll) s[1][0][0][i] * qpow(2, i) % mod * fac[i] % mod 
	* qpow(mod - 1, m - i) % mod) %= mod; 
	cout << res << "\n";
	return 0;
}