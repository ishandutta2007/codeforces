#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> tree[100001];
vector<long long> cost[100001];
long long DP[100001], DP2[100001];
long long visited[100001];
long long dfs2(int node)
{
	long long ans = 0;
	visited[node] = 1;
	for (int i = 0; i < tree[node].size(); i++)
	{
		int child = tree[node][i];
		long long c = cost[node][i];
		if (!visited[child])
			ans += (c+dfs2(child));
	}
	return DP2[node] = ans;
}
long long dfs(int node)
{
	visited[node] = 1;
	long long ans = DP2[node] * 2;
	for (int i = 0; i < tree[node].size(); i++)
	{
		long long c = cost[node][i];
		int child = tree[node][i];
		if (!visited[child])
			ans = min(ans, DP2[node] * 2 - 2 * c - 2 * DP2[child] + c + dfs(child));
	}
	return DP[node] = ans;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		tree[x].push_back(y);
		cost[x].push_back(w);
		tree[y].push_back(x);
		cost[y].push_back(w);
	}
	dfs2(1);
	
	memset(visited, 0, sizeof(visited));
	 cout<<dfs(1)<<endl;
}