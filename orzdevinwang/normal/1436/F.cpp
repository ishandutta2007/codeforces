// You AK, wo bao ling. wo men de qian tu ... dou guang ming ! 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
const int MAXN = 1e5;
const int mod = 998244353;
const int inv2 = (mod + 1) / 2;
int n, m, jc[N], njc[N];
int qpow(int x, ll y) {
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
}
int ny(int x) { return qpow(x, mod - 2); }
int C(int x, int y) { return 1ll * jc[x] * njc[y] % mod * njc[x - y] % mod; }
int cnt[N], ans[N]; ll SZ[N];
void work(int x) {
	ll siz = 0; int sumf = 0, sum = 0;
	L(i, 1, MAXN / x) 
		siz += SZ[i * x], 
		(sum += 1ll * cnt[i * x] * (i * x) % mod) %= mod, 
		(sumf += 1ll * cnt[i * x] * (i * x) % mod * (i * x) % mod) %= mod;

	int suma = 0, sumb = 0;

	if(siz > 1) suma = 1ll * siz % mod * qpow(2, siz - 2) % mod * inv2 % mod;
	// L(i, 0, siz - 2) (suma += C(siz - 2, i) * (i + 1) % mod) %= mod;

	(ans[x] += (1ll * sum * sum - sumf + mod) % mod * suma % mod) %= mod;

	// L(i, 0, siz - 1) (sumb += C(siz - 1, i) * i % mod) %= mod;
	if(siz) sumb = 1ll * (siz - 1) % mod * qpow(2, siz - 1) % mod * inv2 % mod;
	// if(siz % 2 == 0) 
	// else sumb = (1ll * (qpow(2, siz - 1) - C(siz -
	// 1, (siz - 1) / 2)) * (siz - 1) + 1ll * C(siz - 1, (siz - 1) / 2) * ((siz - 1) / 2) % mod) * inv2  % mod;

	(ans[x] += 1ll * sumf * sumb % mod) %= mod;
	
	L(i, 2, MAXN / x) (ans[x] += mod - ans[x * i]) %= mod;
}
int main() {
	scanf("%d", &n);
	jc[0] = njc[0] = 1;
	L(i, 1, MAXN) jc[i] = 1ll * jc[i - 1] * i % mod, njc[i] = ny(jc[i]);
	L(i, 1, n) {
		int x, y; scanf("%d%d", &x, &y);
		(cnt[x] += y) %= mod, SZ[x] += y;
	}
	R(i, MAXN, 1) work(i);
	printf("%d\n", ans[1]);
	return 0;
}