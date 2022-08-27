#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define ull unsigned long long 
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
} 
int n, k, mu[N], pw[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	mu[1] = 1;
	L(i, 1, n) for(int j = 2 * i; j <= n; j += i) mu[j] -= mu[i];
	int ns = 0, xn = n - 1;
	pw[0] = 1;
	L(i, 1, n) pw[i] = (ll) pw[i - 1] * k % mod;
	L(g, 1, xn) {
		L(t, 1, xn / g) if(mu[t]) {
			int pm = xn / (g * t);
			L(i, 2, pm * 2) {
				int r = min(i - 2 + 1, pm * 2 - i + 1);
				(ns += (ll) (mu[t] * r + mod) * pw[max(g, i * g * t - n)] % mod) %= mod;
			}
		}
	}
	ns = (ll) ns * qpow(qpow(k), n) % mod;
	cout << ns << '\n';
	return 0;
}