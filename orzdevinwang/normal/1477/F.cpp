#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 51, M = 2007, mod = 998244353;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[M], ifac[M], inv[M];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
} 
int C(int x, int y) {
	return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

inline int sign(int x) {
	return (x & 1) ? mod - 1 : 1; 
} 

int n, k, a[N], sum, als, f[M], dp[N][M], new_dp[N][M];
int r[2][M];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	init(M - 2);
	
	L(i, 1, n) cin >> a[i], sum += a[i];
	
	dp[0][0] = 1;
	L(i, 1, n) {
		
		int t = (a[i] - 1) / k;
		
		me(r, 0);
		L(j, 0, t) {
			int w = (ll) (a[i] - j * k) * qpow(sum) % mod;
			if(j > 0) r[1][j] = (ll) qpow(w, j - 1) * ifac[j - 1] % mod * sign(j) % mod;
			r[0][j] = (ll) qpow(w, j) * ifac[j] % mod * sign(j) % mod;
		}
		
		me(new_dp, 0);
		L(j, 0, i - 1) 
			L(k, 0, als) 
				L(o, 0, 1) 
					L(u, 0, t) 
						(new_dp[j + o][k + u] += (ll) dp[j][k] * r[o][u] % mod) %= mod;
		swap(dp, new_dp);
		
		als += t;
	}
	
	int ns = 0;
	L(i, 0, n) 
		L(j, 1, als) if(dp[i][j]) {
			int w = (ll) (sum - j * k) * qpow(sum) % mod;
			int ti = j - i;
			(ns += mod - (ll) dp[i][j] * fac[ti] % mod * 
				qpow(qpow(mod + 1 - w), ti + 1) % mod) %= mod;
		}
	cout << ns << '\n';
	return 0;
}