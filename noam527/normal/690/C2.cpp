#include <iostream>
#include <algorithm>
#include <vector>
#define graph vector<vector<int>>
using namespace std;

int n, m, u, v, maxd = 0, maxp;
graph cons;

void dfs(int v, int dis = 0, int prev = -1)
{
	if (dis > maxd) maxd = dis, maxp = v;
	for (int i = 0; i < cons[v].size(); i++)
		if (cons[v][i] != prev)
			dfs(cons[v][i], dis + 1, v);
}

int main()
{
	cin >> n >> m;
	cons.resize(n);
	for (int i = 0; i < m; i++)
		cin >> u >> v, u--, v--, cons[v].push_back(u), cons[u].push_back(v);
	dfs(0);
	dfs(maxp);
	cout << maxd << endl;
}