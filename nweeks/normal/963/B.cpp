#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXN = 2e5;
vector<int> G[MAXN];
int depth[MAXN];
int deg[MAXN];
bool deleted[MAXN];
int par[MAXN];
vector<int> Q[MAXN];

void dfs(int u, int p, int d)
{
	deg[u] = SZ(G[u]);
	depth[u] = d;
	par[u] = p;
	Q[d].push_back(u);
	for (auto v : G[u])
		if (v != p)
			dfs(v, u, d+1);
}

void delete_node(int u)
{
	cout <<u+1 << '\n';
	deg[u] = 0;
	deleted[u] = true;
	for (auto v : G[u])
		if (!deleted[v] and v != par[u])
		{
			deg[v]--;
			assert(deg[v]%2==0);
			delete_node(v);
		}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_sommets;
	cin >> nb_sommets;
	if (nb_sommets%2==0)
	{
		cout << "NO" << endl;
		return 0;
	}
	for (int i(0); i < nb_sommets; ++i)
	{
		int p;
		cin >> p;
		if (p)
		{
			--p;
			G[i].push_back(p);
			G[p].push_back(i);
		}
	}
	dfs(0,0,0);
	cout << "YES" << endl;
	for (int d(nb_sommets-1); d >= 0; --d)
		for (auto u : Q[d])
			if (deg[u]%2==0)
			{
				delete_node(u);
				if (u)
					deg[par[u]]--;
			}

}