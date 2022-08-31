#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = 2e3 + 7, mod = 998244353;
int fac[N], ifac[N], inv[N], pw[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = pw[0] = 1;
	L(i, 2, x) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod, pw[i] = (ll) pw[i - 1] * 2 % mod;
}
int C(int x, int y) {
	return y < 0 || x < y ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int n, f[N][N], g[N][N], a[N], ns;
char s[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> (s + 1), n = strlen(s + 1), init(n + 3);
	f[0][0] = g[n + 1][0] = a[0] = 1;
	int yiw = 0, p = 0; 
	L(i, 1, n) {
		if(s[i] != ')') L(k, 1, n) f[i][k] = C(yiw, k - p - 1);
		yiw += (s[i] == '?'), p += (s[i] == '(');
	}
	p = yiw = 0;
	R(i, n, 1) {
		if(s[i] != '(') L(k, 1, n) g[i][k] = C(yiw, k - p - 1);
		yiw += (s[i] == '?'), p += (s[i] == ')');
	}
	L(t, 1, n) {
		int sum = 0;
		L(i, 1, n) {
			if(s[i] == '?') sum = (ll) sum * 2 % mod;
			(sum += f[i][t]) %= mod, (ns += (ll) sum * g[i + 1][t] % mod) %= mod;
		}
	}
	cout << ns << "\n";
	return 0;
}