#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int mod = 998244353, _G = 3, N = (1 << 12), inv2 = (mod + 1) / 2;
#define Add(a, b) (a + b >= mod ? a + b - mod : a + b)
#define Dec(a, b) (a < b ? a - b + mod : a - b)
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
					a[j + k] = Add(x, y);
					a[j + k + l] = (ll) * w * Dec(x, y) % mod;
				}
	}
	void dit () {
		int n = sz(a);
		for(int i = 2; i <= n; i <<= 1) 
			for(int j = 0, l = (i >> 1); j < n; j += i) 
				for(int k = 0, *w = rt + l; k < l; k++, w++) {
					int pa = a[j + k], pb = (ll) a[j + k + l] * *w % mod;
					a[j + k] = Add(pa, pb), a[j + k + l] = Dec(pa, pb);
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
		L(i, 0, sz(res) - 1) res[i] = Add(aa.v(i), bb.v(i));
		return poly(res);
	}
	friend poly operator - (poly aa, poly bb) {
		vector<int> res(max(sz(aa), sz(bb)));
		L(i, 0, sz(res) - 1) res[i] = Dec(aa.v(i), bb.v(i));
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
int n, a[N][N], rk, pw[N];
struct fenwt {
	int a[N], n = N - 1;
	void init () {
		L(i, 1, n) if(i + (i & -i) <= n) a[i + (i & -i)] += a[i];
	}
	void add (int x, int  w) {
		for (; x <= n; x += x & -x) a[x] += w;
	}
	int query (int x) {
		int ret = 0;
		for (; x; x -= x & -x) ret += a[x];
		return ret;
	}
	int get (int l, int r) {
		if(l > r) return 0;
		return query (r) - query (l - 1);
	}
	void clear () {
		memset(a, 0, sizeof(a));
	}
} s, r;
int dp[N][N]; 
// n m  i 

bool vis[N], cvis[N]; 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	init (n * 2 + 4), Pinit (n * 2 + 4);
	L(i, 1, n) L(j, 1, n) cin >> a[i][j];
	L(i, 0, n) {
		poly A (i + 1), B (i + 1);
		L(j, 0, i) A[j] = j & 1 ? mod - ifac[j] : ifac[j], A[j] = (ll) A[j] * fac[i - j] % mod;
		L(j, 0, i) B[j] = ifac[j];
		A *= B;
		L(j, 0, i) dp[i][j] = (ll) A[j] * fac[j] % mod;
	}
//	cout << dp[2][2] << ' ' << dp[1][1] << '\n';
	int ns = 0;
	L(i, 1, n) {
		memset(vis, true, sizeof(vis));
		memset(cvis, true, sizeof(cvis));
		s.clear(), r.clear();
		L(j, 1, n) s.add(j, 1);
		int ret = 0;
		if(i == 1) {
			L(j, 1, n) {
				int t = s.query(a[i][j]);
				(ret += (ll) (t - 1) * fac[n - j] % mod) %= mod;
				s.add(a[i][j], -1);
			}	
		}
		else {
			int cnt = n;
			L(j, 1, n) r.add(j, 1), cvis[j] = true; 
			L(j, 1, n) { 
				if(vis[a[i - 1][j]]) vis[a[i - 1][j]] = false, cnt -= 1, r.add(a[i - 1][j], -1);
				int t = s.query(a[i][j] - 1), ct = r.query(a[i][j] - 1);
				if(a[i - 1][j] < a[i][j] && cvis[a[i - 1][j]]) t -= 1; 
//				cout << t << " and " << ct << '\n';
				(ret += (ll) dp[n - j][cnt - 1] * ct % mod) %= mod;
				(ret += (ll) dp[n - j][cnt] * (t - ct) % mod) %= mod;
				// a_[i-1][j+1 ~ n] , a[i][j+1 ~ n] ;  
				s.add(a[i][j], -1), cvis[a[i][j]] -= 1;
				if(vis[a[i][j]]) vis[a[i][j]] = false, cnt -= 1, r.add(a[i][j], -1);
			}
		} 
//		cout << "ret = " << ret << '\n';
		ns = (ll) ns * dp[n][n] % mod; 
		(ns += ret) %= mod;
	}
	cout << ns << '\n';
	return 0;
}