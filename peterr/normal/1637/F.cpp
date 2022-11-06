#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int h[MAXN + 1];
unordered_set<int> adjList[MAXN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].insert(v);
		adjList[v].insert(u);
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> vec;
	for (int i = 1; i <= n; i++)
	{
		if (adjList[i].size() == 1)
			pq.push({h[i], i});
		vec.push_back(h[i]);
	}
	sort(vec.begin(), vec.end());
	vec.resize(distance(vec.begin(), unique(vec.begin(), vec.end())));
	long long ans = 0;
	int prev = 0;
	for (int val : vec)
	{
		while (pq.size() && pq.top().first < val)
		{
			pair<int, int> pr = pq.top();
			pq.pop();
			int v = pr.second;
			int adj = *adjList[v].begin();
			adjList[adj].erase(v);
			adjList[v].erase(adj);
			if (adjList[adj].size() == 1)
				pq.push({h[adj], adj});
		}
		ans += (long long) max(2, (int) pq.size()) * (val - prev);
		prev = val;
	}
	cout << ans << "\n";
	return 0;
}