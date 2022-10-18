#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N(222);

int n, m;
int adj[N][N], visit[N], deg[N];
vector<pair<int, int> > answer;
set<pair<int, int> > baned;

void dfs(int x) {
	visit[x] = 1;
	for (int y = 1; y <= n; y++) {
		while (adj[x][y]) {
			adj[x][y]--;
			adj[y][x]--;
			dfs(y);
			answer.push_back({x, y});
		}
	}
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			visit[i] = 0;
			deg[i] = 0;
			for (int j = 1; j <= n; j++) {
				adj[i][j] = 0;
			}
		}
		baned.clear();
		answer.clear();
		for (int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u][v] = adj[v][u] = 1;
			deg[v]++;
			deg[u]++;
		}
		for (int i = 1; i <= n; i++) {
			if (deg[i] % 2 == 1) {
				for (int j = i + 1; j <= n; j++) {
					if (deg[j] % 2 == 1) {
						baned.insert({i, j});
						adj[i][j]++;
						adj[j][i]++;
						deg[i]++;
						deg[j]++;
						break;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				dfs(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			deg[i] = 0;
		}
		vector<pair<int, int> > result;
		for (auto p : answer) {
			int a = p.first, b = p.second;
			if (baned.count({a, b}) || baned.count({b, a})) {
				baned.erase({min(a, b), max(a, b)});
			} else {
				deg[a]++;
				deg[b]--;
				result.push_back({a, b});
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (deg[i] == 0) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
		for (int i = 0; i < result.size(); i++) {
			printf("%d %d\n", result[i].first, result[i].second);
		}
	}
	return 0;
}