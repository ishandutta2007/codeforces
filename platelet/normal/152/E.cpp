#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define fi first
#define se second

using namespace std;
typedef pair <int, int> P;
int n, m, a[200], K, x[7], f[128][200], ans[200];
P g[128][200];
void dfs(int S, int i) {
	ans[i] = 1;
	if(!g[S][i].fi) return;
	if(g[S][i].se == i) dfs(S ^ g[S][i].fi, i);
	dfs(g[S][i].fi, g[S][i].se);
};
int main() {
	mem(f, 63);
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m >> K;
	For(i, 0, n * m) scanf("%d", &a[i]);
	int u, v;
	For(i, 0, K) {
		scanf("%d%d", &u, &v), x[i] = --u * m + --v;
		f[1 << i][x[i]] = a[x[i]];
	}
	For(S, 1, 1 << K) {
		priority_queue <P, vector <P>, greater <P>> q;
		For(i, 0, n * m) {
			for(int T = S; T; --T &= S) {
				int v = f[T][i] + f[S ^ T][i] - a[i];
				if(v < f[S][i]) f[S][i] = v, g[S][i] = {T, i};
			}
			if(f[S][i] < 0x3f3f3f3f) q.push({f[S][i], i});
		}
		while(!q.empty()) {
			int v = q.top().fi, i = q.top().se; q.pop();
			if(v > f[S][i]) continue;
			auto chk = [&](int dx, int dy) {
				dx += i / m, dy += i % m;
				if(~dx && ~dy && dx < n && dy < m) {
					int j = dx * m + dy, x = v + a[dx * m + dy];
					if(x < f[S][j]) f[S][j] = x, g[S][j] = {S, i}, q.push({f[S][j], j});
				}
			};
			chk(0, 1), chk(1, 0), chk(0, -1), chk(-1, 0);
		}
	}
	int all = (1 << K) - 1;
	cout << f[all][x[0]] << endl;
	dfs(all, x[0]);
	For(i, 0, n * m) {
		putchar(ans[i] ? 'X' : '.');
		if(i % m == m - 1) puts("");
	}
	return 0;
}