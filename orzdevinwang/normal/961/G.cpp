#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 524288;
const int mod = 1e9 + 7;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N];
int binom(int x, int y) {
	return (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
void math_init(int x) {
	fac[0] = 1;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod;
	ifac[x] = qpow(fac[x]);
	R(i, x, 1) ifac[i - 1] = (ll) ifac[i] * i % mod;
}
int fpow(int x) {
	return x % 2 ? mod - 1 : 1;
}
int n, m, all, w[N], ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m, math_init(n);
	L(i, 1, n) cin >> w[i], (all += w[i]) %= mod;
	if(m == 1) return cout << (ll) all * n % mod << endl, 0;
	L(i, 0, m - 1) {
		(ans += (ll) fpow(m - 1 - i) * binom(m - 1, i) % mod * 
		(qpow(i + 1, n - 1) % mod + (ll) (n - 1) * qpow(i + 1, n - 2) % mod) % mod) %= mod;
	}
	ans = (ll) ans * all % mod * ifac[m - 1] % mod;
	cout << ans << endl;
	return 0;
}