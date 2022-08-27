#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std; 
const int N = 2333, mod = 998244353; 
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
int n, a, b;
int p, rp, ip, irp;
int g[N], ns[N], w[N];
int dp[N][N], dc[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> a >> b;
	p = (ll) a * qpow (b) % mod;
	rp = (mod + 1 - p) % mod;
	ip = qpow (p);
	irp = qpow (rp);
	L(i, 1, n) 
		w[i] = (ll) qpow (p, i - 1) * qpow (irp, i) % mod;
	dp[0][0] = 1;
	L(i, 0, n) 
		L(j, 0, i) 
			(dp[i + 1][j] += dp[i][j]) %= mod, (dp[i + 1][j + 1] += (ll) w[i + 1] * dp[i][j] % mod) %= mod;
	g[1] = 1, ns[1] = 0;
	L(i, 2, n) {
		L(k, 1, i) {
			dc[k] = dp[i][k];
			dc[k] = (ll) dc[k] * qpow ((ll) ip * rp % mod, k * (k - 1) / 2) % mod;
			dc[k] = (ll) dc[k] * qpow (rp, (i - k + 1) * k) % mod;
			dc[k] = (ll) dc[k] * g[k] % mod;
		}
		g[i] = 1;
		L(k, 1, i - 1) 
			(g[i] += mod - dc[k]) %= mod;
		ns[i] = i * (i - 1) / 2;
		L(k, 1, i - 1) (ns[i] += (ll) dc[k] * (ns[k] + ns[i - k] - (i - k) * (i - k - 1) / 2) % mod) %= mod;
//		cout << "ns = " << (ll) ns[i] * 4 % mod << '\n';
		ns[i] = (ll) ns[i] * qpow (mod + 1 - g[i]) % mod;
//		cout << (ll) dc[1] * 4 % mod << '\n';
//		cout << "dc = " << (ll) dc[1] * 4 % mod << '\n';
//		cout << (ll) ns[i] * 16 % mod << '\n';
	}
	cout << ns[n] << '\n';
	return 0;
}