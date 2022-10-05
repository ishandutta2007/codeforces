#include <iostream>
#include <algorithm>
#include <vector>
#define graph vector<vector<int>>
using namespace std;

int n, u, v, ans = 0;
graph cons;

void dfs(int x, int dis = 0, int prev = -1)
{
	if (dis == 2)
	{
		ans++;
		return;
	}
	for (int i = 0; i < cons[x].size(); i++)
		if (cons[x][i] != prev)
			dfs(cons[x][i], dis + 1, x);
}

int main()
{
	cin >> n;
	cons.resize(n);
	for (int i = 0; i < n - 1; i++)
		cin >> u >> v, cons[u - 1].push_back(v - 1), cons[v - 1].push_back(u - 1);
	for (int i = 0; i < n; i++)
		dfs(i);
	cout << ans / 2 << endl;
}