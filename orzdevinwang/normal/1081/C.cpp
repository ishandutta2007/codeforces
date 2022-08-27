#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
const int mod = 998244353;
int n, m, k;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N];
int binom(int x, int y) {
	return (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
void init(int x) {
	fac[0] = 1, ifac[0] = 1;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = qpow(fac[i]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	init(n);
	cout << (ll) m * qpow(m - 1, k) % mod * binom(n - 1, k) % mod << endl;
	return 0;
}