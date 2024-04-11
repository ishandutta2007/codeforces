#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXN = 2e5;

set<int> G[MAXN];
vector<pair<int, int> > aretes;
set<pair<int, int> > sommets;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_sommets, nb_aretes, nb_min;
	cin >> nb_sommets >> nb_aretes >> nb_min;
	aretes.resize(nb_aretes);
	for (auto &[u, v] : aretes)
	{
		cin >> u >> v;
		--u, --v;
		G[u].insert(v);
		G[v].insert(u);
	}	
	for (int i(0); i < nb_sommets; ++i)
		sommets.insert(make_pair(SZ(G[i]), i));
	while (SZ(sommets) > 0 and sommets.begin()->first < nb_min)
	{
		auto [d, u] = *sommets.begin();
		for (auto v : G[u])
		{
			sommets.erase(make_pair(SZ(G[v]), v));
			G[v].erase(u);
			sommets.insert(make_pair(SZ(G[v]), v));
		}
		G[u].clear();
		sommets.erase(make_pair(d, u));
	}
	vector<int> sol(nb_aretes);
	for (int i(nb_aretes-1); i >= 0; --i)
	{
		sol[i] = SZ(sommets);
		auto [u, v] = aretes[i];
		if (SZ(G[u]) >= nb_min)
		{
			sommets.erase(make_pair(SZ(G[u]), u));
			G[u].erase(v);
			sommets.insert(make_pair(SZ(G[u]) ,u ));
		}
		if (SZ(G[v]) >= nb_min)
		{
			sommets.erase(make_pair(SZ(G[v]), v));
			G[v].erase(u);
			sommets.insert(make_pair(SZ(G[v]), v));
		}
		while (SZ(sommets) > 0 and sommets.begin()->first < nb_min)
		{
			auto [d,u] = *sommets.begin();
			for (auto v : G[u])
			{
				sommets.erase(make_pair(SZ(G[v]), v));
				G[v].erase(u);
				sommets.insert(make_pair(SZ(G[v]), v));
			}
			G[u].clear();
			sommets.erase(make_pair(d, u));
		}
	}
	for (auto s : sol)
		cout <<s << '\n';
}