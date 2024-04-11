#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7, mod = 998244353, inv2 = (mod + 1) / 2, inv6 = (mod + 1) / 6;
int n, f[N], g[N], c[N], ns;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	f[0] = g[0] = 2;
	L(i, 1, n) 
		f[i] = ((ll) f[i - 1] * f[i - 1] % mod + f[i - 1]) % mod * inv2 % mod, (f[i] += 1) %= mod;
	L(i, 1, n) {
		(g[i] += (ll) f[i - 1] * f[i - 1] % mod * f[i - 1] % mod) %= mod;
		(g[i] += (ll) 3 * f[i - 1] % mod * f[i - 1] % mod) %= mod;
		(g[i] += (ll) 2 * f[i - 1] % mod) %= mod;
		g[i] = (ll) g[i] * inv6 % mod;
		
		(g[i] += 1) %= mod; 
	}
	ns = ((g[n] - g[n - 1] + mod) % mod * 2 % mod + mod - 1) % mod;
	
	L(i, 1, n) c[i] = (f[i] - f[i - 1] + mod) % mod;
	c[0] = 1;
	
	L(i, 1, n - 2) 
		(ns += (ll) (c[i] - c[i - 1] + mod) % mod * (c[n - 1 - i] + mod - 1) % mod) %= mod;
	cout << ns << "\n";
	return 0;
}