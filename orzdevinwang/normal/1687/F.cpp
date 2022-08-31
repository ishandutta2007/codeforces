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
inline int sign(int x) {
	return (x & 1) ? mod - 1 : 1;
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
} ;

int n, s, F[N];
int xt[N];
pair < poly, poly > mu(int l, int r) {
	if(l == r) return make_pair((poly) vi{xt[l]}, (poly) vi{1, mod - 1});
	int mid = (l + r) >> 1;
	auto u = mu(l, mid), v = mu(mid + 1, r);
	poly U = u.first, V = v.first;
	U *= v.second;
	int nt = mid - l + 1, xs = sz(V);
	V.rs(nt + xs);
	R(i, xs - 1, 0) V[i + nt] = V[i];
	L(i, 0, nt - 1) V[i] = 0; 
	return make_pair(U + V, u.second * v.second);
}
struct mat {
	poly f[4][4]; 
	poly* operator [] (int x) { return f[x]; }
	/* (1-s)^{underline{r}}; s^t chosen; s^t (t + 1); done; */
};
inline mat operator * (mat a, mat b) {
	mat ret;
	L(i, 0, 3) L(j, i, 3) L(k, i, j) ret[i][j] += a[i][k] * b[k][j];
	return ret; 
}
// case 0 : getting (1-s)^{underline{r}}. 
// case 1 : getting s^t (t+1). 
// case 2 : done. 
inline mat solve(int l, int r) {
	if(l == r) {
		mat ns;
		ns.f[0][0] = vi{mod + 1 - l, mod - 1};
		ns.f[0][1] = vi{0, ifac[l]};
		ns.f[0][2] = vi{0, (ll) 2 * ifac[l] % mod};
		ns.f[0][3] = vi{(ll) F[l] * ifac[l] % mod};
		ns.f[1][1] = vi{0, 1};
		ns.f[1][2] = vi{0, 1};
		ns.f[2][2] = vi{0, 1};
		ns.f[2][3] = vi{F[l]};
		ns.f[3][3] = vi{1};
		return ns;
	}
	int mid = (l + r) >> 1;
	return solve(l, mid) * solve(mid + 1, r);
}
poly calc(int n) {
	poly ns(n + 1), st(n + 1), ic(n + 1);
	L(i, 0, n) st[i] = (ll) qpow(i, n) * ifac[i] % mod; 
	L(i, 0, n) ic[i] = (ll) ifac[i] * sign(i) % mod;
	st *= ic, st.rs(n + 1);
	L(i, 0, n) F[i] = (ll) st[i] * fac[i] % mod * ifac[n] % mod;
//	L(w, 0, n) {
//		poly f(n + 1), cur(n + 1), mut(2);
//		mut[1] = 1;
//		f[0] = 1;
//		L(i, 0, w) {
//			if(i) {
//				poly rm(2);
//				rm[0] = (2 + mod - i) % mod;
//				rm[1] = mod - 1;
//				f *= rm, f.rs(n + 1);
//			} 
//			cur *= mut, cur.rs(n + 1); 
//			cur = cur + f * (w - i + 1) * ifac[i];
//		}
//		ns = ns + cur * F[w];
//	}
	ns = solve(0, n).f[0][3], ns.rs(n + 1);  
	L(i, 0, n) xt[i] = ns[i];
	return mu(0, n).first;
}

int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> s;
	init(n * 2 + 2), Pinit(n * 2 + 2);
	poly ns = calc(n - s - 1);
	ns = ns * ((ll) fac[n - 1] * ifac[s] % mod);
	L(i, 0, s - 1) cout << 0 << ' ';
	L(i, 0, n - s - 1) cout << ns[i] << ' ';
	cout << '\n';
	return 0;
}