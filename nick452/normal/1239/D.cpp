#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void show(const vector<int>& results) {
	printf("Yes\n");
	int c0 = std::count(results.begin(), results.end(), 0);
	printf("%d %d\n", c0, results.size() - c0);
	for (int g = 0; g < 2; ++g) {
		for (int i = 0; i < results.size(); ++i) {
			if (results[i] == g) {
				printf("%d ", i + 1);
			}
		}
		printf("\n");
	}
}

void dfs(const vector<vector<int>>& graph, int current, vector<int>& visited) {
	if (visited[current]) {
		return;
	}
	visited[current] = 1;
	for (int next : graph[current]) {
		dfs(graph, next, visited);
	}
}

void do_one_case() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	vector<vector<int>> reverse_graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		if (a == b) {
			continue;
		}
		graph[a].push_back(b);
		reverse_graph[b].push_back(a);
	}
	vector<int> visited(n);
	dfs(graph, 0, visited);
	if (std::find(visited.begin(), visited.end(), 0) != visited.end()) {
		for (int i = 0; i < n; ++i) {
			visited[i] ^= 1;
		}
		show(visited);
		return;
	}
	visited = vector<int>(n);
	dfs(reverse_graph, 0, visited);
	if (std::find(visited.begin(), visited.end(), 0) != visited.end()) {
		int source = std::distance(visited.begin(), std::find(visited.begin(), visited.end(), 0));
		visited = vector<int>(n);
		dfs(graph, source, visited);
		if (std::find(visited.begin(), visited.end(), 0) != visited.end()) {
			for (int i = 0; i < n; ++i) {
				visited[i] ^= 1;
			}
			show(visited);
			return;
		}
	}
	printf("No\n");
}
int main()
{
#ifdef _MSC_VER
	freopen("d.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int cases;
	cin >> cases;
	while (cases--) {
		do_one_case();
	}
	return 0;
}