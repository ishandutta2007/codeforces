#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define ull unsigned long long
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 3e5 + 7, M = (1 << 19), mod = 998244353, G = 3, iG = (mod + 1) / G, inv2 = (mod + 1) / 2;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int n, s, f[N], a[N], inv[N], ns;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i], (s += a[i]) %= mod;
	inv[1] = 1;
	L(i, 2, s) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, s - 1) f[i + 1] = (ll) (f[i] + mod - 1) * i % mod * (n - 1) % mod * inv[s - i] % mod;
	L(i, 1, s) (f[i] += f[i - 1]) %= mod;
	L(i, 1, n) (ns += f[a[i]]) %= mod;
	(ns += mod - f[s]) %= mod;
	cout << ns << "\n";
	return 0;
}