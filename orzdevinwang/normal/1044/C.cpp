#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 3e5 + 7;
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return x * f; 
}
int n, x[N], y[N], xmx, xmn, ymx, ymn;
int f[5][5][5];
void Max(int &x, int y) {
	if(x < y) x = y;
}
int main() {
	xmn = ymn = 1e9;
	xmx = ymx = -1e9;
	n = read();
	memset(f, -0x3f, sizeof(f));
	f[0][0][0] = 0;
	L(i, 1, n) {
		x[i] = read(), y[i] = read();
		xmx = max(xmx, x[i]);
		xmn = min(xmn, x[i]);
		ymx = max(ymx, y[i]);
		ymn = min(ymn, y[i]);

		R(cnt, 3, 1) L(a, 0, 3) L(b, 0, 3) {
			if(a & 2) Max(f[cnt][a][b], f[cnt - 1][a ^ 2][b] + x[i]);
			if(a & 1) Max(f[cnt][a][b], f[cnt - 1][a ^ 1][b] - x[i]);
			if(b & 2) Max(f[cnt][a][b], f[cnt - 1][a][b ^ 2] + y[i]);
			if(b & 1) Max(f[cnt][a][b], f[cnt - 1][a][b ^ 1] - y[i]);
			if((a & 2) && (b & 2)) Max(f[cnt][a][b], f[cnt - 1][a ^ 2][b ^ 2] + x[i] + y[i]);
			if((a & 2) && (b & 1)) Max(f[cnt][a][b], f[cnt - 1][a ^ 2][b ^ 1] + x[i] - y[i]);
			if((a & 1) && (b & 2)) Max(f[cnt][a][b], f[cnt - 1][a ^ 1][b ^ 2] - x[i] + y[i]);
			if((a & 1) && (b & 1)) Max(f[cnt][a][b], f[cnt - 1][a ^ 1][b ^ 1] - x[i] - y[i]);
		}
	}
	printf("%d ", max(f[2][3][3], f[3][3][3]) * 2);
	L(i, 4, n) printf("%d ", 2 * (xmx - xmn + ymx - ymn));
	puts("");
	return 0;
}