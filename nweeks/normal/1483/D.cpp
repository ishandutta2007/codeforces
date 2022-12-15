#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Arete
{
	int iFrere, poids, iArete;

	Arete(int a, int b, int c) : iFrere(a), poids(b), iArete(c) {}
};

struct Possible
{
	int iFrere, maxPoids;

	Possible(int a, int b) : iFrere(a), maxPoids(b) {}
};

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbSommets, nbAretes;
	cin >> nbSommets >> nbAretes;
	vector<vector<Arete>> adj(nbSommets);
	for (int iArete = 0; iArete < nbAretes; ++iArete) 
	{
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		adj[u].emplace_back(v, w, iArete);
		adj[v].emplace_back(u, w, iArete);
	}

	int nbTriplets;
	cin >> nbTriplets;
	vector<vector<Possible>> possibles(nbSommets);
	while (nbTriplets--)
	{
		int u, v, l;
		cin >> u >> v >> l;
		--u, --v;
		possibles[u].emplace_back(v, l);
		possibles[v].emplace_back(u, l);
	}
	vector<bool> estUtile(nbAretes);
	vector<vector<int>> dis(nbSommets, vector<int>(nbSommets, 1e18));
	for (int i(0); i < nbSommets; ++i)
		dis[i][i] = 0;
	for (int iSommet(0); iSommet < nbSommets; ++iSommet)
		for (auto [iFrere, poids, iArete] : adj[iSommet])
			dis[iSommet][iFrere] = min(dis[iSommet][iFrere], poids);
	for (int k(0); k < nbSommets; ++k)
		for (int i(0); i < nbSommets; ++i)
			for (int j(0); j < nbSommets; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int u(0); u < nbSommets; ++u)
		for (int b(0); b < nbSommets; ++b)
		{
			int plusGrandPossible(-1e18);
			for (auto [v, maxPoids] : possibles[u])
				plusGrandPossible = max(plusGrandPossible, maxPoids - dis[b][v]);
			for (auto [a, poids, iArete] : adj[b])
				if (dis[u][a] + poids <= plusGrandPossible)
					estUtile[iArete] = true;
		}

	int sol(0);
	for (auto v : estUtile) sol += v;
	cout << sol << endl;
}