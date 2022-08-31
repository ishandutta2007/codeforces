#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 2e6 + 7, mod = 998244353;
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
int n, lcp[N], ns;
int main() {
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> n;
	init (n + 2);
	lcp[0] = n ;
	L(i, 1, n - 1) 
		lcp[i] = (ll) fac[n] * ifac[n - i + 1] % mod * ((ll) (n - i) * (n - i) % mod + 1) % mod;
	L(i, n, n * 2 - 2) 
		lcp[i] = (fac[n] + mod - lcp[i - n]) % mod;
	int l = (ll) fac[n] * n % mod; 
	ns = (ll) l * (l + 1) / 2 % mod;
	L(i, 0, n * 2 - 2) (ns += mod - (ll) lcp[i] * i % mod) %= mod;
	cout << ns << '\n';
	return 0;
}