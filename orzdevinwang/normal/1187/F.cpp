#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db long double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
const int mod = 1e9 + 7;
int qpow(int x, int y) {
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
}
int ny(int x) { return qpow(x, mod - 2); }
int n, l[N], r[N], kk[N], ans, S[N], P[N], sum;
int main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &l[i]);
	L(i, 1, n) scanf("%d", &r[i]);
	L(i, 1, n) kk[i] = ny(r[i] - l[i] + 1);
	L(i, 1, n) {
		int L = max(l[i - 1], l[i]), R = min(r[i - 1], r[i]);
		if(L > R) S[i] = 0;
		else S[i] = 1ll * (R - L + 1) * kk[i] % mod * kk[i - 1] % mod;
		P[i] = (mod + 1 - S[i]) % mod;
		(sum += P[i]) %= mod;
	}
	ans = sum;
	L(i, 1, n) {
		(ans += 1ll * P[i] * ((0ll + sum - P[i - 1] - P[i] - P[i + 1]) % mod + mod) % mod) %= mod;
		if(i >= n) continue;
		(ans += 2ll * (0ll + P[i] + P[i + 1] + mod - 1) % mod) %= mod;
		int L = max(l[i - 1], max(l[i], l[i + 1])), R = min(r[i - 1], min(r[i], r[i + 1]));
		if(L > R) continue;
		(ans += 2ll * kk[i] * kk[i - 1] % mod * kk[i + 1] % mod * (R - L + 1) % mod) %= mod;
	}
	printf("%d\n", ans);
	return 0;
}