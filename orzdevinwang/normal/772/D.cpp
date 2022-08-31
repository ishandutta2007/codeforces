#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int mod = 1e9 + 7;
const int N = 1e6 + 7;
void fwt(int *f, int len) {
	for(int i = 10; i <= len; i *= 10) 
		for(int l = i / 10, j = 0; j < len; j += i)
			for(int k = j + 9 * l - 1; k >= j; k--)  
				(f[k] += f[k + l]) %= mod;
}
void ifwt(int *f, int len) {
	for(int i = 10; i <= len; i *= 10) 
		for(int l = i / 10, j = 0; j < len; j += i) 
			for(int k = j; k < j + 9 * l; k++) 
				(f[k] += mod - f[k + l]) %= mod;
}
int n, a[N], f[N], g[N], cnt[N], tpow[N]; 
ll ans;
int main() {
	scanf("%d", &n);
    L(i, 1, n) scanf("%d", &a[i]), cnt[a[i]]++, (f[a[i]] += a[i]) %= mod, (g[a[i]] += 1ll * a[i] * a[i] % mod) %= mod;
    tpow[0] = 1;
    L(i, 1, n) tpow[i] = 2 * tpow[i - 1] % mod;
    fwt(cnt, 1e6), fwt(f, 1e6), fwt(g, 1e6);
    L(i, 0, 999999) {
    	if(cnt[i] == 1) f[i] = g[i];
		else if(cnt[i] == 0) f[i] = 0;
		else f[i] = (1ll * f[i] * f[i] + g[i]) % mod * tpow[cnt[i] - 2] % mod;
	}
	ifwt(f, 1e6);
	L(i, 0, 999999) ans ^= 1ll * f[i] * i;
	printf("%lld\n", ans);
	return 0;
}