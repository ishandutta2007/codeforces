#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7, inv2 = (mod + 1) / 2;
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
int n, dp[N], suf[N];
void Main() {
	cin >> n;
	int qwq = 1;
	L(t, 0, n + 1) dp[t] = suf[t] = 0;
	dp[n] = suf[n] = 1;
	R(j, n - 1, 1) {
		dp[j] = (suf[j + 1] + mod - suf[min(j * 2 - 1, n) + 1]) % mod;
		suf[j] = (suf[j + 1] + dp[j]) % mod;
//		L(k, j + 1, min(j * 2 - 1, n)) (dp[j] += dp[k]) %= mod;
	} 
	L(x, 1, n - 1) {
		int ret = 0;
		ret = (ll) qpow(inv2, (x + 1) / 2) % mod;
		ret = (ll) ret * dp[x] % mod * qpow(inv2, n - x - 1) % mod;
		cout << ret << '\n';
		(qwq += mod - ret) %= mod;
	}
	cout << qwq << '\n';
} 
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}