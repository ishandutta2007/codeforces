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
#define vi vector<int>
using namespace std;
const int N = 4e5 + 7, mod = 998244353;
int ns, n, m;
int fac[N], inv[N], ifac[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
}
int C(int x, int y) {
	return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int main() {
	cin >> n >> m, init(max(n, m) * 4);
	L(z, 1, m - 1) {
		int now = 0;
		R(r1, n - 1, 1) {
			(now += (ll) C(r1 + m - z - 1, m - z - 1) * C(n - r1 + m - z - 1, m - z) % mod) %= mod;
			(ns += (ll) C(r1 + z - 1, z) * C(n - r1 + z - 1, z - 1) % mod * now % mod) %= mod;
		}
	}
	L(p, 1, n) {
		int now = 0;
		L(z1, 1, m - 1) {
			(now += (ll) C(n - p + z1 - 2, z1 - 2) * C(n - p + m - z1, m - z1 + 1) % mod) %= mod; 
			(ns += (ll) C(p + z1 - 1, z1) * C(p + m - z1 - 1, m - z1 - 1) % mod * now % mod) %= mod;	
		}
	}
	ns = (ll) ns * 2 % mod;
	cout << ns << "\n";
	return 0;
}