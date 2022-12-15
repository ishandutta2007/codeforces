#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 5000;

vector<pair<int, int> > G[MAXN];
pair<int, int> parent[MAXN][MAXN];
int beauty[MAXN];

int nb_noeuds;

struct Query
{
	int u, v, b;

	bool operator<(Query other) const
	{
		if (b==other.b)
			return make_pair(u,v) < make_pair(other.u,other.v);
		return b > other.b;
	}
};

void dfs(int u, int p, int from)
{
	for (auto v : G[u])
		if (v.first != p)
		{
			parent[from][v.first] = make_pair(u, v.second);
			dfs(v.first, u, from);
		}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> nb_noeuds;
	for (int i(1); i < nb_noeuds; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u,--v;
		G[u].push_back({v,i});
		G[v].push_back({u,i});
	}
	for (int i(0); i < nb_noeuds; ++i)
	{
		beauty[i] = -1;
		dfs(i,i,i);
	}
	
	int m;
	cin >> m;
	vector<Query> queries(m);
	for (int i(0); i < m; ++i)
	{
		int u, v, b;
		cin >> u >> v >> b;
		--u,--v;
		queries[i] = {u,v,b};
	}
	sort(queries.begin(), queries.end());
	
	for (int i(0); i < m; ++i)
	{
		int u = queries[i].u;
		int v = queries[i].v;
		int b = queries[i].b;
		bool can = false;
		while (v != u)
		{
			if (beauty[parent[v][u].second] == -1)
			{
				beauty[parent[v][u].second] = b;
				can = true;
				
			}
			if (beauty[parent[v][u].second] == b)
				can=true;
			u = parent[v][u].first;
		}
		if (!can)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i(1); i < nb_noeuds; ++i)
	{
		if (beauty[i] == -1)
			beauty[i] = 1;
		cout << beauty[i] << " \n"[i == nb_noeuds-1];
	}
}