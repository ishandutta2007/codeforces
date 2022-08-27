#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 7, mod = 1e9 + 7;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int n, p[N][N];
map < ll, int > dp[N + 1];
int h[N + 1][40], f[1 << N], tp[N + 1]; 
ll msk[35]; 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	L(i, 0, n - 1) L(j, 0, n - 1) cin >> p[i][j], p[i][j] = (ll) p[i][j] * qpow (100) % mod;
	L(i, 0, (1 << n) - 1) {
		int z = __builtin_popcount(i);
		f[i] = tp[z]++, h[z][f[i]] = i;
	}
	dp[0][1] = 1;
	L(i, 0, n - 1) {
		L(w, 0, (1 << n) - 1) {
			int prb = 1;
			L(z, 0, n - 1) {
				if(w >> z & 1) prb = (ll) prb * p[i][z] % mod;
				else prb = (ll) prb * (mod + 1 - p[i][z]) % mod;
			}
			L(j, 0, tp[i] - 1) msk[j] = 0;
			L(j, 0, tp[i] - 1) {
				int k = h[i][j];
				L(z, 0, n - 1) if((w >> z & 1) && !(k >> z & 1)) msk[j] |= 1LL << f[k | (1 << z)];
			}
			for (auto u : dp[i]) {
				ll lb = 0;
				L(t, 0, tp[i] - 1) if(u.first >> t & 1) lb |= msk[t];
				(dp[i + 1][lb] += (ll) u.second * prb % mod) %= mod;
			}
		} 
	} 
	cout << dp[n][1] << '\n';
	return 0;
}