#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
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
int T;

int n;
int c[N];
char s[N];
void Main () {
	cin >> n >> (s + 1);
	int g = 0;
	L (i, 1, n) {
		if(s[i] == '1') {
			++g, c[i - g] ++;
		} 
	}
	n -= g;
	L(i, 0, n) c[i] /= 2;
	int sum = 0;
	L(i, 0, n) sum += c[i];
	cout << C(n + sum, sum) << "\n";
	L(i, 0, n) c[i] = 0;
}
int main() { 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init(200000);
	cin >> T;
	while (T--) Main();
	return 0;
}