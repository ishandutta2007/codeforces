#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;

map<int, list<pair<int, int>>> edges;
int dp[2][MAXN];
int last_change[MAXN];

int N, M;

int main(void)
{
	ios_base::sync_with_stdio(false);
	
	fill(last_change, last_change + MAXN, -1);
	cin >> N >> M;
	for (int i(0); i < M; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges[w].push_back(make_pair(u-1, v-1));
	}
	int cur(0);
	for (auto e : edges)
	{
		auto to_update = e.second;
		for (auto v : to_update)
		{
			int first = dp[0][v.first] + 1;
			if (last_change[v.first] == cur)
				first = dp[1][v.first] + 1;
			if (first > dp[0][v.second])
			{
				dp[1][v.second] = dp[0][v.second];
				dp[0][v.second] = first;
				last_change[v.second] = cur;
			}
		}
		++cur;	
	}
	int ans(0);
	for (int i(0); i < MAXN; ++i)
		ans = max(ans, dp[0][i]);
	cout << ans << endl;
}