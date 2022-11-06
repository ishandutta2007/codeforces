#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int N, M, S, B, K, H, mat, ma[2005], d[2005], Xs[1005], Xb[1005], A[1005], F[1005], D[1005], dist[105][105];
vector<int> adj[2005];
 
bool bfs() {
	queue<int> q;
	for (int i = 1; i <= S; i++)
		if (!ma[i]) d[i] = 0, q.push(i);
		else d[i] = 1e9;
	d[0] = 1e9;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		if (a)
			for (auto u : adj[a])
				if (d[ma[u]] == 1e9) d[ma[u]] = d[a] + 1, q.push(ma[u]);
	}
	return d[0] != 1e9;
}
 
bool dfs(int n) {
	if (n) {
		for (auto u : adj[n])
			if (d[ma[u]] == d[n] + 1 && dfs(ma[u])) {
				ma[u] = n;
				ma[n] = u;
				return 1;
			}
		d[n] = 1e9;
		return 0;
	}
	return 1;
}
 
main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dist[i][j] = (i ^ j ? 1e9 : 0);
	for (int u, v; M--; ) {
		cin >> u >> v;
		dist[u][v] = min(dist[u][v], 1ll);
		dist[v][u] = min(dist[v][u], 1ll);
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	cin >> S >> B >> K >> H;
	for (int i = 1; i <= S; i++)
		cin >> Xs[i] >> A[i] >> F[i];
	for (int i = 1; i <= B; i++)
		cin >> Xb[i] >> D[i];
	for (int i = 1; i <= S; i++)
		for (int j = 1; j <= B; j++)
			if (A[i] >= D[j] && F[i] >= dist[Xs[i]][Xb[j]]) {
				adj[i].push_back(S + j);
				adj[S + j].push_back(i);
			}
	while (bfs())
		for (int i = 1; i <= S; i++)
			if (!ma[i] && dfs(i)) mat++;
	cout << min(mat * K, S * H) << '\n';
}