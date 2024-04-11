#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch= getchar();
	return x * f;
}
const int lim = (1 << 20);
const int mod = 490019;
const int phi = mod - 1;
const db pi = acos(-1);
int qpow(int x, int y = mod - 2, int p = mod) {
	int res = 1;
	for(; y; x = 1ll * x * x % p, y >>= 1) if(y & 1) res = 1ll * res * x % p;
	return res;
}
struct CP {
	db x, y;
	CP (db xx = 0, db yy = 0) { x = xx, y = yy; }
};
CP operator + (CP aa, CP bb) { return CP(aa.x + bb.x, aa.y + bb.y); }
CP operator - (CP aa, CP bb) { return CP(aa.x - bb.x, aa.y - bb.y); }
CP operator * (CP aa, CP bb) { return CP(aa.x * bb.x - aa.y * bb.y, aa.x * bb.y + aa.y * bb.x); }
int pp[lim];
void NTT(CP *f, int flag) {
	L(i, 0, lim - 1) if(pp[i] < i) swap(f[i], f[pp[i]]);
	for(int i = 2; i <= lim; i <<= 1) {
		CP ch(cos(2 * pi / i), flag * sin(2 * pi / i));
		for(int j = 0, l = (i >> 1); j < lim; j += i) {
			CP now(1, 0);
			for(int k = j; k < j + l; k ++) {
				CP pa = f[k], pb = f[k + l] * now;
				f[k] = pa + pb, f[k + l] = pa - pb, now = now * ch;
			}
		}
	}
	if(flag == -1) L(i, 0, lim - 1) f[i].x /= lim, f[i].y /= lim; 
}
CP Aa[lim], Ab[lim], Ba[lim], Bb[lim], Sa[lim], Sb[lim], Sc[lim];
int n, m, c, f[lim], pA[lim], pB[lim], ans[lim], Pow[lim], iPow[lim], ic, Ans;
int main() {
	n = read(), m = read(), c = read();
	ic = qpow(c), Pow[0] = iPow[0] = 1;
	L(i, 1, phi) Pow[i] = 1ll * Pow[i - 1] * c % mod, iPow[i] = 1ll * iPow[i - 1] * ic % mod;
	L(i, 0, n - 1) (pA[(ll)i * i % phi] += read()) %= mod;
	L(i, 0, m - 1) (pB[(ll)i * i % phi * i % phi] += read()) %= mod;

	L(i, 0, lim - 1) pA[i] = 1ll * pA[i] * iPow[(ll)i * (i - 1) / 2 % phi] % mod;
	L(i, 0, lim - 1) pB[i] = 1ll * pB[i] * iPow[(ll)i * (i - 1) / 2 % phi] % mod;
	
	L(i, 0, lim - 1) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (lim >> 1)));

	L(i, 0, lim - 1) Aa[i].x = (pA[i] & 1023), Ab[i].x = (pA[i] >> 10), Ba[i].x = (pB[i] & 1023), Bb[i].x = (pB[i] >> 10);
	NTT(Aa, 1), NTT(Ab, 1), NTT(Ba, 1), NTT(Bb, 1);
	L(i, 0, lim - 1) Sa[i] = Aa[i] * Ba[i], Sb[i] = Aa[i] * Bb[i] + Ab[i] * Ba[i], Sc[i] = Ab[i] * Bb[i];
	NTT(Sa, -1), NTT(Sb, -1), NTT(Sc, -1);
	
	L(i, 0, lim - 1) ans[i] = (ll)(Sa[i].x + 0.49) % mod + (ll)(Sb[i].x + 0.49) % mod * 1024 % mod + (ll)(Sc[i].x + 0.49) % mod * 1048576 % mod;
	L(i, 0, lim - 1) (Ans += 1ll * ans[i] * Pow[(ll)i * (i - 1) / 2 % phi] % mod) %= mod;
	printf("%d\n", Ans);
	return 0;
}