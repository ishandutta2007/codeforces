#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define last(X) (X)[(X).size() - 1]
typedef long long ll;
using namespace std;

int n, m, u, v, g[400][400];
vector<int> dis;

int bfs(bool isgiven) {
	queue<int> q;
	int x;
	dis[0] = 0, q.push(0);
	while (!q.empty()) {
		x = q.front(), q.pop();
		if (isgiven) {
			for (int i = 0; i < n; i++)
				if (g[x][i] && dis[i] == -1)
					dis[i] = dis[x] + 1, q.push(i);
		}
		else {
			for (int i = 0; i < n; i++)
				if (!g[x][i] && dis[i] == -1)
					dis[i] = dis[x] + 1, q.push(i);
		}
	}
	return dis[n - 1];
}

int main() {
	for (int i = 0; i < 400; i++) for (int j = 0; j < 400; j++) g[i][j] = 0;
	ios::sync_with_stdio(0);
	cin >> n >> m;
	dis.resize(n, -1);
	for (int i = 0; i < m; i++) cin >> u >> v, u--, v--, g[u][v] = g[v][u] = 1;
	if (g[0][n - 1]) cout << bfs(false) << endl;
	else cout << bfs(true) << endl;
}