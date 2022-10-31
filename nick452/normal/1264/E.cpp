#include <bits/stdc++.h>

using namespace std;

int dfs(int n, int current, vector<int>& visited, vector<vector<int>>& graph, vector<vector<int>>& results) {
	visited[current] = 1;
	for (int next = 0; next < n; ++next) {
		if (!graph[current][next] || results[current][next]) {
			continue;
		}
		if (!results[next][current] || !visited[next] && dfs(n, next, visited, graph, results)) {
			results[current][next] = 1;
			results[next][current] = 0;
			return 1;
		}
	}
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(n));
	vector<vector<int>> results(n, vector<int>(n));
	vector<int> d(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				graph[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		results[a][b] = 1;
		++d[a];
		graph[a][b] = graph[b][a] = 0;
	}
	for (int current_d = 0; current_d < n; ++current_d) {
		for (int src = 0; src < n; ++src) {
			if (d[src] != current_d) {
				continue;
			}
			vector<int> visited(n);
			if (dfs(n, src, visited, graph, results)) {
				++d[src];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d", results[i][j]);
		}
		printf("\n");
	}
	return 0;
}