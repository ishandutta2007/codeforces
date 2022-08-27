#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define uint unsigned int
using namespace std;
const int N = 3e5 + 7;
const int mod = 998244353;
const int G = 3;
const int iG = (mod + 1) / G;
int qpow(int x, ll y = mod - 2, int p = mod) {
	int res = 1;
	for(; y; x = 1ll * x * x % p, y >>= 1) if(y & 1) res = 1ll * res * x % p;
	return res;
}
int n, f[N], g[N];
ll m;
int lim, pp[N];
void NTT(int *f, int flag) {
	L(i, 0, lim - 1) if(pp[i] < i) swap(f[pp[i]], f[i]);
	for(int i = 2; i <= lim; i <<= 1) {
		int ch = qpow(flag == 1 ? G : iG, (mod - 1) / i);
		for(int j = 0, l = (i >> 1); j < lim; j += i) 
			for(int k = j, now = 1; k < j + l; k ++) {
				int pa = f[k], pb = 1ll * f[k + l] * now % mod;
				f[k] = (pa + pb) % mod, f[k + l] = (pa - pb + mod) % mod, now = 1ll * now * ch % mod;
			}
	} 
	if(flag == -1) {
		int nylen = qpow(lim);
		L(i, 0, lim - 1) f[i] = 1ll * f[i] * nylen % mod;
	}
}
void poly_init() {
	L(i, 0, lim - 1) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (lim >> 1)));
}
void upto(int x) { lim = 1; for(; lim <= x; lim <<= 1); }
int fac[N], ifac[N];
void math_init(int x) {
	fac[0] = 1; 
	L(i, 1, x) fac[i] = 1ll * fac[i - 1] * i % mod; 
	ifac[x] = qpow(fac[x]);
	R(i, x, 1) ifac[i - 1] = 1ll * ifac[i] * i % mod;
}
int fpow(int x) {
	if(x % 2 == 0) return 1;
	else return mod - 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 0, n) cin >> f[i];
	math_init(n);
	reverse(f, f + n + 1);
	L(i, 0, n) f[i] = (ll) f[i] * fac[n - i] % mod, g[i] = ifac[i]; 
	upto(n << 1), poly_init();
	NTT(f, 1), NTT(g, 1);
	L(i, 0, lim - 1) g[i] = (ll) f[i] * g[i] % mod;
	NTT(g, -1);
	L(i, 0, n) g[i] = (ll) g[i] * ifac[n - i] % mod;
	reverse(g, g + n + 1);
	L(i, 0, n) g[i] = (ll) g[i] * qpow(qpow(i + 1), m) % mod;
	reverse(g, g + n + 1);
	L(i, 0, n) g[i] = (ll) g[i] * fac[n - i] % mod, f[i] = (ll) ifac[i] * fpow(i) % mod;
	L(i, n + 1, lim - 1) g[i] = f[i] = 0;
	NTT(g, 1), NTT(f, 1);
	L(i, 0, lim - 1) f[i] = (ll) f[i] * g[i] % mod;
	NTT(f, -1); 
	L(i, 0, n) f[i] = (ll) f[i] * ifac[n - i] % mod;
	reverse(f, f + n + 1);
	L(i, 0, n) cout << f[i] << " ";
	cout << "\n";
	return 0;
}