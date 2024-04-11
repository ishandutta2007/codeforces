#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
int d[MAXN + 1];
int par[MAXN + 1];
int down_[MAXN + 1];
int val[MAXN + 1];
bool visited[MAXN + 1];

void dfs(int v, int p, int d_ = 0)
{
	down_[v] = v;
	par[v] = p;
	d[v] = d_;
	for (int adj : adjList[v])
	{
		if (adj == p)
			continue;
		dfs(adj, v, d_ + 1);
		if (d[down_[adj]] > d[down_[v]])
			down_[v] = down_[adj];
	}
	val[v] = d[down_[v]] - d[v];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	int leaves = 0;
	for (int i = 2; i <= n; i++)
	{
		leaves += adjList[i].size() == 1;
	}
	long long ans = 0; 
	if (k >= leaves)
	{
		for (int i = leaves; i <= k; i++)
			ans = max(ans, (long long) (n - i) * i);
	}
	else
	{
		dfs(1, 1);
		priority_queue<pair<int, int>> pq;
		pq.push({val[1], 1});
		for (int i = 0; i < k; i++)
		{
			pair<int, int> pr = pq.top();
			//cout << "popped " << pr.first << " " << pr.second << endl;
			pq.pop();
			int v = down_[pr.second];
			int prev = v;
			while (!visited[v])
			{
				for (int adj : adjList[v])
				{
					if (adj == par[v] || adj == prev)
						continue;
					pq.push({val[adj], adj});
				}
				visited[v] = true;
				prev = v;
				v = par[v];
			}
		}
		ans = (long long) (n - k) * k;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += (!visited[i]);
		//cout << "cnt " << cnt << endl;
		for (int i = 1; i <= cnt; i++)
			ans = min(ans, (long long) (n - k - i) * (k - i));
	}
	cout << ans << "\n";
	return 0;
}