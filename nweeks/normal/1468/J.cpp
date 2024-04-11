#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct UF
{
	vector<int> id;

	UF(int n) {id.assign(n, -1);}

	int find(int u)
	{
		if (id[u] < 0) return u;
		return id[u] = find(id[u]);
	}

	bool merge(int u, int v)
	{
		u = find(u), v = find(v);
		if (u == v)
			return false;
		if (id[u] > id[v]) swap(u, v);
		id[u] += id[v];
		id[v] = u;
		return true;
	}
};

struct Arete
{
	int u, v, w;

	bool operator<(Arete other) const
	{
		if (w == other.w)
			return make_pair(u,v) < make_pair(other.u, other.v);
		return w < other.w;
	}
};

ll solve(void)
{
	ll nbSommets, nbAretes, wanted;
	cin >> nbSommets >> nbAretes >> wanted;
	vector<Arete> aretes(nbAretes);
	for (auto &v : aretes)
	{
		cin >> v.u >> v.v >> v.w;
		--v.u, --v.v;
	}
	sort(aretes.begin(), aretes.end());
	int nbcc(nbSommets);
	int i(0);
	UF uf(nbSommets);
	while (i < nbAretes and aretes[i].w <= wanted)
	{
		nbcc -= uf.merge(aretes[i].u, aretes[i].v);
		++i;
	}
	ll ans(0);
	if (nbcc == 1)
	{
		if (!i)
			return aretes[i].w - wanted;
		ans = wanted - aretes[i-1].w;
		if (i < nbAretes)
			ans = min(ans, aretes[i].w - wanted);
		return ans;
	}
	ll cost(0);
	while (i < nbAretes)
	{
		cost += uf.merge(aretes[i].u, aretes[i].v) * (aretes[i].w - wanted);
		++i;
	}
	return cost;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		cout << solve() << '\n';
}