#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 3e5;
const int mod = 998244353;
const int G = 3;
const int iG = (mod + 1) / G;
const int twony = (mod + 1) / 2;
int qpow(int x, int y) {
	if(x == 0) return 0;
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
}
int pp[N];
void init(int lim) { for(int i = 0; i < lim; i++) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (lim >> 1))); }
struct Poly {
	int len, f[N];
	void NTT(int flag) {
		for(int i = 0; i < len; i++) if(pp[i] < i) swap(f[pp[i]], f[i]);
		for(int i = 2; i <= len; i <<= 1) 
			for(int l = (i >> 1), ch = qpow(flag == 1 ? G : iG, (mod - 1) / i), j = 0; j < len; j += i) 
				for(int now = 1, k = j; k < j + l; k++) {
					int pa = f[k], pb = 1ll * f[k + l] * now % mod;
					f[k] = (pa + pb) % mod;
					f[k + l] = (pa - pb + mod) % mod;
					now = 1ll * now * ch % mod;
				}
		if(flag == -1) {
			int nylen = qpow(len, mod - 2);
			for(int i = 0; i < len; i ++) f[i] = 1ll * f[i] * nylen % mod;
		}
	}
};
Poly operator * (Poly aa, Poly bb) {
	int sav = aa.len + bb.len - 1, lim; for(lim = 1; lim <= sav; lim <<= 1);
	aa.len = bb.len = lim;
	init(lim), aa.NTT(1), bb.NTT(1);
	for(int i = 0; i < lim; i++) aa.f[i] = 1ll * aa.f[i] * bb.f[i] % mod;
	aa.NTT(-1), aa.len = sav;
	return aa;
}
void Inv(Poly f, Poly &h) {
	if(f.len == 1) return h.f[0] = qpow(f.f[0], mod - 2), h.len = 1, void();
	int sav = f.len, lim;
	f.len = (sav + 1) / 2, Inv(f, h);
	for(lim = 1; lim <= sav * 2; lim <<= 1);
	fill(f.f + sav, f.f + lim, 0);
	f.len = h.len = lim;
	init(lim);
	f.NTT(1), h.NTT(1);
	for(int i = 0; i < lim; i++) h.f[i] = 1ll * (2ll + mod - 1ll * f.f[i] * h.f[i] % mod) * h.f[i] % mod;
	h.NTT(-1), fill(h.f + sav, h.f + lim, 0), h.len = sav;
}
void Sqrt(Poly f, Poly &h) {
	if(f.len == 1) return h.f[0] = 1, h.len = 1, void();
	int sav = f.len, lim; 
	f.len = (sav + 1) / 2, Sqrt(f, h);
	Poly G; h.len = sav, Inv(h, G);
	for(lim = 1; lim <= sav * 2; lim <<= 1);
	fill(f.f + sav, f.f + lim, 0);
	f.len = h.len = G.len = lim;
	init(lim);
	f.NTT(1), h.NTT(1), G.NTT(1);
	for(int i = 0; i < lim; i++) h.f[i] = (1ll * h.f[i] * h.f[i] % mod + f.f[i]) * G.f[i] % mod * twony % mod;
	h.NTT(-1), fill(h.f + sav, h.f + lim, 0), h.len = sav;
}
int n, m, a[N];
Poly f, g;
int main() {
	scanf("%d%d", &m, &n), f.len = g.len = n + 3;
	int k;
	L(i, 1, m) scanf("%d", &k), f.f[k] = 1;
	L(i, 1, n) f.f[i] = -f.f[i] * 4;
	f.f[0] = 1;
	Sqrt(f, g);
	g.f[0] ++;
	fill(f.f, f.f + n + 3, 0);
	Inv(g, f);
	L(i, 1, n) f.f[i] = 2ll * f.f[i] % mod;
	L(i, 1, n) printf("%d\n", f.f[i]);
	return 0;
}