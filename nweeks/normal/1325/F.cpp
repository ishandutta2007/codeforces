#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;
const int MAXN = 1e5;

vector<int> G[MAXN];
int SQRT;
int nb_sommets, nb_aretes;
int par[MAXN];
int depth[MAXN];
bool visited[MAXN];
vector<int> indep;
bool in_indep[MAXN];

void get_sqrt(void)
{
	while (SQRT*SQRT < nb_sommets)
		++SQRT;
}

void dfs(int u)
{
	visited[u] = true;
	for (auto v : G[u])
	{
		if (visited[v] and depth[u] - depth[v] + 1 >= SQRT)
		{
			cout << 2 << endl;
			cout << depth[u] - depth[v] +1 << endl;
			while (u != v)
			{
				cout << u+1 << ' ';
				u = par[u];
			}
			cout << v+1 << endl;
			exit(0);
		}
		if (!visited[v])
		{
			par[v] = u;
			depth[v] = depth[u]+1;
			dfs(v);
		}
	}
	bool can_add(true);
	for (auto v : G[u])
		if (in_indep[v])
		{
			can_add = false;
			break;
		}
	if (can_add)
	{
		in_indep[u] = true;
		indep.push_back(u);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> nb_sommets >> nb_aretes;
	get_sqrt();
	while (nb_aretes--)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}	
	dfs(0);
	cout << 1 << endl;
	assert(SZ(indep) >= SQRT);
	for (int i(0); i < SQRT; ++i)
		cout << indep[i]+1 << ' ';
	cout << endl;
}