#include <bits/stdc++.h>
#define int long long
using namespace std;

int nbSommets, nbAretes, coutArete;

vector<int> id, curWeight;
vector<vector<pair<int, int>>> g;

int find(int i)
{
	return id[i] < 0 ? i : id[i] = find(id[i]);
}

int getWeight(int i)
{
	return curWeight[find(i)];
}

void merge(int u, int v)
{
	u = find(u), v = find(v);
	if (id[u] > id[v]) swap(u, v);
	id[u] += id[v];
	curWeight[u] += curWeight[v];
	assert(curWeight[u] >= coutArete);
	for (auto w : g[v])
		g[u].push_back(w);
	g[v].clear();
	curWeight[u] -= coutArete;
	id[v] = u;
}

struct UF2
{
	vector<int> id;

	UF2(int n) : id(n, -1) {}
	int find(int i)
	{
		return id[i] < 0 ? i : id[i] = find(id[i]);
	}

	void merge(int u, int v)
	{
		u = find(u), v = find(v);
		if (id[u] > id[v]) swap(u, v);
		id[u] += id[v];
		id[v] = u;
	}
};

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> nbSommets >> nbAretes >> coutArete;
	g.resize(nbSommets);
	vector<int> poids(nbSommets);
	for (auto &v : poids) cin >> v;
	id.assign(nbSommets, -1);
	curWeight = poids;
	UF2 uf2(nbSommets);

	int totWeight(0);
	for (auto v: poids)
		totWeight += v;
	if (totWeight < coutArete * (nbSommets - 1))
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	vector<int> sol;
	vector<pair<int, int>> edges;
	vector<int> usableEdges;
	for (int iArete = 0; iArete < nbAretes; ++iArete) 
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		edges.emplace_back(u, v);
		if (uf2.find(u) != uf2.find(v))
		{
			g[u].emplace_back(v, iArete);
			g[v].emplace_back(u, iArete);
			usableEdges.push_back(iArete);
			uf2.merge(u, v);
		}
	}
	for (int i(0); i < nbSommets; ++i)
		id[i] = -(int)g[i].size();
	assert((int)usableEdges.size() == nbSommets-1);
	priority_queue<pair<int, int>> pqNode;

	for (int i(0); i < nbSommets; ++i)
	{
		int u = find(i);
		while (!g[u].empty() and curWeight[u] >= coutArete)
		{
			auto [v, iArete] = g[u].back(); g[u].pop_back();
			v = find(v);
			if (u == v) continue;
			merge(u, v);
			u = find(u);
			sol.push_back(iArete);
		}
	}

	priority_queue<pair<int, int>> pq;
	for (int iArete = 0; iArete < (int)usableEdges.size(); ++iArete) 
	{
		auto [u, v] = edges[usableEdges[iArete]];
		if (find(u) != find(v))
			pq.emplace(getWeight(u) + getWeight(v), usableEdges[iArete]);
	}

	while (!pq.empty())
	{
		auto [weight, iArete] = pq.top(); pq.pop();
		auto [u, v] = edges[iArete];
		u = find(u), v = find(v);
		if (u == v)
			continue;
		weight = curWeight[u] + curWeight[v];
		if (weight < coutArete)
			continue;
		merge(u, v);
		sol.push_back(iArete);
	}

	assert((int)sol.size() == nbSommets-1);

	for (auto v : sol)
		cout << v+1 << '\n';
}