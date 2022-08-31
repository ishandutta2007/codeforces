#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = 55, mod = 1e9 + 7;
int fac[N], ifac[N], inv[N];
void exp(int *f, int *g, int n) {
	g[0] = 1;
	L(i, 1, n) {
		L(j, 1, i) (g[i] += (ll) f[j] * j % mod * g[i - j] % mod) %= mod;
		g[i] = (ll) g[i] * inv[i] % mod;
	}
}
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
}
int C(int x, int y) {
	return y < 0 || x < y ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int n, m, M, f[N][N], d[N][N], q[N], p[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m, init(max(n, m) + 3);
	f[0][1] = 1, d[0][0] = 1, M = n + 1;
	L(i, 1, n) {
		L(j, 0, M) q[j] = 0;
		L(j, 0, i - 1) {
			L(a, 1, M) 
				L(b, 1, M) (q[min(a, b)] += (ll) f[j][a] * f[i - 1 - j][b] % mod) %= mod;
		}
//		L(j, 0, M) cout << q[j] << " ";
//		cout << "\n";
		L(p, 1, M) {
			R(j, n, 0) R(k, M, 0) {
				int now = d[j][k];
				L(z, 1, min((n - j) / i, (M - k) / p)) {
					now = (ll) now * (z + q[p] - 1) % mod * inv[z] % mod;
					(d[j + i * z][k + p * z] += now) %= mod;
				}
			}
		}
//		cout << " = " << d[4][4] << "\n";
		R(j, M, 1) f[i][j] = d[i][j - 1];
		f[i][0] = 0;
//		L(j, 0, M) cout << setw(5) << f[i][j];
//		cout << "\n";
	}
	cout << f[n][m] << "\n";
	return 0;
}