#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MXN = 200005;

typedef pair<int, int> pii;

struct Node
{
	vector<int> neighbors;
	int vis = 0;
	int p = -1;
};

Node graph[MXN];

vector<int> curr;

pii dfs(int s)
{
	graph[s].vis = 1;
	pii ans = { -1, -1 };
	for (int x : graph[s].neighbors)
	{
		if (graph[x].vis)
		{
			if (graph[x].vis == 3)
			{
				ans = { s, x };
			}
			continue;
		}
		graph[x].p = s;
		pii res = dfs(x);
		if (res.first != -1) ans = res;
	}
	graph[s].vis = 2;
	curr.push_back(s);
	return ans;
}

pii dodfs(int s)
{
	pii a = dfs(s);
	for (int x : curr)
	{
		graph[x].vis = 3;
	}
	curr.clear();
	return a;
}

vector<int> getpath(int s, int e)
{
	vector<int> ans = {e};
	while (e != s)
	{
		e = graph[e].p;
		ans.push_back(e);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, s;
	cin >> n >> m >> s;
	s--;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].neighbors.push_back(v);
	}
	int u = -1, v = -1;
	graph[s].vis = 4;
	for (int x : graph[s].neighbors)
	{
		if (graph[x].vis)
		{
			u = s;
			v = x;
			break;
		}
		graph[x].p = s;
		pii a = dodfs(x);
		if (a.first != -1)
		{
			u = a.first;
			v = a.second;
			break;
		}
	}
	if (u == -1)
	{
		cout << "Impossible\n";
	}
	else
	{
		cout << "Possible\n";
		vector<int> p = getpath(s, u);
		p.push_back(v);
		vector<int> q = getpath(s, v);
		cout << p.size() << "\n";
		for (int x : p)
		{
			cout << x + 1 << " ";
		}
		cout << "\n" << q.size() << "\n";
		for (int x : q)
		{
			cout << x + 1 << " ";
		}
		cout << "\n";
	}
	cin >> n;
}