#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 524288;
const int mod = 998244353;
const int G = 3;
const int iG = (mod + 1) / G;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int pp[N];
void polyinit(int len) {
	L(i, 0, len - 1) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (len >> 1)));
}
void NTT(int *f, int len, int flag) {
	L(i, 0, len - 1) if(pp[i] < i) swap(f[pp[i]], f[i]);
	for(int i = 2; i <= len; i <<= 1) 
		for(int j = 0, l = (i >> 1), ch = qpow(flag == 1 ? G : iG, (mod - 1) / i); j < len; j += i) 
			for(int k = j, now = 1; k < j + l; k ++) {
				int pa = f[k], pb = (ll) f[k + l] * now % mod;
				f[k] = (pa + pb) % mod, f[k + l] = (pa + mod - pb) % mod;
				now = (ll) now * ch % mod;
			}
	if(flag == -1) {
		int nylen = qpow(len);
		L(i, 0, len - 1) f[i] = (ll) f[i] * nylen % mod;
	}
}
int up(int x) {
	int lim = 1;
	for(; lim <= x; lim <<= 1);
	return lim;
}
int n, g[N], p[N], fac[N], ifac[N];
int binom(int x, int y) {
	return (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int ans[N];
void math_init(int x) {
	fac[0] = 1;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod;
	ifac[x] = qpow(fac[x]);
	R(i, x, 1) ifac[i - 1] = (ll) ifac[i] * i % mod;
}
int A, B;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> A >> B;
	if(n == 1) return cout << (A == 1 && B == 1) << endl, 0;
	math_init(n);
	--n;
	int tmp = log2(n), len = 1;
	ans[1] = 1;
	R(t, tmp - 1, 0) {
		int lim = up(len * 2);
		L(i, 0, len) p[len - i] = (ll) ans[i] * fac[i] % mod, g[i] = (ll) qpow(len, i) * ifac[i] % mod;
		fill(p + len + 1, p + lim, 0), fill(g + len + 1, g + lim, 0);
		polyinit(lim);
		NTT(p, lim, 1), NTT(g, lim, 1);
		L(i, 0, lim - 1) g[i] = (ll) p[i] * g[i] % mod;
		NTT(g, lim, -1);
		fill(g + len + 1, g + lim, 0), reverse(g, g + len + 1);
		L(i, 0, len) g[i] = (ll) g[i] * ifac[i] % mod;
		NTT(ans, lim, 1), NTT(g, lim, 1);
		L(i, 0, lim - 1) ans[i] = (ll) ans[i] * g[i] % mod;
		NTT(ans, lim, -1);
		len <<= 1;
		if(n >> t & 1) {
			R(i, len, 0) ans[i + 1] = ans[i];
			ans[0] = 0;
			L(i, 0, len) (ans[i] += (ll) ans[i + 1] * len % mod) %= mod;
			++len;
		}
	}
	cout << (ll) ans[A + B - 2] * binom(A + B - 2, A - 1) % mod << endl;
	return 0;
}