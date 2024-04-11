#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mkp make_pair 
const int N = 6e5 + 7;
const db pi = acos(-1);
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
int n, m, k, s[N];
ll ans[N];
int f[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	L(i, 1, n) cin >> s[i];
	int cnt = 0;
	L(i, 1, n) {
		A[n - cnt].x += 1;
		cnt += (s[i] < k);
		B[cnt].x += 1;
	}
	lim = 1; for(; lim <= n * 2; lim <<= 1) ;
	
	L(i, 0, lim - 1) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (lim >> 1)));
	FFT(A, 1), FFT(B, 1);
	L(i, 0, lim - 1) A[i] = A[i] * B[i];
	FFT(A, -1);

	L(i, 1, n) ans[i] = (ll)(A[i + n].x + 0.499);
	int nowlen = 0;
	L(i, 1, n) {
		if(s[i] < k) {
			nowlen = 0;
			continue;
		}
		nowlen ++;
		ans[0] += nowlen;
	}
	L(i, 0, n) cout << ans[i] << " ";
	cout << endl;
	return 0;
}