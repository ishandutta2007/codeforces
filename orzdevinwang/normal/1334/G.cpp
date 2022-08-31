#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db long double
#define pii pair<int, int>
#define mkp make_pair
#define sz(x) ((int) x.size())
#define be(x) x.begin()
#define en(x) x.end()
using namespace std;
const int N = 1 << 18;
const db pi = acos(-1);
struct CP {
	db x, y; 
	CP (db xx = 0, db yy = 0) {
		x = xx, y = yy;
	}
	inline CP rev() {
		return CP(x, -y);
	}
} ;
inline CP operator + (CP aa, CP bb) {
	return CP(aa.x + bb.x, aa.y + bb.y);
}
inline CP operator - (CP aa, CP bb) {
	return CP(aa.x - bb.x, aa.y - bb.y);
}
inline CP operator * (CP aa, CP bb) {
	return CP(aa.x * bb.x - aa.y * bb.y, aa.x * bb.y + aa.y * bb.x);
}
CP Pow[N], iPow[N];
int lim, rev[N];
void revlim() {
	L(i, 0, lim - 1) rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) * (lim >> 1)));
}
void up(int x) {
	for(lim = 1; lim <= x; lim <<= 1) ;
}
void FFT(CP *f, int flag = 1) {
	L(i, 0, lim - 1) if(rev[i] < i) swap(f[rev[i]], f[i]);
	for(int i = 2; i <= lim; i <<= 1) {
		for(int j = 0, l = (i >> 1), ch = lim / i; j < lim; j += i) {
			for(int k = j, now = 0; k < j + l; k++) {
				CP pa = f[k], pb = f[k + l] * (flag == 1 ? Pow[now] : iPow[now]);
				f[k] = pa + pb, f[k + l] = pa - pb, now += ch;
			}
		}
	}
	if(flag == -1) L(i, 0, lim - 1) f[i].x /= lim, f[i].y /= lim;
}
int n, m, S[N], T[N], P[N];
ll ppss[N], ssss[N], tttt[N], ans[N];
char SS[N], TT[N];
CP t[N], tt[N], ttt[N];
CP s[N], ss[N];
CP pp[N], pps[N], p[N], pss[N], ps[N], f[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	L(i, 1, 26) cin >> P[i];
	cin >> SS >> TT, n = strlen(SS), m = strlen(TT);
	L(i, 0, n - 1) S[i] = SS[i] - 'a' + 1;
	L(i, 0, m - 1) T[i] = TT[i] - 'a' + 1;
	reverse(S, S + n);
	up(m), revlim();
	L(i, 0, lim - 1) Pow[i] = CP(cos(pi * 2 / lim * i), sin(pi * 2 / lim * i)), iPow[i] = Pow[i].rev();
	L(i, 0, n - 1) {
		s[i] = S[i], ss[i] = s[i] * s[i];
		p[i] = P[S[i]], pp[i] = p[i] * p[i];
		pps[i] = pp[i] * s[i], pss[i] = p[i] * ss[i];
		ps[i] = p[i] * s[i], ppss[i] = (int)(pp[i].x * ss[i].x + 0.49);
	}
	L(i, 0, m - 1) t[i] = T[i], tt[i] = t[i] * t[i], ttt[i] = tt[i] * t[i], tttt[i] = (int) (ttt[i].x * t[i].x + 0.49);
	L(i, 1, m - 1) tttt[i] += tttt[i - 1];
	L(i, 1, n - 1) ppss[i] += ppss[i - 1];
	FFT(s), FFT(ss), FFT(t), FFT(tt), FFT(ttt), FFT(pp), FFT(pps), FFT(p), FFT(pss), FFT(ps);
	L(i, 0, lim - 1) {
		f[i] = pp[i] * tt[i] - 2 * pps[i] * t[i] + ss[i] * tt[i] - 2 * s[i] * ttt[i] 
		- 2 * pss[i] * t[i] - 2 * p[i] * ttt[i] + 4 * ps[i] * tt[i];
	}
	FFT(f, -1);
	L(i, 0, m - n) {
		ans[i] = (ll) round(f[n + i - 1].x);
		ans[i] += ppss[n - 1], ans[i] += tttt[i + n - 1];
		if(i) ans[i] -= tttt[i - 1];
	}
	cout << "\n";
	L(i, 0, m - n) cout << ! ans[i];
	cout << endl;
	return 0;
}