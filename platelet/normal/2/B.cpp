#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 1005, MI = 1e6;
int read() {
	static streambuf* in = cin.rdbuf();
	#define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, MI), p1 == p2) ? -1 : *p1++)
	static char buf[MI], *p1, *p2;
	int c = gc, r = 0;
	while(c < 48) c = gc;
	while(c > 47) r = (r << 3) + (r << 1) + (c & 15), c = gc;
	return r;
}
int n, fx, a[2][N][N], f[2][N][N]; char d[2][N][N];
void get(int& x, int d, int v) { while(v % d == 0) x++, v /= d; }
void dp(int f[][N], int a[][N], char d[][N]) {
	per(i, n, 1) per(j, n, 1) if(!~a[i][j]) f[i][j] = 0x3f3f3f3f;
	else if(j == n || (i < n && f[i+1][j] < f[i][j+1]))
		f[i][j] = f[i+1][j] + a[i][j], d[i][j] = 'D';
	else f[i][j] = f[i][j+1] + a[i][j], d[i][j] = 'R';
}
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0), cin.tie(0);
	n = read();
	rep(i, 1, n) rep(j, 1, n) {
		int t = read();
		if(!t) fx = i, a[0][i][j] = a[1][i][j] = -1;
		else get(a[0][i][j], 2, t), get(a[1][i][j], 5, t);
	}
	dp(f[0], a[0], d[0]), dp(f[1], a[1], d[1]);
	int ans = f[0][1][1] > f[1][1][1], i = 1, j = 1;
	if(fx && f[ans][1][1]) {
		puts("1");
		rep(i, 2, fx) putchar('D');
		rep(i, 2, n) putchar('R');
		rep(i, fx + 1, n) putchar('D');
	} else {
		printf("%d\n", f[ans][1][1]);
		while(i < n || j < n) {
			putchar(d[ans][i][j]);
			if(d[ans][i][j] == 'D') i++; else j++;
		}
	}
	return 0;
}