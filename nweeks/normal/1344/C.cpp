#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXN = 2e5;

vector<int> up[MAXN];
vector<int> down[MAXN];
int quanti[MAXN];
int seen_up[MAXN];
int seen_down[MAXN];
int nb_var, nb_clauses;

void dfs0(int u)
{
	if (seen_up[u] == 1)
	{
		cout << -1 << endl;
		exit(0);
	}
	if (seen_up[u])
		return;
	seen_up[u] = 1;
	if (quanti[u] != 1)
		quanti[u] = 0;
	for (auto v : up[u])
		dfs0(v);
	seen_up[u] = 2;
}

void dfs1(int u)
{
	if (seen_down[u] == 1)
	{
		cout <<-1 << endl;
		exit(0);
	}
	if (seen_down[u])
		return ;
	seen_down[u] = 1;
	if (quanti[u] != 1)
		quanti[u] = 0;
	for (auto v : down[u])
		dfs1(v);
	seen_down[u] = 2;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> nb_var >> nb_clauses;
	while (nb_clauses--)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		up[u].push_back(v);
		down[v].push_back(u);
	}	
	for (int i(0); i < nb_var; ++i)
		quanti[i] = -1;

	int ans(0);
	for (int i(0); i < nb_var; ++i)
         {
		if (quanti[i] == -1)
		{
			quanti[i] = 1;
			++ans;
			dfs0(i);
			dfs1(i);
		}
else
{
dfs0(i);
dfs1(i);
}
}
	cout << ans << endl;
	for (int i(0); i < nb_var; ++i)
		cout << (quanti[i] ? 'A' : 'E');
	cout << endl;
}