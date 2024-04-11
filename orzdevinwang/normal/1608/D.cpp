#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 5e5 + 7, mod = 998244353;
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
int n, ns, cnt, now;
char s[N][5];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n;
	init (n * 2);
	L(i, 1, n) cin >> s[i];
	bool ok = true;
	L(i, 1, n) if(s[i][0] == 'B' || s[i][1] == 'W') ok = false;
	if(ok) (ns += 1) %= mod;
	ok = true; 
	L(i, 1, n) if(s[i][0] == 'W' || s[i][1] == 'B') ok = false;
	if(ok) (ns += 1) %= mod;
	L(i, 1, n) L(j, 0, 1) {
		if(s[i][j] == 'B') now += 1;
		if(s[i][j] == '?') cnt += 1;
	}
	if(now <= n) (ns += C(cnt, n - now)) %= mod;
	int ret = 1;
	L(i, 1, n) {
		int cnt = 0;
		if(s[i][0] != 'B' && s[i][1] != 'W') cnt += 1;
		if(s[i][0] != 'W' && s[i][1] != 'B') cnt += 1;
		ret = (ll) ret * cnt % mod;
	}
	(ns += mod - ret) %= mod;
	cout << ns << '\n';
	return 0;
}