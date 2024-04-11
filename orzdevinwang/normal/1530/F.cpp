#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 21, mod = 31607;
int n, w[N][N], a[N][N], inv[mod], ns;
int bf[N][1 << N];
int calc () {
	int res = 0, cbuf = 1;
	L(i, 0, n - 1) L(j, 0, n - 1) cbuf = (ll) cbuf * a[i][j] % mod, a[i][j] = inv[a[i][j]];  
	L(i, 0, n - 1) {
		bf[i][0] = 1;
		L(j, 0, n - 1) bf[i][1 << j] = a[i][j];
		L(j, 0, (1 << n) - 1) {
			int c = j & -j; 
			bf[i][j] = (ll) bf[i][c] * bf[i][j ^ c] % mod;
		} 
	}
	L(i, 0, (1 << n) - 1) {
		int buf = 1;
		L(y, 0, n - 1) buf = (ll) buf * (mod + 1 - bf[y][i]) % mod;
		if(__builtin_popcount(i) & 1) (res += mod - buf) %= mod;
		else (res += buf) %= mod;
	}
	return (ll) res * cbuf % mod;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int s;
	cin >> n;
	inv[1] = 1;
	L(i, 2, mod - 1) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	
	L(i, 0, n - 1) L(j, 0, n - 1) cin >> w[i][j], w[i][j] = (ll) w[i][j] * inv[10000] % mod;
	
	L(i, 0, n - 1) L(j, 0, n - 1) a[i][j] = w[i][j];
	(ns += calc()) %= mod;
	
	L(i, 0, n - 1) L(j, 0, n - 1) a[i][j] = w[i][j];
	s = mod - 1;
	L(i, 0, n - 1) L(j, 0, n - 1) if(i == j) s = (ll) s * a[i][j] % mod, a[i][j] = 1;
	(ns += (ll) s * calc() % mod) %= mod;
	
	L(i, 0, n - 1) L(j, 0, n - 1) a[i][j] = w[i][j];
	s = mod - 1;
	L(i, 0, n - 1) L(j, 0, n - 1) if(i + j == n - 1) s = (ll) s * a[i][j] % mod, a[i][j] = 1;
	(ns += (ll) s * calc() % mod) %= mod;
	
	L(i, 0, n - 1) L(j, 0, n - 1) a[i][j] = w[i][j];
	s = 1;
	L(i, 0, n - 1) L(j, 0, n - 1) if(i == j || i + j == n - 1) s = (ll) s * a[i][j] % mod, a[i][j] = 1;
	(ns += (ll) s * calc() % mod) %= mod;
	
	cout << (mod + 1 - ns) % mod << "\n";
	return 0;
}