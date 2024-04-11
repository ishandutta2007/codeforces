#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define George1123AKIOI 1
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 505;
const int inf = 1e9;
int n, fn, m, mat[N], las[N];
int e[N][N], lx[N], rx[N], slack[N];
bool visr[N];
void bfs(int x) {
	fill(visr + 1, visr + fn + 1, 0);
	fill(las + 1, las + fn + 1, 0);
	fill(slack + 1, slack + fn + 1, inf);
	int pp = 0, wz = 0;
	mat[pp] = x;
	while(George1123AKIOI) {
		int d = inf, now = mat[pp];
		visr[pp] = 1;
		L(i, 1, fn) if(!visr[i]) {
			if(lx[now] + rx[i] - e[now][i] < slack[i]) slack[i] = lx[now] + rx[i] - e[now][i], las[i] = pp;
			if(d > slack[i]) d = slack[i], wz = i;
		}
		L(i, 0, fn) {
			if(visr[i]) lx[mat[i]] -= d, rx[i] += d;
			else slack[i] -= d;
		}
		pp = wz;
		if(!mat[pp]) break;
	}
	while(pp) mat[pp] = mat[las[pp]], pp = las[pp];
}
int KM() {
	L(i, 1, fn) {
		lx[i] = rx[i] = -1e5;
		L(j, 1, fn) lx[i] = max(lx[i], e[i][j]), rx[i] = max(rx[i], e[j][i]);
	}
	L(i, 1, fn) bfs(i);
	int res = 0;
	L(i, 1, fn) res += e[mat[i]][i];
	return res;
}
int two_cnt(int x) { return x == 0 ? 0 : two_cnt(x >> 1) + (x & 1); }
int f[N], col[N];
int main() {
	scanf("%d%d", &n, &m);
	fn = n + m;
	L(i, 1, n) scanf("%d", &f[i]);
	L(i, 1, fn) L(j, 1, fn) e[i][j] = -1e5;
	L(i, 1, n) L(j, i + 1, n) {
		if(f[i] == f[j]) e[i][j] = 0;
		else e[i][j] = -two_cnt(f[j]);
	}
	L(i, n + 1, fn) L(j, 1, n) e[i][j] = -two_cnt(f[j]);
	L(i, 1, fn) L(j, n + 1, fn) e[i][j] = 0;
	int res = -KM(), cnt = n;
	L(i, 1, n) if(f[i] ^ f[mat[i]]) cnt++;
	printf("%d %d\n", cnt, res);
	L(i, 1, n) {
		if(mat[i] > n) col[i] = mat[i] - n;
		else col[i] = col[mat[i]];
		if(f[i] != f[mat[i]]) putchar(col[i] + 'a' - 1), printf("=%d\n", f[i]);
		printf("print("), putchar(col[i] + 'a' - 1), printf(")\n");
	}
	return 0;
}