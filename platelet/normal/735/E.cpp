#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 105, P = 1e9 + 7;
int n, K; long long f[N][25][25], g[25][25], ans;
vector <int> G[N];
int calc(int i, int j, int k, int s) {
	int res = -1;
	if(s < K && i + s + 1 > K) res = max(res, s + 1);
	if(k < K && j + k + 1 > K) res = max(res, k);
	return ~res ? res < K ? res : -1 : K;
}
void dfs(int u, int fa) {
	f[u][0][K] = f[u][K][0] = 1;
	for(int v : G[u]) if(v ^ fa) {
		dfs(v, u), mem(g, 0);
		rep(i, 0, K) rep(j, 0, K) rep(k, 0, K) rep(s, 0, K) if(~calc(i, j, k, s))
			(g[min(min(i, j + 1), n)][calc(i, j, k, s)] += f[u][i][k] * f[v][j][s]) %= P;
		rep(i, 0, K) rep(j, 0, K) f[u][i][j] = g[i][j];
	}
}
int main() {
	cin >> n >> K;
	if(!K) puts("1"), exit(0);
	int u, v;
	rep(i, 2, n) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
	}
	dfs(1, 0);
	rep(i, 0, K) (ans += f[1][i][K]) %= P;
	cout << ans;
	return 0;
}