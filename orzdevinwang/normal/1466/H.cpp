#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); i++)
#define R(i, j, k) for (int i = (j); i >= (k); i--) 
#define sz(a) ((int) (a).size())
#define ll long long 
#define vi vector < int > 
using namespace std;
const int N = 1 << 12, mod = 1e9 + 7;
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
int n, p[N], cn[N];
int w[N], dp[N], all[N], pop[N], xg[N], pw[N], f[N];
bool vis[N]; 
vi S;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> p[i];
	init (n);
	pw[0] = 1;
	L(i, 1, n * n) pw[i] = (ll) pw[i - 1] * 2 % mod;
	L(i, 1, n) if(!vis[i]) {
		int x = i, rt = 0; 
		while (!vis[x]) vis[x] = true, rt += 1, x = p[x];
		cn[rt] += 1;
	}
	int ret = 1;
	L(i, 1, n) if(cn[i]) 
		w[i] = ret, ret *= cn[i] + 1, S.push_back(i);
	L(k, 0, n) 
		L(j, 0, n - 1) 
			(f[k] += (ll) fac[j] * fac[n - j - 1] % mod * C(k, j) % mod) %= mod;
	L(i, 0, ret - 1) {
		xg[i] = 1;
		for (const int &j : S) 
			all[i] += j * ((i / w[j]) % (cn[j] + 1)), pop[i] += (i / w[j]) % (cn[j] + 1);
		for (const int &j : S) 
			xg[i] = (ll) xg[i] * ifac[(i / w[j]) % (cn[j] + 1)] % mod;
	}
	dp[0] = 1;
	L(i, 0, ret - 1) {
		L(j, i + 1, ret - 1) {
			bool op = true;
			int cr = ((pop[i] - pop[j]) & 1) ? 1 : mod - 1;
			for (const int &k : S) 
				if((i / w[k]) % (cn[k] + 1) > (j / w[k]) % (cn[k] + 1)) {
					op = false;
					break;
				}
			if(!op) continue;
			cr = (ll) cr * qpow (f[all[ret - j - 1]], all[j - i]) % mod * xg[j - i] % mod; 
			(dp[j] += (ll) dp[i] * cr % mod) %= mod;
		}
	}
	int ns = dp[ret - 1];
	L(i, 1, n) ns = (ll) ns * fac[cn[i]] % mod; 
	cout << ns << '\n';
	return 0;
}