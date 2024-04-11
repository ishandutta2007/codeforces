#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
const int MAXK = 21;

int par[MAXK][MAXN];
vector<int> G[MAXN];
bool taken[MAXN];
int n, k;


void read_input(void)
{
	cin >> n >> k;

	for (int i(1); i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
}

void build_tree(int u, int p)
{
	for (auto v : G[u])
		if (v != p)
		{
			par[0][v] = u;
			build_tree(v, u);
		}
}

void build_sparse(void)
{
	for (int i(1); i < MAXK; ++i)
		for (int j(0); j < n; ++j)
			par[i][j] = par[i-1][par[i-1][j]];
}

int cost(int u)
{
	if (taken[u])
		return 0;
	int start = u;
	int to_take(1);
	for (int i(MAXK-1); i >= 0; --i)
		if (!taken[par[i][u]])
		{
			to_take += (1<<i);
			u = par[i][u];
		}
	if (to_take > k)
		return 0;
	u = par[0][u];
	while (start != u)
	{
		taken[start] = true;
		start = par[0][start];
	}
	return to_take;
}

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	read_input();
	par[0][n-1] = n-1;
	build_tree(n-1, n-1);
	build_sparse();
	k = n - k - 1;
	taken[n-1] = true;
	for (int i(n-2); i >= 0; --i)
		k -= cost(i);
	for (int i(0); i < n; ++i)
		if (!taken[i])
			cout << i + 1 << ' ';
	cout << endl;
}