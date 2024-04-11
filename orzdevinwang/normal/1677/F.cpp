#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int mod = 998244353, _G = 3, N = (1 << 21), inv2 = (mod + 1) / 2;
#define add(a, b) (a + b >= mod ? a + b - mod : a + b)
#define dec(a, b) (a < b ? a - b + mod : a - b)
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
}
int C(int x, int y) {
	return y < 0 || x < y ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int rt[N], Lim;
void Pinit(int x) {
	for(Lim = 1; Lim <= x; Lim <<= 1) ;
	for(int i = 1; i < Lim; i <<= 1) {
		int sG = qpow (_G, (mod - 1) / (i << 1));
		rt[i] = 1;
		L(j, i + 1, i * 2 - 1) rt[j] = (ll) rt[j - 1] * sG % mod;
	}
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
	inline void dif() {
		int n = sz(a);
		for (int l = n >> 1; l >= 1; l >>= 1) 
			for(int j = 0; j < n; j += l << 1) 
				for(int k = 0, *w = rt + l; k < l; k++, w++) {
					int x = a[j + k], y = a[j + k + l];
					a[j + k] = add(x, y);
					a[j + k + l] = (ll) * w * dec(x, y) % mod;
				}
	}
	void dit () {
		int n = sz(a);
		for(int i = 2; i <= n; i <<= 1) 
			for(int j = 0, l = (i >> 1); j < n; j += i) 
				for(int k = 0, *w = rt + l; k < l; k++, w++) {
					int pa = a[j + k], pb = (ll) a[j + k + l] * *w % mod;
					a[j + k] = add(pa, pb), a[j + k + l] = dec(pa, pb);
				}
		reverse(a.begin() + 1, a.end());
		for(int i = 0, iv = qpow(n); i < n; i++) a[i] = (ll) a[i] * iv % mod;
	} 
	friend poly operator * (poly aa, poly bb) {
		if(!sz(aa) || !sz(bb)) return {};
		int lim, all = sz(aa) + sz(bb) - 1;
		for(lim = 1; lim < all; lim <<= 1);
		aa.rs(lim), bb.rs(lim), aa.dif(), bb.dif();
		L(i, 0, lim - 1) aa[i] = (ll) aa[i] * bb[i] % mod;
		aa.dit(), aa.a.resize(all);
		return aa;
	}
	poly Inv() {
		poly res, f, g;
		res.rs(1), res[0] = qpow(a[0]);
		for(int m = 1, pn; m < sz(a); m <<= 1) {
			pn = m << 1, f = res, g.rs(pn), f.rs(pn);
			for(int i = 0; i < pn; i++) g[i] = (*this).v(i);
			f.dif(), g.dif();
			for(int i = 0; i < pn; i++) g[i] = (ll) f[i] * g[i] % mod;
			g.dit();
			for(int i = 0; i < m; i++) g[i] = 0;
			g.dif();
			for(int i = 0; i < pn; i++) g[i] = (ll) f[i] * g[i] % mod;
			g.dit(), res.rs(pn);
			for(int i = m; i < min(pn, sz(a)); i++) res[i] = (mod - g[i]) % mod;
		} 
		return res.rs(sz(a)), res;
	}
	poly Shift (int x) {
		poly zm (sz(a) + x);
		L(i, 0, sz(a) - 1) zm[i + x] = a[i];
		return zm; 
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
	poly pow(int x, int rx = -1) { // x : the power % mod; rx : the power % (mod - 1)
		if(rx == -1) rx = x;
		int cnt = 0;
		while (a[cnt] == 0 && cnt < sz(a)) cnt += 1;
		
		poly res = (*this);
		L(i, cnt, sz(a) - 1) res[i - cnt] = res[i];
		L(i, sz(a) - cnt, sz(a) - 1) res[i] = 0;
		int c = res[0], w = qpow (res[0]);
		L(i, 0, sz(res) - 1) res[i] = (ll) res[i] * w % mod;
		res = res.Ln();
		L(i, 0, sz(res) - 1) res[i] = (ll) res[i] * x % mod;
		res = res.Exp();
		c = qpow (c, rx);
		L(i, 0, sz(res) - 1) res[i] = (ll) res[i] * c % mod;
		
		if((ll) cnt * x > sz(a)) L(i, 0, sz(a) - 1) res[i] = 0;
		else if(cnt) {
			R(i, sz(a) - cnt * x - 1, 0) res[i + cnt * x] = res[i];
			L(i, 0, cnt * x - 1) res[i] = 0; 
		}
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
	friend poly mul (poly aa, poly bb, int k) {
		if(!sz(aa) || !sz(bb)) return {};
		int lim; 
		for(lim = 1; lim < k; lim <<= 1);
		aa.rs(lim), bb.rs(lim), aa.dif(), bb.dif();
		L(i, 0, lim - 1) aa[i] = (ll) aa[i] * bb[i] % mod;
		aa.dit(), aa.a.resize(lim);
		return aa;
	}
} ;

int n, k, s[N], p;
int mat[2][2], g[2][2];
int S[N], x[N], rx[N];
int lm[N];

namespace eval {
	poly A[N], B[N], a, sav;
	int X[N], Y[N];
	void Divide1(int id, int l, int r) {
		if(l == r) return A[id] = poly(vi{1, (mod - X[l]) % mod}), void();
		int mid = (l + r) >> 1;
		Divide1(id << 1, l, mid), Divide1(id << 1 | 1, mid + 1, r);
		A[id] = A[id << 1] * A[id << 1 | 1];
	}
	void Divide2(int id, int l, int r) {
		if(l == r) return Y[l] = (a[0] + (ll) X[l] * B[id][0] % mod) % mod, void();
		int mid = (l + r) >> 1, len = r - l + 1, la = mid - l + 1, lb = r - mid;
		sav = mul(B[id], A[id << 1 | 1], len), B[id << 1].rs(la);
		L(i, 0, la - 1) B[id << 1][i] = sav[i + len - la];
		sav = mul(B[id], A[id << 1], len), B[id << 1 | 1].rs(lb);
		L(i, 0, lb - 1) B[id << 1 | 1][i] = sav[i + len - lb];
		Divide2(id << 1, l, mid), Divide2(id << 1 | 1, mid + 1, r);
	}
	void eva(int m) {
		if(sz(a) < m + 1) a.rs(m + 1);
		int n = sz(a);
		Divide1(1, 1, m);
		sav = a, sav.Rev(), sav *= A[1].Rs(n).Inv(), B[1].rs(m);
		L(i, 0, m - 1) B[1][i] = sav[i + n - m - 1];
		Divide2(1, 1, m);
	}
}


int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k >> p;
	
	init(max(k, n) * 2 + 1);
	Pinit(max(k, n) * 2 + 1);
	
	poly f(k + 1);
	L(i, 0, k) f[i] = (ll) p * ifac[i] % mod;
	f = f * (mod - 1), (f[0] += 1) %= mod, f = f.Inv();
	L(i, 0, k) lm[i] = (ll) ifac[i] * f[k - i] % mod;
	
	L(i, 1, n) 
		cin >> s[i], s[i] += 1;
	
	poly qwq(k + 1);
	L(i, 0, k) qwq[i] = lm[i];;
	
	L(i, 1, n) eval :: X[i] = s[i]; 
	
	eval::a = qwq, eval::eva(n);
	
	L(i, 1, n) S[i] = eval :: Y[i];
	
	
//	L(i, 1, n) {/*
//		cin >> s[i], s[i] += 1;
//		L(j, 0, k) (S[i] += (ll) lm[j] * qpow(s[i], j) % mod) %= mod;
//
////		L(t, 0, s[i]) 
////			(S[i] += (ll) qpow(p, t) * qpow(t, k) % mod) %= mod;
//	}*/
	L(i, 1, n) 
		S[i] = (ll) S[i] * qpow(p, s[i]) % mod;
		
	L(i, 1, n) 
		S[i] = (f[k] + mod - S[i]) % mod, S[i] = (ll) S[i] * fac[k] % mod;
	
	int ns = 0;
	L(o, 1, n) {
		(mat[0][0] += 1) %= mod;
		R(i, 1, 0) R(j, 1, 0) R(a, 1 - i, 0) R(b, 1 - j, 0) {
			int v = a == 1 ? S[o] : s[o] - 1;
			v = (ll) v * mat[i][j] % mod;
			(mat[i + a][j + b] += v) %= mod;
		}
		(ns += mat[1][1]) %= mod;
	}
	cout << ns << '\n';
	return 0;
}