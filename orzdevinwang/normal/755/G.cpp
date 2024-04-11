#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define y second
#define x first
using namespace std;
char obuf[1 << 20], *O = obuf;
void print(int x) {
    if(x > 9) print(x / 10);
    *O++ = x % 10 + '0';
}
const int N = 65536;
const int mod = 998244353;
const int G = 3;
const int iG = 332748118;
int n, lim, nlim, pp[N], Pow1[N + 1], Pow2[N + 1];
void AD(int &x, int y) { x += y; if(x >= mod) x -= mod; }
int ad(int x, int y) { x += y; if(x >= mod) return x - mod; return x; }
int qpow(int x, int y) {
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
}
int ny(int x) { return qpow(x, mod - 2); }
void swap(int &x, int &y) { x ^= y ^= x ^= y; }
void fft(int *f, int flag) {
	L(i, 0, lim - 1) if(pp[i] < i) swap(f[i], f[pp[i]]);
	for(int i = 2; i <= lim; i <<= 1) {
		int ch = lim / i;
		for(int l = (i >> 1), j = 0; j < lim; j += i) {
			int now = 0;
			for(int k = j; k < j + l; k++) {
				int pa = f[k], pb = 1ll * f[k + l] * (flag == 1 ? Pow1[now] : Pow2[now]) % mod;
				f[k] = ad(pa, pb), f[k + l] = ad(pa, mod - pb);
				now += ch;
			}
		}
	}
	if(flag == -1) L(i, 0, lim - 1) f[i] = 1ll * f[i] * nlim % mod; 
}
int _f[N], _g[N];
void Mul(int *f, int *g, int *ans) {
	fill(_f, _f + lim, 0), fill(_g, _g + lim, 0);
	L(i, 0, n) _f[i] = f[i], _g[i] = g[i], ans[i] = 0;
	fft(_f, 1), fft(_g, 1);
	L(i, 0, lim - 1) _f[i] = 1ll * _f[i] * _g[i] % mod;
	fft(_f, -1);
	L(i, 0, n) ans[i] = _f[i];
}
int m, f[31][3][N], sp[N], ans[2][2][N];
int main() {
	scanf("%d%d", &m, &n);
	for(lim = 1; lim <= n * 2 + 1; lim <<= 1);
	nlim = ny(lim);
	Pow1[0] = Pow2[0] = 1;
	int P1 = qpow(G, (mod - 1) / lim), P2 = qpow(iG, (mod - 1) / lim);
	L(i, 1, lim) Pow1[i] = 1ll * Pow1[i - 1] * P1 % mod, Pow2[i] = 1ll * Pow2[i - 1] * P2 % mod;
	L(i, 0, lim - 1) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (lim >> 1)));
	f[0][0][0] = f[0][0][1] = f[0][1][0] = 1;
	f[1][0][0] = 1, f[1][0][1] = 3,f[1][0][2] = 1;
	f[1][1][0] = f[1][1][1] = 1;
	f[1][2][0] = 1;
	L(i, 2, 29) {
		Mul(f[i - 1][0], f[i - 1][0], f[i][0]);
		Mul(f[i - 1][1], f[i - 1][1], sp);
		L(j, 1, n) AD(f[i][0][j], sp[j - 1]);
 
		Mul(f[i - 1][1], f[i - 1][0], f[i][1]);
		Mul(f[i - 1][2], f[i - 1][1], sp);
		L(j, 1, n) AD(f[i][1][j], sp[j - 1]);
 
		Mul(f[i - 1][1], f[i - 1][1], f[i][2]);
		Mul(f[i - 1][2], f[i - 1][2], sp);
		L(j, 1, n) AD(f[i][2][j], sp[j - 1]);
	}
	int now = 0, pp = log2(m);
	L(i, 0, n) ans[now][0][i] = f[pp][0][i], ans[now][1][i] = f[pp][1][i];
	m -= (1 << pp);
	R(i, 29, 0) if(m & (1 << i)) {
		now ^= 1;
		Mul(ans[now ^ 1][0], f[i][0], ans[now][0]);
		Mul(ans[now ^ 1][1], f[i][1], sp);
		L(j, 1, n) AD(ans[now][0][j], sp[j - 1]);
 
		Mul(ans[now ^ 1][0], f[i][1], ans[now][1]);
		Mul(ans[now ^ 1][1], f[i][2], sp);
		L(j, 1, n) AD(ans[now][1][j], sp[j - 1]);
	}
	L(i, 1, n) print(ans[now][0][i]), *O++ = ' '; 
	*O ++ = '\n';
	fwrite(obuf,O-obuf,1,stdout);
	return 0;
}