#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const int MAXN = 2e5;
const int MAXP = 20;
int par[MAXP][MAXN];

int depth[MAXN];
int n,m;
vector<int> G[MAXN];

void dfs(int u, int p, int d)
{
	par[0][u] = p;
	depth[u] = d;
	for (auto v : G[u])
		if (v != p)
			dfs(v, u, d+1);
}

void calc_par(void)
{
	for (int p(1); p < MAXP; ++p)
		for (int i(0); i < n; ++i)
			par[p][i] = par[p-1][ par[p-1][i] ];
}

int go_up(int u, int dis)
{
	for (int p(0); p < MAXP; ++p)
		if ((1<<p)&dis)
			u = par[p][u];
	return u;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i(1); i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(0,0,0);
	calc_par();
	while (m--)
	{
		int sz_query;
		cin >> sz_query;

		vector<int> vertices(sz_query);
		for (auto &v : vertices)
		{
			cin >> v;
			--v;
		}

		int lowest(0);
		for (int i(1); i < sz_query; ++i)
			if (depth[vertices[lowest]] < depth[vertices[i]])
				lowest = i;
		bool ok = true;
		for (int i(0); i < sz_query; ++i)
			if (lowest != i)
			{
				int diff = depth[vertices[lowest]] - depth[vertices[i]];

				if (go_up(vertices[lowest], diff) != vertices[i]
					and go_up(vertices[lowest], diff+1) != par[0][vertices[i]])
					ok = false;
			}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}