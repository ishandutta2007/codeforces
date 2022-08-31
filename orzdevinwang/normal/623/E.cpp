// You AK, wo bao ling. wo men de qian tu ... dou guang ming !
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db long double
#define pii pair<int, int>
#define mkp make_pair
#define uint unsigned int
using namespace std;
const int N = 30009;
const int M = (1 << 16);
const int mod = 1e9 + 7;
struct CP {
	db x, y;
	CP (db xx = 0, db yy = 0) {
		x = xx, y = yy;
	}
};
CP operator + (CP aa, CP bb) {
	return CP(aa.x + bb.x, aa.y + bb.y);
}
CP operator - (CP aa, CP bb) {
	return CP(aa.x - bb.x, aa.y - bb.y);
}
CP operator * (CP aa, CP bb) {
	return CP(aa.x * bb.x - aa.y * bb.y, aa.x * bb.y + aa.y * bb.x);
}
const db pi = acos(-1);
int pp[M + 10];
void fft(CP *f, int len, int flag) {
	for(int i = 0; i < len; i ++) if(pp[i] < i) swap(f[pp[i]], f[i]);
	for(int i = 2; i <= len; i <<= 1) {
		CP ch(cos(pi * 2 / i), flag * sin(pi * 2 / i));
		for(int l = (i >> 1), j = 0; j < len; j += i) {
			CP now(1, 0);
			for(int k = j; k < j + l; k ++) {
				CP ga = f[k], gb = f[k + l] * now;
				f[k] = ga + gb, f[k + l] = ga - gb, now = now * ch;
			}
		}
	}
	if(flag == -1) for(int i = 0; i < len; i++) f[i].x /= len;
}
CP fa[M + 10], fb[M + 10], ga[M + 10], gb[M + 10], G1[M + 10], G2[M + 10], G3[M + 10];
void MTT(int *f, int *g, int *ans, int n) {
	int lim = 1;
	for(; lim <= n * 2 + 1; lim <<= 1);
	for(int i = 0; i < lim; i++) fa[i].x = fb[i].x = ga[i].x = gb[i].x = fa[i].y = ga[i].y = fb[i].y = gb[i].y = 0;
	L(i, 0, n) fa[i].x = (f[i] & 32767), fb[i].x = (f[i] >> 15), ga[i].x = (g[i] & 32767), gb[i].x = (g[i] >> 15);
	for(int i = 0; i < lim; i++) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (lim >> 1)));
	fft(fa, lim, 1), fft(fb, lim, 1), fft(ga, lim, 1), fft(gb, lim, 1);
	for(int i = 0; i < lim; i++) G1[i] = fa[i] * ga[i], G2[i] = fa[i] * gb[i] + fb[i] * ga[i], G3[i] = fb[i] * gb[i];
	fft(G1, lim, -1), fft(G2, lim, -1), fft(G3, lim, -1);
	L(i, 0, n) 
		ans[i] = ((ll)(G1[i].x + 0.49) % mod + (((ll)(G2[i].x + 0.49) % mod) << 15) % mod + (((ll)(G3[i].x + 0.49) % mod) << 30) % mod) % mod;
}
int qpow(int x, ll y) {
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
}
int ny(int x) { return qpow(x, mod - 2); }
int n, m, jc[N], njc[N], Pow[N];
int C(int x, int y) { return 1ll * jc[x] * njc[y] % mod * njc[x - y] % mod; }
int dp[20][N], ans[N], sav[N], f[N], g[N];
int main() {
	ll nnn; scanf("%lld%d", &nnn, &m);
	if(nnn > m) return printf("0\n"), 0;
	n = nnn;
	jc[0] = njc[0] = Pow[0] = 1;
	L(i, 1, m) jc[i] = 1ll * jc[i - 1] * i % mod, njc[i] = ny(jc[i]), Pow[i] = 2ll * Pow[i - 1] % mod;
	L(i, 1, m) dp[0][i] = 1;
	L(i, 1, 15) {
		L(j, 0, m) f[j] = 1ll * dp[i - 1][j] * njc[j] % mod * qpow(Pow[j], 1 << (i - 1)) % mod;
		L(j, 0, m) g[j] = 1ll * dp[i - 1][j] * njc[j] % mod;
		MTT(f, g, dp[i], m);
		L(j, 0, m) dp[i][j] = 1ll * dp[i][j] * jc[j] % mod;
	}
	ans[0] = 1;
	int now = 0;
	L(i, 0, 15) if(n & (1 << i)) {
		L(j, 0, m) f[j] = 1ll * dp[i][j] * njc[j] % mod * qpow(Pow[j], now) % mod;
		L(j, 0, m) g[j] = 1ll * ans[j] * njc[j] % mod;
		MTT(f, g, ans, m);
		L(j, 0, m) ans[j] = 1ll * ans[j] * jc[j] % mod;
		now |= (1 << i);
	}
	int sum = 0;
	L(i, 0, m) (sum += 1ll * ans[i] * C(m, i) % mod) %= mod;
	printf("%d\n", sum);
	return 0;
}