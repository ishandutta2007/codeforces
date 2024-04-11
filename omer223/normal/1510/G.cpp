#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	vector<int> children;
	vector<int> neighbors;
	int d;
	int p = -1;
	bool vis = false;
	bool onPath = false;
	bool marked = false;
};

int n, l;
vector<int> path;
vector<int> tmp;

int DFS2(Node* graph, int s, int e)
{
	if (s == e)
	{
		tmp.push_back(e);
		return !graph[e].marked;
	}
	graph[s].vis = true;
	for (int i = 0; i < graph[s].neighbors.size(); i++)
	{
		int currNei = graph[s].neighbors[i];
		if (graph[currNei].vis) continue;
		int curr = DFS2(graph, currNei, e);
		if (curr != -1)
		{
			tmp.push_back(s);
			return curr + 1 - graph[s].marked;
		}
	}
	return -1;
}

bool tryEnd(Node* graph, int s, int k, int e)
{
	tmp.clear();
	int ans = DFS2(graph, s, e);
	for (int i = 0; i < n; i++)
	{
		graph[i].vis = false;
	}
	if (ans + l == k)
	{
		reverse(tmp.begin(), tmp.end());
		path.pop_back();
		for (int x : tmp) path.push_back(x);
		return true;
	}
	return false;
}

bool DFS(Node* graph, int s, int k, int e)
{
	path.push_back(s);
	graph[s].marked = true;
	l++;
	if (tryEnd(graph, s, k, e))
	{
		return true;
	}
	for (int i = 0; i < graph[s].children.size(); i++)
	{
		int currNei = graph[s].children[i];
		if (graph[currNei].onPath) continue;
		if (DFS(graph, currNei, k, e)) return true;
		path.push_back(s);
	}
	for (int i = 0; i < graph[s].children.size(); i++)
	{
		int currNei = graph[s].children[i];
		if (!graph[currNei].onPath) continue;
		if (DFS(graph, currNei, k, e)) return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int abc = 0; abc < t; abc++)
	{
		l = 0;
		path.clear();
		int k;
		cin >> n >> k;
		Node* graph = new Node[n];
		graph[0].d = 0;
		int maxD = 0;
		int maxDv = 0;
		for (int i = 1; i < n; i++)
		{
			int u;
			cin >> u;
			u--;
			graph[i].p = u;
			graph[u].children.push_back(i);
			graph[i].neighbors.push_back(u);
			graph[u].neighbors.push_back(i);
			graph[i].d = graph[u].d + 1;
			if (graph[i].d > maxD)
			{
				maxD = graph[i].d;
				maxDv = i;
			}
		}
		int lowest = min(k - 1, maxD);
		int l = 2 * (k - 1) - lowest;
		cout << l << endl;
		int end = 0;
		for (int i = 0; i < n; i++)
		{
			if (graph[i].d == lowest) end = i;
		}
		for (int i = end; i != -1; i = graph[i].p)
		{
			graph[i].onPath = true;
		}
		DFS(graph, 0, k, end);
		for (int x : path)
		{
			cout << x + 1 << " ";
		}
		cout << endl;
	}
	cin >> t;
}