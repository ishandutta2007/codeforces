#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 3005;
int T, n, r, c, fa[N*N*2], sz[N*N*2], stk[N*N*2], tp, vis[N][N*2];
int id(int x, int y) { return (x - 1) * c * 2 + y; }
int find(int x) { while(x ^ fa[x]) x = fa[x]; return x; }
int mrg(int a, int b) {
	if((a = find(a)) ^ (b = find(b))) {
		if(sz[a] > sz[b]) swap(a, b);
		fa[stk[++tp] = a] = b, sz[b] += sz[a];
		return 1;
	} return 0;
}
void undo() { int x = stk[tp--]; sz[fa[x]] -= sz[x], fa[x] = x; }
int main() {
	#ifdef local
		freopen(".in ", "r", stdin);
	#endif
	for(T = 1; T--;) {
		cin >> r >> c >> n;
		rep(i, 1, r * c * 2) fa[i] = i, sz[i] = 1;
		rep(i, 1, r) rep(j, 1, c * 2) vis[i][j] = 0;
		int ans = tp = 0;
		for(int x, y; n--;) {
			scanf("%d%d", &x, &y);
			int cnt = 0;
			rep(k, 0, 1) {
				rep(i, -1, 1) rep(j, -1, 1) {
					int xx = x + i, yy = y + j;
					if(!yy) yy = c * 2; if(yy > c * 2) yy = 1; 
					if(xx && xx <= r && yy && yy <= c * 2 && vis[xx][yy]) cnt += mrg(id(x, y), id(xx, yy));
				}
				vis[x][y] = 1, y += c;
			}
			if(find(id(x, y - c)) == find(id(x, y - c * 2))) for(vis[x][y-c] = vis[x][y-c*2] = 0; cnt--; undo()); else ans++;
		}
		cout << ans << endl;
	}
	return 0;
}