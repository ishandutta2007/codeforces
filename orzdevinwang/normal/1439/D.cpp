#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 3005;
int mod, fac[N], ifac[N], inv[N], f[N][N], g[N][N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
}
int C(int n, int m) {
	return (ll) fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int G(int n, int m) {
	if(n == m) {
		int res = 0;
		L(i, 1, n) (res += (ll) g[i - 1][i - 1] * g[n - i][n - i] % mod * C(n - 1, i - 1) % mod) %= mod;
		return (ll) res * (n + 1) % mod;
	} 
	int res = g[n][m - 1];
	L(i, 1, n) (res += (ll) g[i][i] * g[n - i][m - i - 1] % mod * C(n, i) % mod) %= mod;
	return res;
}
int F(int n, int m) {
	if(n == m) {
		int res = 0;
		L(i, 1, n) (res += (ll) f[i - 1][i - 1] * g[n - i][n - i] % mod * C(n - 1, i - 1) % mod) %= mod;
		L(i, 1, n) (res += (ll) g[i - 1][i - 1] * f[n - i][n - i] % mod * C(n - 1, i - 1) % mod) %= mod;
		res = (ll) res * (n + 1) % mod;
		L(i, 1, n) (res += (ll) (i * (i - 1) / 2 % mod + (n - i) * (n - i + 1) / 2 % mod) * 
		g[i - 1][i - 1] % mod * g[n - i][n - i] % mod * C(n - 1, i - 1) % mod) %= mod;
		return res;
	} 
	int res = f[n][m - 1];
	L(i, 1, n) (res += (ll) f[i][i] * g[n - i][m - i - 1] % mod * C(n, i) % mod) %= mod;
	L(i, 1, n) (res += (ll) g[i][i] * f[n - i][m - i - 1] % mod * C(n, i) % mod) %= mod;
	return res;
}
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> m >> n >> mod, init(m);
	L(i, 0, m) g[0][i] = 1;
	L(i, 1, n) L(j, i, m) g[i][j] = G(i, j); 
	L(i, 1, n) L(j, i, m) f[i][j] = F(i, j);
	cout << f[n][m] << "\n";
	return 0;
}