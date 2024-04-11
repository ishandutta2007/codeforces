#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
const int mod = 998244353;
const int G = 3;
const int iG = (mod + 1) / G;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int pp[N];
void polyinit(int len) {
	L(i, 0, len - 1) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (len >> 1)));
}
void NTT(int *f, int len, int flag) {
	L(i, 0, len - 1) if(pp[i] < i) swap(f[pp[i]], f[i]);
	for(int i = 2; i <= len; i <<= 1) 
		for(int j = 0, l = (i >> 1), ch = qpow(flag == 1 ? G : iG, (mod - 1) / i); j < len; j += i) 
			for(int k = j, now = 1; k < j + l; k ++) {
				int pa = f[k], pb = (ll) f[k + l] * now % mod;
				f[k] = (pa + pb) % mod, f[k + l] = (pa + mod - pb) % mod;
				now = (ll) now * ch % mod;
			}
	if(flag == -1) {
		int nylen = qpow(len);
		L(i, 0, len - 1) f[i] = (ll) f[i] * nylen % mod;
	}
}
int up(int x) {
	int lim = 1;
	for(; lim <= x; lim <<= 1);
	return lim;
}
int fac[N], ifac[N];
int C(int x, int y) {
	if(y < 0 || y > x) return 0;
	return (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
void math_init(int x) {
	fac[0] = 1;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod;
	ifac[x] = qpow(fac[x]);
	R(i, x, 1) ifac[i - 1] = (ll) ifac[i] * i % mod;
}
int n, dp[2][N], a[N], b[N];
int A[N], B[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	math_init(200000);
	int bf = 0, now = 0;
	dp[0][0] = 1;
	L(i, 1, n) {
		bf ^= 1;
		memset(dp[bf], 0, sizeof(dp[bf]));
		cin >> a[i] >> b[i];
		int las = now;
		now += a[i] - b[i];
		
		int mx = max(now, las), lim = up(now + las + mx);
		
		L(j, 0, lim - 1) A[j] = B[j] = 0; 
		L(j, 0, las) A[j] = dp[bf ^ 1][j];
		L(j, -mx, mx) B[j + mx] = C(a[i] + b[i], b[i] + j);
		polyinit(lim);
		NTT(A, lim, 1), NTT(B, lim, 1);
		L(j, 0, lim - 1) A[j] = (ll) A[j] * B[j] % mod;
		NTT(A, lim, -1);
		L(j, 0, now) dp[bf][j] = A[j + mx];
	}
	int sum = 0;
	L(i, 0, now) (sum += dp[bf][i]) %= mod;
	cout << sum << endl;
	return 0;
}