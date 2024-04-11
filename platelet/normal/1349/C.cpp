#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define repxy for(int op = 0, x, y; op < 4; op++) if((x = i + nxt[op][0]) && (y = j + nxt[op][1]) && x <= n && y <= m)

using namespace std;
const int N = 1005, nxt[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n, m, t, a[N][N], qx[N*N], qy[N*N], l = 1, r, c[N][N];
int u, v; long long w;
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	mem(c, -1);
	cin >> n >> m >> t;
	rep(i, 1, n) rep(j, 1, m) scanf("%1d", &a[i][j]);
	rep(i, 1, n) rep(j, 1, m) repxy if(a[x][y] == a[i][j]) { r++, c[qx[r] = i][qy[r] = j] = 0; break; }
	while(l <= r) {
		int i = qx[l], j = qy[l++];
		repxy if(!~c[x][y]) r++, c[qx[r] = x][qy[r] = y] = c[i][j] + 1;
	}
	while(t--) {
		scanf("%d%d%lld", &u, &v, &w);
		printf("%d\n", a[u][v] ^ (~c[u][v] && (max(w - c[u][v], 0LL) & 1)));
	}
	return 0;
}