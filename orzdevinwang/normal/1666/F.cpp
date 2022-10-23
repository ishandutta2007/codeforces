#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 5005, mod = 998244353;
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

int n, a[N], cnt[N];
int dp[N], xdp[N], S;
void Main() {
	cin >> n, S = n;
	me(cnt, 0), me(dp, 0);
	L(i, 1, n) {
		cin >> a[i];
		cnt[a[i]] += 1;
	}
	dp[0] = 1;
	R(t, n, 1) if(cnt[t]) {
		me(xdp, 0);
		S -= cnt[t];
		L(i, 0, n) if(dp[i]) {
			L(j, 0, 1) {
				int ls = cnt[t] - j, o = 1, prd = dp[i];
				if(i == S + ls) o = 0; //, cout << "I = " << i << endl;
				if(ls) prd = (ll) prd * C(i - o, ls) % mod;
				if(prd) (xdp[i + j - ls] += prd) %= mod;
			}
		}
		swap(dp, xdp); 
//		L(i, 0, n) cout << dp[i] << ' ';
//		cout << '\n';
	}
	cout << dp[0] << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init(5000);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
} 
// 1 3 2 4; 2 3 1 4