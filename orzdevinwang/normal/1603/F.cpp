#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e7 + 7, mod = 998244353, inv2 = (mod + 1) / 2;
int n, k, x, ns, pw[N];
int fac[N], ifac[N];
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
void q_init(int x) {
	pw[0] = 1;
	L(i, 1, x) pw[i] = (ll) pw[i - 1] * 2 % mod;
	L(i, 1, x) fac[i] = (fac[i - 1] + pw[i - 1]) % mod;
	fac[0] = ifac[0] = 1;
	L(i, 1, x) ifac[i] = (ll) qpow (fac[i]) * ifac[i - 1] % mod, fac[i] = (ll) fac[i - 1] * fac[i] % mod;
} 
int q_C(int x, int y) {
	return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

void Main () {
	cin >> n >> k >> x;
	if (x == 0) {
		int ret = 1;
		L(i, 0, min(n - 1, k)) 
			ret = (ll) ret * (pw[k] - pw[i] + mod) % mod;
		cout << ret << '\n'; 
		return ;
	} 
	else { 
		/*
			 r  ?
			
			 prod_{i=0...r} \frac{1}{1-2^i} [x^{n-r}] = C(n,r)_q
		*/
		ns = 0;
		int ret = 1, cp = qpow (2, n);
		L(i, 1, min(n, k)) {
			ret = (ll) ret * (pw[k] - pw[i - 1] + mod) % mod;
			ret = (ll) ret * (cp - 1) % mod, cp = (ll) cp * inv2 % mod;
			int f = (ll) ret * ifac[i] % mod;
			(ns += (ll) f * (pw[k] - pw[i] + mod) % mod) %= mod;
		}
		ns = (ll) ns * qpow (pw[k] - 1) % mod;
		cout << (ns + 1) % mod << "\n";
	}
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	q_init (N - 7);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}