#include<bits/stdc++.h>

#define mod 998244353
#define G 3
#define iG 332748118
#define N 2097200

using namespace std;
int n, fn, m, pp[N], ts, g[N], s[N], ss[N], cnt;
int qpow(int x, int y) {
	int res = 1;
	while(y) {
		if(y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod, y >>= 1;
	}
	return res;
}
void fft(int *f, int len, int flag) {
	for(int i = 0; i < len; i++) if(i > pp[i]) swap(f[i], f[pp[i]]);
	for(int i = 2; i <= len; i <<= 1) {
		int FL = (i >> 1);
		for(int j = 0; j < len; j += i) {
			int ch = qpow((flag == 1 ? G : iG), (mod - 1) / i), now = 1;
			for(int k = j; k < j + FL; k++) {
				int pa = f[k], pb = f[k + FL];
				f[k] = (pa + 1ll * pb * now % mod) % mod;
				f[k+FL] = (pa - 1ll * pb * now % mod + mod) % mod;
				now = 1ll * now * ch % mod;
			}
		}
	}
	if(flag == -1) {
		int ny = qpow(len, mod - 2);
		for(int i = 0; i < len; i++) f[i] = 1ll * ny * f[i] % mod;
	}
}
int main() {
	scanf("%d%d",&n,&m), s[0] = 1;
	for(int i = 1; i <= n; i++) scanf("%d",&g[i]), s[g[i]] = 1, ss[g[i]] = 1;
	for(fn = 1; fn <= 2 * m + 1; fn <<= 1);
	for(int i = 0; i < fn; i++) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (fn >> 1)));
	fft(s, fn, 1);
	for(int i = 0; i < fn; i++) s[i] = 1ll * s[i] * s[i] % mod;
	fft(s, fn, -1);
	for(int i = 1; i <= m; i++) {
		if(s[i] && !ss[i]) {
			printf("NO\n");
			return 0;
		}
		cnt += (s[i] == 2);
	}
	printf("YES\n%d\n", cnt);
	for(int i = 1; i <= m; i++) if(s[i] == 2) printf("%d ", i);
	puts("");
	return 0;
}