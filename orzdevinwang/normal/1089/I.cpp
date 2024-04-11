#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 405;
int n = 400, T, mod, f[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> T >> mod, f[1] = 1;
 	L(i, 2, n) {
 		L(j, 1, i - 1) (f[i] += (ll) (j + 1) * f[j] % mod * f[i - j] % mod) %= mod;
 		L(j, 2, i - 1) (f[i] += (ll) j * f[j] % mod * f[i - j + 1] % mod) %= mod;
 		f[i] = mod - f[i];
	}
	L(i, 1, n) {
		f[i] = mod - f[i];
		if(i & 1) (f[i] += 2) %= mod;
		else (f[i] += mod - 2) %= mod;
	}
	f[2] = 2; 
	while (T--) {
		int x;
		cin >> x, cout << f[x] << "\n";
	}
	return 0;
}