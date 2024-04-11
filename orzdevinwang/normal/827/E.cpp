#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = (1 << 20);
const db pi = acos(-1);
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar();
	return x * f;
}
struct CP {
	db x, y; 
	CP (db xx = 0, db yy = 0) {
		x = xx, y = yy;
	}
} ;
CP operator + (CP aa, CP bb) {
	return CP(aa.x + bb.x, aa.y + bb.y);
}
CP operator - (CP aa, CP bb) {
	return CP(aa.x - bb.x, aa.y - bb.y);
}
CP operator * (CP aa, CP bb) {
	return CP(aa.x * bb.x - aa.y * bb.y, aa.x * bb.y + aa.y * bb.x);
}
CP operator * (CP aa, db bb) {
	return CP(aa.x * bb, aa.y * bb);
}
int pp[N], lim, Lim;
CP Pow[N], iPow[N];
void up(int x) {
	for(lim = 1; lim <= x; lim <<= 1);
}
void revlim() {
	L(i, 0, lim - 1) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (lim >> 1)));
}
void init(int x) {
	up(x), Lim = lim;
	Pow[0] = iPow[0] = CP(1, 0);
	L(i, 1, Lim - 1) Pow[i] = iPow[Lim - i] = CP(cos(2 * pi / Lim * i), sin(2 * pi / Lim * i));
}
void FFT(CP *f, int flag) {
	L(i, 0, lim - 1) if(pp[i] < i) swap(f[pp[i]], f[i]);
	for(int i = 2; i <= lim; i <<= 1) 
		for(int j = 0, l = (i >> 1), ch = Lim / i; j < lim; j += i) {
			for(int k = j, now = 0; k < j + l; k++) {
				CP pa = f[k], pb = f[k + l] * (flag == 1 ? Pow[now] : iPow[now]);
				f[k] = pa + pb, f[k + l] = pa - pb, now += ch;
			}
		}
	if(flag == -1) L(i, 0, lim - 1) f[i].x /= lim, f[i].y /= lim;
}
int n, m, a[N], f[N], tot, g[N];
CP A[N], AA[N], AAA[N];
CP B[N], BB[N], BBB[N];
char s[N];
void Main() {
	n = read(), scanf("%s", s);
	up(n << 1), revlim();
	L(i, 0, lim - 1) A[i] = B[i] = AA[i] = BB[i] = AAA[i] = BBB[i] = CP(0, 0);
	L(i, 0, n - 1) {
		int o;
		if(s[i] == '?') o = 0;
		if(s[i] == 'V') o = 1;
		if(s[i] == 'K') o = 2;
		B[n - 1 - i].x = A[i].x = o;
		BB[n - 1 - i].x = AA[i].x = o * o;
		BBB[n - 1 - i].x = AAA[i].x = o * o * o;;
	}
	FFT(A, 1), FFT(AA, 1), FFT(AAA, 1);
	FFT(B, 1), FFT(BB, 1), FFT(BBB, 1);
	L(i, 0, lim - 1) A[i] = A[i] * BBB[i] + AAA[i] * B[i] - AA[i] * BB[i] * 2;
	FFT(A, -1);
	L(i, 0, n - 1) f[i] = A[n - 1 - i].x;
	tot = 0;
	L(i, 1, n) {
		bool ok = 1;
		L(j, 1, (n - 1) / i) if(f[i * j]) ok = 0;
		if(ok) g[++tot] = i;
	}
	printf("%d\n", tot);
	L(i, 1, tot) printf("%d ", g[i]);
	puts("");
}
int main() {
	init(1e6);
	int T = read();
	while(T--) Main();
	return 0;
}