#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 6, mod = 1e9 + 7;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int n, p[N][N], dp[N + 1][1 << 20]; //  
int h[N + 1][30], msk[1 << 20], f[1 << N], tp[N + 1]; 
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
			L(j, 0, tp[i] - 1) msk[1 << j] = 0;
			L(j, 0, tp[i] - 1) {
				int k = h[i][j];
				L(z, 0, n - 1) 
					if((w >> z & 1) && !(k >> z & 1)) 
						msk[1 << j] |= 1 << f[k | (1 << z)];
			}
			msk[0] = 0;
			L(j, 0, (1 << tp[i]) - 1) {
				int lb = j & -j;
				msk[j] = msk[lb] | msk[j ^ lb];
				(dp[i + 1][msk[j]] += (ll) dp[i][j] * prb % mod) %= mod;
			}
		} 
	} 
	cout << dp[n][1] << '\n';
	return 0;
}