#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e7 + 7;
const int mod = 998244353;
inline int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
inline void ad(int &x, int y) {
	x += y, x -= mod; x += x >> 31 & mod;
}
inline int Sum(int x, int y) {
	x += y, x -= mod, x += x >> 31 & mod;
	return x;
}
int n, m, k, c, w, ans, f[N], inv[N];
bool Prime[N];
int p[N >> 3], Pw[N], tot;
void minit(int x) {
	inv[1] = Pw[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 2, x) {
		if(!Prime[i]) p[++tot] = i, Pw[i] = qpow(i, k);
		for(int j = 1; p[j] * i <= x && j <= tot; j++) {
			Prime[p[j] * i] = 1, Pw[p[j] * i] = (ll) Pw[p[j]] * Pw[i] % mod;
			if(i % p[j] == 0) break;
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	minit(k);
	if(m == 1) return printf("%d\n", qpow(n, k)), 0;
	c = qpow(m - 1), w = mod - (ll) c * qpow(c + 1) % mod;
	f[min(n, k)] = 1;
	int now = 1;
	if(n <= k) R(i, n - 1, 0) f[i] = (ll) (w + 1) * f[i + 1] % mod;
	else R(i, k - 1, 0) {
		now = (ll) now * w % mod * (n - i - 1) % mod * inv[k - i] % mod;
		f[i] = Sum((ll) (w + 1) * f[i + 1] % mod, now);
	}
	now = 1;
	L(i, 0, k) {
		ad(ans, (ll) now * Pw[i] % mod * f[i] % mod);
		now = (ll) now * (n - i) % mod * (mod - w) % mod * inv[i + 1] % mod;
	}
	ans = (ll) ans * qpow(c + 1, n) % mod;
	ans = (ll) ans * qpow((ll) (m - 1) * qpow(m) % mod, n) % mod;
	printf("%d\n", ans);
	return 0;
}