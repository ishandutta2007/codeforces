#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5;
const int MAXP = 18;
const int MAXKEEP = 10;

vector<int> adj[MAXN];
vector<int> dansVilles[MAXN];
int par[MAXP][MAXN];
vector<int> dansVilleUp[MAXP][MAXN];
int depth[MAXN];
int nbSommets, nbPersonnes,nbRequetes;

void dfs(int iNoeud, int iPere)
{
	par[0][iNoeud] = iPere;
	for (int iFrere : adj[iNoeud])
		if (iFrere != iPere)
		{
			depth[iFrere] = depth[iNoeud] + 1;
			dfs(iFrere, iNoeud);
		}
}

vector<int> fusion(vector<int> &lhs, vector<int> &rhs)
{
	int iL(0), iR(0);
	vector<int> ret; ret.reserve(MAXKEEP);
	while ((iL < (int)lhs.size() or iR < (int)rhs.size()) and (int)ret.size() < MAXKEEP)
	{
		if (iL == (int)lhs.size())
			ret.push_back(rhs[iR++]);
		else if (iR == (int)rhs.size())
			ret.push_back(lhs[iL++]);
		else if (lhs[iL] < rhs[iR])
			ret.push_back(lhs[iL++]);
		else if (lhs[iL] > rhs[iR])
			ret.push_back(rhs[iR++]);
		else
			ret.push_back(lhs[iL++]), iR++;
	}
	return ret;
}

void init()
{
	for (int i = 0; i < nbSommets; ++i) 
		dansVilleUp[0][i] = dansVilles[par[0][i]];
	for (int p = 0; p < MAXP-1; ++p) 
		for (int i = 0; i < nbSommets; ++i) 
		{
			par[p+1][i] = par[p][par[p][i]];
			dansVilleUp[p+1][i] = fusion(dansVilleUp[p][i],dansVilleUp[p][par[p][i]]);
		}
}


signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> nbSommets >> nbPersonnes >> nbRequetes;
	for (int iSommet = 0; iSommet < nbSommets-1; ++iSommet) 
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int iPer = 0; iPer < nbPersonnes; ++iPer) 
	{
		int ville;
		cin >> ville;
		--ville;
		if ((int)dansVilles[ville].size() < MAXKEEP)
			dansVilles[ville].push_back(iPer);
	}
	dfs(0, 0);
	init();

	while (nbRequetes--)
	{
		int u, v, keep;
		cin >> u >> v >> keep;
		--u, --v;
		if (depth[u] < depth[v]) swap(u, v);
		vector<int> sol = fusion(dansVilles[u], dansVilles[v]);
		int diff = depth[u] - depth[v];
		for (int p(0); p < MAXP; ++p)
			if ((1<<p) & diff)
			{
				assert(p != MAXP-1);
				sol = fusion(sol, dansVilleUp[p][u]);
				u = par[p][u];
			}
		for (int p(MAXP-1); p >= 0; --p)
			if (par[p][u] != par[p][v])
			{
				assert(p != MAXP-1);
				sol = fusion(sol, dansVilleUp[p][u]);
				sol = fusion(sol, dansVilleUp[p][v]);
				u = par[p][u], v = par[p][v];
			}
		if (u != v)
			sol = fusion(sol, dansVilleUp[0][u]);
		if ((int)sol.size() > keep)
			sol.resize(keep);
		cout << sol.size() << ' ';
		for (auto v : sol) cout << v + 1 << ' ';
		cout << '\n';
	}
}