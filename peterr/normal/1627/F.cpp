#include <bits/stdc++.h>
 
using namespace std;

const int INF = 1E9;
const int MAXN = 500;
int adj[MAXN + 1][MAXN + 1][4];
int dist[MAXN + 1][MAXN + 1];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

void addEdge(int r1, int c1, int r2, int c2)
{
	if (r1 == r2)
	{
		adj[r1][max(c1, c2)][DOWN]++;
		adj[r1 + 1][max(c1, c2)][UP]++;
	}
	else
	{
		adj[max(r1, r2)][c1][RIGHT]++;
		adj[max(r1, r2)][c1 + 1][LEFT]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0; i <= k; i++)
		{
			for (int j = 0; j <= k; j++)
			{
				fill(adj[i][j], adj[i][j] + 4, 0);
				dist[i][j] = INF;
			}
		}
		for (int i = 0; i < n; i++)
		{
			int r1, c1, r2, c2;
			cin >> r1 >> c1 >> r2 >> c2;
			r1--;
			c1--;
			r2--;
			c2--;
			addEdge(r1, c1, r2, c2);
			addEdge(k - r1 - 1, k - c1 - 1, k - r2 - 1, k - c2 - 1);
		}
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
		pq.push({0, k / 2, k / 2});
		dist[k / 2][k / 2] = 0;
		while (pq.size())
		{
			tuple<int, int, int> tup = pq.top();
			int d = get<0>(tup);
			int r = get<1>(tup);
			int c = get<2>(tup);
			pq.pop();
			if (d > dist[r][c])
				continue;
			for (int i = 0; i < 4; i++)
			{
				int newr = r + dr[i];
				int newc = c + dc[i];
				int newd = d + adj[r][c][i];
				if (newr < 0 || newr > k || newc < 0 || newc > k)
					continue;
				if (newd < dist[newr][newc])
				{
					dist[newr][newc] = newd;
					pq.push({newd, newr, newc});
				}
			}
		}
		int ans = INF;
		for (int i = 0; i <= k; i++)
		{
			ans = min(ans, dist[i][0]);
			ans = min(ans, dist[0][i]);
			ans = min(ans, dist[i][k]);
			ans = min(ans, dist[k][i]);
		}
		cout << n - ans << "\n";
	}
	return 0;
}