#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

vector<int> G[MAX];
int taken_by[MAX];
bool blocked[MAX];
int visiting[MAX];
int needed[MAX];

bool DFS(int u, int start)
{
	if (visiting[u] == start)
		return false;
	visiting[u] = start;
	for (auto e : G[u])
		if (!blocked[e] and (taken_by[e] == -1 or DFS(taken_by[e], start)))
		{
			taken_by[e] = u;
			return true;
		}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	
	fill(visiting, visiting + MAX, -1);
	fill(taken_by, taken_by + MAX, -1);
	int n, m;
	cin >> n >> m;
	for (int i(0); i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		blocked[b] = true;
		needed[i] = c;
		while (a < b)
			G[i].push_back(a++);
	}
	int cur(0);
	for (int i(0); i < m; ++i)
		while (needed[i]--)
			if (!DFS(i, cur++))
			{
				cout << -1;
				return 0;
			}
	for (int i(1); i <= n; ++i)
	{
		if (blocked[i])
			taken_by[i] = m;
		cout << taken_by[i] + 1 << ' ';
	}
}