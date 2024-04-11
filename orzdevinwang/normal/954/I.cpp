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
int lim, pp[N];
void revlim() {
	L(i, 0, lim - 1) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (lim >> 1)));
}
void up(int x) {
	for(lim = 1; lim <= x; lim <<= 1) ;
}
void FFT(CP *f, int flag) {
	L(i, 0, lim - 1) if(pp[i] < i) swap(f[pp[i]], f[i]);
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
int n, m, mod;
CP F[7][N], G[7][N], A[17][N];
int p[16][2] = {{}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {3, 4}, {3, 5}, {3, 6}, 
{4, 5}, {4, 6}, {5, 6}};
int f[N], g[N], ans[N];
int fa[N][7], now;
char s[N], t[N];
int find(int x) {
	return fa[now][x] == x ? x : fa[now][x] = find(fa[now][x]);
}
int main() {
	scanf("%s%s", s + 1, t + 1), n = strlen(s + 1), m = strlen(t + 1);
	reverse(t + 1, t + m + 1);
	L(i, 1, n) F[s[i] - 'a' + 1][i].x = 1;
	L(i, 1, m) G[t[i] - 'a' + 1][i].x = 1;
	up(n + 1), revlim();
	L(i, 0, lim - 1) Pow[i] = CP(cos(pi * 2 / lim * i), sin(pi * 2 / lim * i)), iPow[i] = Pow[i].rev();
	L(i, 1, 6) FFT(F[i], 1), FFT(G[i], 1);
	L(t, 1, 15) L(i, 0, lim - 1) A[t][i] = F[p[t][0]][i] * G[p[t][1]][i] + F[p[t][1]][i] * G[p[t][0]][i];
	L(i, 1, 15) FFT(A[i], -1);
	L(i, 1, n - m + 1) {
		now = i;
		L(j, 1, 6) fa[i][j] = j;
		L(j, 1, 15) if(find(p[j][0]) ^ find(p[j][1]) && (int) (A[j][i + m].x + 0.49)) ans[i] ++, fa[i][find(p[j][0])] = find(p[j][1]);
	} 
	L(i, 1, n - m + 1) printf("%d ", ans[i]);
	puts("");
	return 0;
}