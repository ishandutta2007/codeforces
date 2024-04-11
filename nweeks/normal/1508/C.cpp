#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Arete
{
	int u, v , w;
	
	bool operator<(Arete other) const
	{
		return w < other.w;
	}
};

struct DSU
{
	vector<int> id;

	DSU(int n) : id(n, -1) {}

	int find(int i)
	{
		if (id[i] < 0) return i;
		return id[i] = find(id[i]);
	}

	bool merge(int u, int v)
	{
		u = find(u), v = find(v);
		if (u == v) return false;
		if (id[u] > id[v]) swap(u, v);
		id[u] += id[v];
		id[v] = u;
		return true;
	}
};

const int MAXN = 2e5;
vector<int> adj[MAXN];
DSU dsu1(MAXN), dsu2(MAXN);
int nbSommets, nbAretes;
set<int> sommetsRestants;
int nbCC;

void dfs(int iSommet)
{
	sommetsRestants.erase(iSommet);
	sort(adj[iSommet].begin(), adj[iSommet].end());

	int deg = adj[iSommet].size();
	sommetsRestants.erase(iSommet);
	for (int iArete = 0; iArete <= deg; ++iArete) 
	{
		while (!sommetsRestants.empty())
		{
			auto it = sommetsRestants.upper_bound(iArete ? adj[iSommet][iArete-1] : -1);	
			if (it == sommetsRestants.end() or (iArete < deg and *it >= adj[iSommet][iArete]))
				break;
			dsu1.merge(*it, iSommet);
			dfs(*it);
		}
	}
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> nbSommets >> nbAretes;
	vector<Arete> aretes(nbAretes);
	int valXor = 0;
	for (auto &[u, v, w] : aretes)
	{
		cin >> u >> v >> w;
		valXor ^= w;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i(0); i < nbSommets; ++i) sommetsRestants.insert(i);

	for (int iSommet = 0; iSommet < nbSommets; ++iSommet) 
		if (sommetsRestants.count(iSommet))
		{
			dfs(iSommet);
			++nbCC;
		}
	sort(aretes.begin(), aretes.end());
	int nbLibres = nbSommets * (nbSommets-1) / 2 - nbAretes;
	int nbUtilises = nbSommets - nbCC;
	int curCost = nbUtilises < nbLibres ? 0 : valXor;
	bool xorRemoved = nbUtilises < nbLibres;
	int sol = 2e18;
	if (nbCC == 1) sol = curCost;
	for (auto [u, v, w] : aretes)
	{
		if (dsu1.merge(u, v))
		{
			nbCC--;
			curCost += w;
		}
		else if (dsu2.find(u) != dsu2.find(v) and w < valXor and !xorRemoved)
		{
			curCost += w - valXor;
			xorRemoved = true;
		}
		dsu2.merge(u, v);
		if (nbCC == 1) sol = min(sol, curCost);
	}
	cout << sol << endl;
}