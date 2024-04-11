#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll; 

void solve()
{
	int nbSommets, nbAretes;
	cin >> nbSommets >> nbAretes;
	vector<vector<int>> g(nbSommets);
	for (int i(0); i < nbAretes; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> ret(1, 0);
	vector<int> state(nbSommets, -1);
	queue<int> q;
	state[0] = 1;
	for (auto v : g[0])
	{
		state[v] = 0;
		q.push(v);
	}
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (auto v : g[u])
			if (state[v] == -1)
			{
				state[v] = 1;
				ret.push_back(v);
				for (auto w : g[v])
					if (state[w] == -1)
					{
						q.push(w);
						state[w] = 0;
					}
			}
	}
	for (auto v : state)
		if (v == -1)
		{
			cout << "NO\n";
			return ;
		}
	cout << "YES\n" << SZ(ret) << '\n';
	for (auto v : ret)
		cout <<v+1 << ' ';
	cout << '\n';
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}