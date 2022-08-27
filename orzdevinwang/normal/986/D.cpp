#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int mod = 998244353, _G = 3, N = (1 << 22), inv2 = (mod + 1) / 2;
#define add(a, b) (a + b >= mod ? a + b - mod : a + b)
#define dec(a, b) (a < b ? a - b + mod : a - b)
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int rt[N], Lim;
void Pinit(int x) {
	for(Lim = 1; Lim < x; Lim <<= 1) ;
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
} ;
int n, m;
vi operator * (vi a, vi b) {
	poly qwq = ((poly) a) * ((poly) b);
	int xn = sz(qwq) + 1;
	vi ns(xn);
	L(i, 0, xn - 2) ns[i] += qwq[i], ns[i + 1] += ns[i] / 10, ns[i] %= 10;
	assert(ns[xn - 1] < 10);
	while(sz(ns) && !ns.back()) ns.pop_back();
	return ns;
}
vi mulk(vi a, int w) { // w < 10;
	assert(w < 10);
	int xn = sz(a);
	a.resize(xn + 1);
	L(i, 0, xn - 1) a[i] *= w;
	L(i, 0, xn - 1) a[i + 1] += a[i] / 10, a[i] %= 10;
	if(!a[xn]) a.resize(xn);
	return a; 
}
vi s;
bool chk (vi a) {
	if(sz(a) < sz(s)) return 0;
	if(sz(a) > sz(s)) return true;
	R(i, sz(a) - 1, 0) if(a[i] != s[i]) return a[i] > s[i];
	return true;
}
vi pw(int c) {
	vi ns(1), cur(1);
	ns[0] = 1, cur[0] = 3;
	for(ll i = 0; i <= 30; ++i) {
		if(c >> i & 1) {
			c ^= 1 << i;
			ns = ns * cur;
		} 
		if(!c) break ;
		cur = cur * cur; 
	}
	return ns;
}
char ss[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	Pinit(N);
//	vi o = pw(100);
//	cout << sz(o) << endl;
//	R(i, sz(o) - 1, 0) cout << o[i];
//	cout << endl;
	cin >> (ss + 1);
	int xn = strlen(ss + 1);
	s.resize(xn); 
	L(i, 0, xn - 1) s[i] = ss[xn - i] - '0';
	int qwq = log(10.) / log(3.) * xn - 6;
	qwq = max(qwq, 0);
	vi cur = pw(qwq);
	int ns = 1e9;
	while(true) {
		if(chk(cur)) {
			ns = min(ns, qwq * 3);
			break; 
		} 
//		R(i, sz(cur) - 1, 0) cout << cur[i];
//		cout << endl; 
		vi a = mulk(cur, 2);
		if(chk(a)) {
			ns = min(ns, qwq * 3 + 2);
		} else {
			a = mulk(a, 2);
			if(chk(a)) 
				ns = min(ns, qwq * 3 + 4);
		}
		qwq += 1;
		if(qwq * 3 >= ns) break;
		cur = mulk(cur, 3);
	}
	ns = max(ns, 1); 
	cout << ns << '\n';
	return 0;
}