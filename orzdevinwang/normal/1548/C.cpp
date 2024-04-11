#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 6e6 + 7, mod = 1e9 + 7;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
} 
int C(int x, int y) {
	return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int n, q, g[4], f[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	init ((n + 2) * 3);
	g[1] = mod - 1, g[2] = mod - inv[3];
	L(i, 0, (n + 1) * 3 - 1) {
		f[i] = (ll) C((n + 1) * 3, i + 1) * inv[3] % mod;
		L(j, 1, min(i, 2)) 
			(f[i] += (ll) g[j] * f[i - j] % mod) %= mod; 
	}
	while (q--) {
		int x;
		cin >> x;
		cout << f[x] << "\n"; 
	}
	return 0;
}