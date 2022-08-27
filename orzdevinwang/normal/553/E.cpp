#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mkp make_pair 
const int N = 66666;
const int M = 55;
const int sM = 105;
const int inf = 1e9 + 7;
const db pi = acos(-1);
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch= getchar();
	return x * f;
}
int lim, pp[N];
struct CP {
	db x, y;
	CP (db xx = 0, db yy = 0) {
		x = xx, y = yy;
	}
};
CP operator + (CP aa, CP bb) { return CP(aa.x + bb.x, aa.y + bb.y); }
CP operator - (CP aa, CP bb) { return CP(aa.x - bb.x, aa.y - bb.y); }
CP operator * (CP aa, CP bb) { return CP(aa.x * bb.x - aa.y * bb.y, aa.x * bb.y + aa.y * bb.x); }
void FFT(CP *f, int flag) {
	L(i, 0, lim - 1) if(i < pp[i]) swap(f[i], f[pp[i]]);
	for(int i = 2; i <= lim; i <<= 1) {
		CP ch(cos(2 * pi / i), flag * sin(2 * pi / i));
		for(int l = (i >> 1), j = 0; j < lim; j += i) {
			CP now(1, 0);
			for(int k = j; k < j + l; k ++) {
				CP pa = f[k], pb = now * f[k + l];
				f[k] = pa + pb, f[k + l] = pa - pb, now = now * ch;
			}
		}
	}
	if(flag == -1) L(i, 0, lim - 1) f[i].x /= lim, f[i].y /= lim;
}
CP A[N], B[N];
int n, m, t, x, dis[N];
int fu[N], fv[N], fval[N];
db ans[M][N], p[sM][N], calc[sM][N];
void Solve(int l, int mid, int r) {
	L(d, 1, m) {
		int tota = -1, totb = 0; B[0] = CP(0, 0);
		L(i, l, mid) A[++tota] = CP(ans[fv[d]][i], 0); 
		L(i, 1, min(r - l + 1, t)) B[++totb] = CP(p[d][i], 0);
		for(lim = 1; lim <= tota + totb; lim <<= 1) ; 
		L(i, 0, lim - 1) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (lim >> 1)));
		L(i, tota + 1, lim - 1) A[i] = CP(0, 0); 
		L(i, totb + 1, lim - 1) B[i] = CP(0, 0);
		FFT(A, 1), FFT(B, 1);
		L(i, 0, lim - 1) A[i] = A[i] * B[i];
		FFT(A, -1);
		L(i, 1, r - mid) calc[d][i + mid] += A[i + tota].x;
		// L(i, l, mid) L(j, 1, t) if(i + j <= r && i + j > mid) calc[d][i + j] += p[d][j] * ans[fv[d]][i];
	}
}
void Divide(int l, int r) {
	if(l == r) {
		L(j, 1, m) ans[fu[j]][l] = min(ans[fu[j]][l], calc[j][l] + fval[j]);
		return;
	}
	int mid = (l + r) / 2;
	Divide(l, mid);
	Solve(l, mid, r);
	Divide(mid + 1, r);
}
int main() {
	n = read(), m = read(), t = read(), x = read();
	dis[n] = 0; L(i, 1, n - 1) dis[i] = inf; 
	L(i, 1, n - 1) L(j, t, t * 2) ans[i][j] = inf;
	L(i, 1, m) {
		fu[i] = read(), fv[i] = read(), fval[i] = read();
		L(j, 1, t) p[i][j] = 1. * read() / 100000;
	}
	L(i, 1, n) L(j, 1, m) dis[fu[j]] = min(dis[fu[j]], dis[fv[j]] + fval[j]);
	L(i, 1, n) L(j, 0, t - 1) ans[i][j] = dis[i] + x;
	Solve(0, t - 1, t * 2);
	Divide(t, t * 2);
	// L(i, t, 2 * t) {
	// 	L(j, 1, m) {
	// 		db sum = 0;
	// 		L(k, i - t, i - 1) sum += ans[fv[j]][k] * p[j][i - k];
	// 		ans[fu[j]][i] = min(ans[fu[j]][i], sum + fval[j]);
	// 	}
	// }
	printf("%.10lf\n", ans[1][2 * t]);
	return 0;
}