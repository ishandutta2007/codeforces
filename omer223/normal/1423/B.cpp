#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int infty = 1e9;

typedef pair<int, int> pii;

struct Node
{
	vector<pair<Node*, int>> neighbors;
	Node* pair;
	int dist = infty;

	bool isNull = false;
};

int n, m;
Node* factories;
Node* airports;
Node null;

bool BFS(int w)
{
	queue<Node*> q;
	for (int i = 0; i < n; i++)
	{
		if (factories[i].pair->isNull)
		{
			factories[i].dist = 0;
			q.push(&factories[i]);
		}
		else
		{
			factories[i].dist = infty;
		}
	}
	null.dist = infty;
	while (!q.empty())
	{
		Node* u = q.front();
		q.pop();
		if (u->dist < null.dist)
		{
			for (int i = 0; i < u->neighbors.size(); i++)
			{
				Node* v = u->neighbors[i].first;
				int currW = u->neighbors[i].second;
				if (currW > w)
				{
					continue;
				}
				Node* pair = v->pair;
				if (pair->dist == infty)
				{
					pair->dist = u->dist + 1;
					q.push(pair);
				}
			}
		}
	}
	return null.dist != infty;
}

bool DFS(Node* u, int w)
{
	if (!u->isNull)
	{
		for (int i = 0; i < u->neighbors.size(); i++)
		{
			Node* v = u->neighbors[i].first;
			int currW = u->neighbors[i].second;
			if (currW > w)
			{
				continue;
			}
			Node* pair = v->pair;
			if (pair->dist == u->dist + 1)
			{
				if (DFS(pair, w))
				{
					v->pair = u;
					u->pair = v;
					return true;
				}
			}
		}
		u->dist = infty;
		return false;
	}
	return true;
}

int hopcroftKarp(int w)
{
	for (int i = 0; i < n; i++)
	{
		factories[i].pair = &null;
		airports[i].pair = &null;
	}
	int ans = 0;
	while (BFS(w))
	{
		for (int i = 0; i < n; i++)
		{
			Node* u = &factories[i];
			if (u->pair->isNull)
			{
				if (DFS(u, w))
				{
					ans++;
				}
			}
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	factories = new Node[n];
	airports = new Node[n];
	null.isNull = true;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		factories[u].neighbors.push_back({ &airports[v], w });
		airports[v].neighbors.push_back({ &factories[u], w });
	}
	if (hopcroftKarp(infty) < n)
	{
		cout << "-1" << endl;
		cin >> n;
		return 0;
	}
	int lo = 1;
	int hi = infty;
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (hopcroftKarp(mid) == n)
		{
			hi = mid;
		}
		else
		{
			lo = mid + 1;
		}
	}
	cout << lo << endl;
	cin >> n;
}