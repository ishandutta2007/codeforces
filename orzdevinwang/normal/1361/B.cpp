#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = (1 << 20), mod = 1e9 + 7;
int qpow (int x, int y = mod - 2) {
	int ret = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) ret = (ll) ret * x % mod;
	return ret;
}
int n, p, f[N], real;
bool vis[N];
void Main () {
	cin >> n >> p;
	L(i, 1, n) cin >> f[i];
	if(p == 1) return cout << n % 2 << "\n", void ();
	sort(f + 1, f + n + 1), reverse(f + 1, f + n + 1);
	int S = 0, real = 0;
	L(i, 1, n) {
		if(i != 1 && S) {
			real = (ll) real * qpow (p, f[i - 1] - f[i]) % mod;
			L(j, 1, f[i - 1] - f[i]) {
				S = min((ll) mod, (ll) S * p);
				if(S == mod) break ;	
			}
		} 
		S -= 1, (real += mod - 1) %= mod;
		if(S < 0) S = - S;
		if(S <= 2000000) real = S;
//		cout << S << " and " << real << "\n";
	} 
	real = (ll) real * qpow (p, f[n]) % mod;
	cout << real << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}