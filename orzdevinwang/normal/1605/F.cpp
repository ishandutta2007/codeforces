#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 8 ;
int mod;
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
int hC (int x, int y) {
	int ret = ifac[y];
	L(i, 1, y) ret = (ll) ret * (x - i + 1) % mod;
	return ret;
}
int n, k, f[N][N], g[N][N], h[N][N], pw[N * N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> k >> mod, init (max (n, k)); 
	pw[0] = 1;
	L(i, 1, n * k) pw[i] = (ll) pw[i - 1] * 2 % mod;
	L(u, 0, n) {
		L(v, 0, k) 
			g[u][v] = qpow (2, u * v), h[u][v] = (ll) hC (qpow (2, v) - 1, u) * fac[u] % mod;
		L(v, 0, k) 
			L(t, 0, v - 1) 
				(g[u][v] += mod - (ll) C(v, t) * g[u][t] % mod) %= mod, 
				(h[u][v] += mod - (ll) C(v, t) * h[u][t] % mod) %= mod;
	}
	f[0][0] = 1;
	L(i, 1, n) {
		L(u, 0, k) {
			L(j, 0, i - 1) L(v, 0, u - 1) if(f[j][v])
				(f[i][u] += (ll) f[j][v] * C(u, v) % mod * C(i, j) % mod * 
					h[i - j][u - v] % mod * pw[(i - j) * v] % mod) %= mod; 
			f[i][u] = (mod + g[i][u] - f[i][u]) % mod;
		}
	}
	if(n & 1) {
		int ns = 0;
		L(u, 0, k) {
			int ret = g[n][u];
			L(j, 0, n - 2) L(v, 0, u - 1) 
				(ret += mod - (ll) f[j][v] * C(u, v) % mod * C(n, j) % mod * 
					h[n - j][u - v] % mod * pw[(n - j) * v] % mod) %= mod; 
			(ns += (ll) ret * C(k, u) % mod) %= mod;
		}
		cout << ns << '\n';
	}
	else {
		int ret = 0;
		L(i, 0, k) (ret += (ll) f[n][i] * C(k, i) % mod) %= mod;
		cout << ret << '\n';	
	}
	return 0;
}