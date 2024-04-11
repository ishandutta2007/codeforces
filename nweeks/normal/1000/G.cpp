#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXP = 20;
const int MAXN = 3e5;

int nbSommets, nbRequetes;
vector<pair<int, int>> adj[MAXN];

int valNode[MAXN];
int valEdge[MAXN];
int bestSubtree[MAXN];
int bestLoop[MAXN];
int par[MAXP][MAXN];
int bestUp[MAXP][MAXN];
int parEdge[MAXN];
int depth[MAXN];
int depthVal[MAXN];

void dfs(int iNoeud, int iPere)
{
	par[0][iNoeud] = iPere;
	bestSubtree[iNoeud] = valNode[iNoeud];
	depthVal[iNoeud] += valNode[iNoeud];
	for (auto [iFils, iArete] : adj[iNoeud])
		if (iFils != iPere)
		{
			depth[iFils] = depth[iNoeud] + 1;
			depthVal[iFils] = depthVal[iNoeud] - valEdge[iArete];
			parEdge[iFils] = iArete;
			dfs(iFils, iNoeud);
			bestSubtree[iNoeud] += max(0LL, bestSubtree[iFils] - 2*valEdge[iArete]);
		}
}

void dfs2(int iNoeud, int iPere)
{
	bestLoop[iNoeud] = bestSubtree[iNoeud];
	if (iNoeud)
		bestLoop[iNoeud] += max(0LL, bestLoop[iPere] - 2 * valEdge[parEdge[iNoeud]] - max(0LL, bestSubtree[iNoeud] - 2 * valEdge[parEdge[iNoeud]]));
	for (auto [iFils, iArete] : adj[iNoeud])
		if (iFils != iPere)
			dfs2(iFils, iNoeud);
}

void init()
{
	for (int iNoeud(1); iNoeud < nbSommets; ++iNoeud)
	{
		int p = par[0][iNoeud];
		int pp = par[0][p];
		bestUp[0][iNoeud] = bestLoop[p];
		bestUp[0][iNoeud] -= max(0LL, bestSubtree[iNoeud] - 2 * valEdge[parEdge[iNoeud]]);
		if (p)
			bestUp[0][iNoeud] -= 
				max(0LL, bestLoop[pp] - 2 * valEdge[parEdge[p]]
						- max(0LL, bestSubtree[p] - 2 * valEdge[parEdge[p]]));
		bestUp[0][iNoeud] -= valNode[p];
	}
	for (int p(0); p < MAXP-1; ++p)
		for (int iNoeud(0); iNoeud < nbSommets; ++iNoeud)
		{
			int pa = par[p][iNoeud];
			par[p+1][iNoeud] = par[p][pa];
			bestUp[p+1][iNoeud] = bestUp[p][iNoeud] + bestUp[p][pa];
		}
}

int goUp(int a, int dis)
{
	for (int p(0); p < MAXP; ++p)
		if ((1<<p) & dis)
			a = par[p][a];
	return a;
}

int calcLCA(int u, int v)
{
	if (depth[u] < depth[v]) swap(u, v);
	u = goUp(u, depth[u] - depth[v]);
	if (u == v) return u;
	for (int p(MAXP-1); p >= 0; --p)
		if (par[p][u] != par[p][v])
			u = par[p][u], v = par[p][v];
	return par[0][u];
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> nbSommets >> nbRequetes;
	for (int iSommets = 0; iSommets < nbSommets; ++iSommets) 
		cin >> valNode[iSommets];
	for (int iArete(0); iArete < nbSommets-1; ++iArete)
	{
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		valEdge[iArete] = w;
		adj[u].emplace_back(v, iArete);
		adj[v].emplace_back(u, iArete);
	}
	dfs(0, 0);
	dfs2(0, 0);
	init();
	
	/*for (int iSommet = 0; iSommet < nbSommets; ++iSommet) 
	{
		cout << iSommet+1 << ' ' << bestSubtree[iSommet] << ' ' << bestLoop[iSommet] <<endl;
	}*/

	for (int iRequete = 0; iRequete < nbRequetes; ++iRequete) 
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		if (u == v)
		{
			cout << bestLoop[u] << '\n';
			continue;
		}
		int lca = calcLCA(u, v);
		int ret = depthVal[u] + depthVal[v] - 2 * depthVal[lca] + valNode[lca];
		if (u != lca) ret += bestSubtree[u] - valNode[u];
		if (v != lca) ret += bestSubtree[v] - valNode[v];
		if (lca)
			ret += max(0LL, bestLoop[par[0][lca]] - max(0LL, bestSubtree[lca] - 2 * valEdge[parEdge[lca]]) - 2 * valEdge[parEdge[lca]]);
		if (depth[u] < depth[v]) swap(u,v);
		int dis = depth[u] - depth[v];
		for (int p(0); p < MAXP; ++p)
			if ((1<<p) & dis)
			{
				ret += max(0LL, bestUp[p][u]);
				u = par[p][u];
			}
		for (int p(MAXP-1); p >= 0; --p)
			if (par[p][u] != par[p][v])
			{
				ret  += max(0LL, bestUp[p][u]) + max(0LL, bestUp[p][v]);
				u = par[p][u], v = par[p][v];
			}
		if (u != v)
		{
			ret += max(0LL, bestSubtree[lca] - max(0LL, bestSubtree[u] - 2*valEdge[parEdge[u]]) - max(0LL, bestSubtree[v] - 2*valEdge[parEdge[v]]) - valNode[lca]);
		}

		cout << ret << '\n';
	}
}