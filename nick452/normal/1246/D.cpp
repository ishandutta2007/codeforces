#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void Dfs(const vector<vector<int>>& graph, const vector<int>& mark, int cur, vector<int>& que) {
	que.push_back(cur);
	for (int expected = 0; expected < 2; ++expected) {
		for (int next : graph[cur]) {
			if (mark[next] == expected) {
				Dfs(graph, mark, next, que);
			}
		}
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("d.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> dep(n);
	for (int i = 1; i < n; ++i) {
		cin >> p[i];
		dep[i] = dep[p[i]] + 1;
	}
	
	vector<int> mark(n);
	for (int k = std::distance(dep.begin(), max_element(dep.begin(), dep.end())); k > 0; k = p[k]) {
		mark[k] = 1;
	}

	vector<vector<int>> graph(n);
	for (int i = 1; i < n; ++i) {
		graph[p[i]].push_back(i);
	}

	vector<int> que;
	Dfs(graph, mark, 0, que);

	for (int p : que) {
		printf("%d ", p);
	}
	printf("\n");

	vector<int> operations;
	for (int i = 1; i < n; ++i) {
		int count = dep[que[i - 1]] - dep[p[que[i]]];
		for (int j = 0; j < count; ++j) {
			operations.push_back(que[i]);
		}
	}
	printf("%d\n", operations.size());
	for (int p : operations) {
		printf("%d ", p);
	}
	printf("\n");

	return 0;
}