#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
const int mod = 998244353;
int qpow(int x, int y = mod - 2, int p = mod) {
	int res = 1;
	for(; y; x = 1ll * x * x % p, y >>= 1) if(y & 1) res = 1ll * res * x % p;
	return res;
}
int n, f[N], jc[N], njc[N], ans;
void Main() {
	scanf("%d", &n);
	jc[0] = njc[0] = 1; L(i, 1, n) jc[i] = 1ll * jc[i - 1] * i % mod, njc[i] = qpow(jc[i]);
	L(i, 2, n) f[i] = 1ll * jc[n] * njc[i - 1] % mod;
	L(i, 2, n) (f[i] += mod - f[i + 1]) %= mod;
	ans ++, (f[n] += mod - 1 ) %= mod;
	L(i, 2, n) {
		(ans += 1ll * (n - i + 1) * f[i] % mod) %= mod;
	}
	printf("%d\n", ans);
}
int main() {
	Main();
	return 0;
}