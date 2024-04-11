#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

const int infty = 1e9;

struct Node
{
	vector<int> neighbors;
	bool vis = false;
	int dist = infty;
	int p;
};

void do1(int* p, int n)
{
	for (int i = 0; i < 2 * n; i += 2)
	{
		swap(p[i], p[i + 1]);
	}
}

void do2(int* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		swap(p[i], p[i + n]);
	}
}

void BFS(Node* graph, int s)
{
	queue<int> q;
	q.push(s);
	graph[s].dist = 0;
	graph[s].vis = true;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int currNei : graph[u].neighbors)
		{
			if (graph[currNei].vis) continue;
			graph[currNei].vis = true;
			graph[currNei].p = u;
			graph[currNei].dist = graph[u].dist + 1;
			q.push(currNei);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int* p = new int[2 * n];
	int s = -1;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> p[i];
		if (p[i] == 1) s = i;
	}
	Node* graph = new Node[2*n];
	for (int i = 0; i < n; i++)
	{
		int u = i;
		int v = i + n;
		graph[u].neighbors.push_back(v);
		graph[v].neighbors.push_back(u);
	}
	for (int i = 0; i < 2*n; i+=2)
	{
		int u = i;
		int v = i + 1;
		graph[u].neighbors.push_back(v);
		graph[v].neighbors.push_back(u);
	}
	BFS(graph, s);
	if (!graph[0].vis)
	{
		cout << -1 << endl;
		return 0;
	}
	vector<int> swaps;
	for (int c = 0; c != s; c = graph[c].p)
	{
		int p = graph[c].p;
		if (abs(p - c) == 1)
		{
			swaps.push_back(1);
		}
		else
		{
			swaps.push_back(2);
		}
	}
	reverse(swaps.begin(), swaps.end());
	for (int op : swaps)
	{
		if (op == 1) do1(p, n);
		else do2(p, n);
	}
	for (int i = 0; i < 2 * n; i++)
	{
		if (p[i] != i + 1)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	cout << swaps.size() << endl;
}