#include<bits/stdc++.h>

#define N 524300
#define mod 998244353
#define G 3
#define iG 332748118
#define re register

using namespace std;
int n, m, k, l, h[N], g[N], pp[N], sum[N], maxtot, Ans;
char a[N], b[N];
int qpow(int x, int y) {
	int res = 1;
	while(y) {
		if(y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod, y >>= 1;
	}
	return res;
}
void fft(int *f, int len, int flag) {
	for(re int i = 0; i < len; i++) if(pp[i] > i) swap(f[i], f[pp[i]]);
	for(re int i = 2; i <= len; i <<= 1) {
		int FL = (i >> 1);
		int ch = qpow(flag == 1  ? G : iG, (mod - 1) / i);
		for(re int j = 0; j < len; j += i) {
			int now = 1;
			for(re int k = j; k < j + FL; k++) {
				int fa = f[k], fb = f[k + FL];
				f[k] = (fa + 1ll * fb * now % mod) % mod;
				f[k + FL] = (fa - 1ll * fb * now % mod + mod) % mod;
				now = 1ll * now * ch % mod;
			}
		}
	}
	if(flag == -1) {
		int nylen = qpow(len, mod - 2);
		for(re int i = 0; i < len; i++) f[i] = 1ll * f[i] * nylen % mod;
	}
}
void getans(char ch) {
	// cout << ch << endl;
	maxtot = -1;
	for(re int i = 0; i < l; i++) {
		h[i] = 0;
		if(i < n) 
			if(a[i] == ch) {
				if(i >= k) h[i - k] = 1;
				else maxtot = i + k;
			}
	}
	for(re int i = 0; i < l; i++) g[i] = (i < m ? b[i] == ch : 0);
	for(re int i = 0; i < n; i++) maxtot = (h[i] ? i + 2 * k : maxtot), h[i] = (maxtot >= i);
	// for(int i = 0; i < l; i++) cout << g[i];
	// cout << endl;
	fft(h, l, 1), fft(g, l, 1);
	for(re int i = 0; i < l; i++) h[i] = 1ll * h[i] * g[i] % mod;
	fft(h, l, -1);
	for(re int i = 0; i < l; i++) sum[i] += h[i];
	// cout << endl;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s%s", a, b);
	for(re int i = 0; i <= (m - 1) / 2; i++) swap(b[i], b[m - i - 1]);
	for(l = 1; l <= n + m - 1; l <<= 1);
	for(re int i = 0; i < l; i++) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (l >> 1)));
	getans('A'), getans('G'), getans('C'), getans('T');
	for(re int i = 0; i < n; i++) Ans += (sum[i] == m);
	printf("%d\n", Ans);
	return 0;
}