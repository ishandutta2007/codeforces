#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 555;
const int mod = 1e9 + 7;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int S[N][N], fac[N], ifac[N], inv[N], pre[N];
int s[N];
int C(int x, int y) {
	return (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
void math_init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
	S[0][0] = 1;
	L(i, 1, x) {
		L(j, 1, x) S[i][j] = (ll) s[j - 1] * inv[i] % mod;
		L(j, 0, x) (s[j] += S[i - 1][j]) %= mod;
	}
}
int calc(int k) {
	int res = 0;
	L(i, 0, k) (res += (ll) S[k + i][i] * pre[i + k] % mod) %= mod;
	return res;
}
int n, k, ans[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	math_init(400);
	cin >> n >> k;
	pre[0] = 1;
	L(i, 1, k * 2) pre[i] = (ll) pre[i - 1] * (n - i + 1) % mod;
	
	L(i, 0, k) {
		ans[i] = calc(i);
		if(i > 1) (ans[i] += ans[i - 2]) %= mod;
		if(i > 0) cout << ans[i] << " ";
	}
	return 0;
}