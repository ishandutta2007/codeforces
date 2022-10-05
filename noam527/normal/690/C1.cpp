#include <iostream>
#include <vector>
#include <algorithm>
#define graph vector<vector<int>>
using namespace std;

bool visited[1001] = { false };
graph c;
int n, m, u, v;

void dfs(int v)
{
	if (!visited[v])
	{
		visited[v] = true;
		for (int i = 0; i < c[v].size(); i++) dfs(c[v][i]);
	}
}

int main()
{
	cin >> n >> m;
	c.resize(n);
	for (int i = 0; i < m; i++)
		cin >> u >> v, u--, v--, c[u].push_back(v), c[v].push_back(u);
	if (m != n - 1)
	{
		cout << "no" << endl;
		return 0;
	}
	dfs(0);
	for (int i = 0; i < n; i++)
		if (!visited[i])
		{
			cout << "no" << endl;
			return 0;
		}
	cout << "yes" << endl;
}