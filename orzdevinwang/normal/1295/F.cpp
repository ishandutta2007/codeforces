#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db long double
#define pii pair<int, int>
#define mkp make_pair
#define sz(x) ((int) x.size())
#define be(x) x.begin()
#define en(x) x.end()
using namespace std;
const int N = 107;
const int mod = 998244353;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int n, m, l[N], r[N], f[N], tot, fl[N], fr[N], ans;
int dp[N][N], s[N][N], g[N][N];
int inv[N], fac[N], ifac[N];
void init(int x) {
	inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	fac[0] = ifac[0] = 1;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
}
int C(int x, int y) {
	return (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	cin >> n, init(n << 1 | 1);
	R(i, n, 1) cin >> l[i] >> r[i], ++r[i], f[++tot] = l[i], f[++tot] = r[i];
	sort(f + 1, f + tot + 1);
	tot = unique(f + 1, f + tot + 1) - f - 1;	
	L(i, 1, n) 
		fl[i] = lower_bound(f + 1, f + tot + 1, l[i]) - f, 
		fr[i] = lower_bound(f + 1, f + tot + 1, r[i]) - f - 1;
	L(i, 1, tot - 1) {
		int res = 1;
		L(j, 0, n) g[i][j] = res, res = (ll) res * inv[j + 1] % mod * (f[i + 1] - f[i] + j) % mod; 
	}
	dp[0][0] = 1;
	L(i, 0, tot - 1) s[0][i] = 1;
	L(i, 1, n) {
		L(j, 1, tot - 1) if(fl[i] <= j && j <= fr[i]) {
			R(a, i - 1, 0) 
				if(fl[a + 1] <= j && j <= fr[a + 1]) (dp[i][j] += (ll) s[a][j - 1] * g[j][i - a] % mod) %= mod;
				else break;
		}
		L(j, 1, tot - 1) s[i][j] = (s[i][j - 1] + dp[i][j]) % mod;
	}
	L(i, 1, tot - 1) (ans += dp[n][i]) %= mod;
	L(i, 1, n) ans = (ll) ans * qpow(r[i] - l[i]) % mod;
	cout << ans << endl;
	return 0;
}