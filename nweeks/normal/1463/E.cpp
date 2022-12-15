#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll; 

const int MAXN = 3e5;

vector<int> G[MAXN];
set<int> condensedGraph[MAXN];
int par[MAXN];
int pre[MAXN], post[MAXN];
bool seen[MAXN];
int nxt[MAXN];
int prv[MAXN];
int id[MAXN];
vector<int> order;
vector<int> ret;
int rnk[MAXN];
int state[MAXN];
int t;
int root;
int nbSommets, nbPaires;

void dfs(int u)
{
	pre[u] = t++;
	for (auto v : G[u])
		dfs(v);
	post[u] = t++;
}

int find(int i)
{
	if (id[i] < 0) return i;
	return id[i] = find(id[i]);
}

bool merge(int u,int v)
{
	u = find(u), v= find(v);
	if (u == v) return false;
	if (id[u] > id[v]) swap(u, v);
	id[u] += id[v];
	id[v] = u;
	return true;
}

void printComp(int u)
{
	while (prv[u] != -1)
		u = prv[u];
	while (u != -1)
	{
		rnk[u] = SZ(ret);
		ret.push_back(u);
		u = nxt[u];
	}
}

void topSort(int u)
{
	if (state[u] == 1) return;
	if (state[u] == 2)
	{
		cout << 0 << endl;
		exit(0);
	}
	state[u] = 2;
	for (auto v : condensedGraph[u])
		topSort(v);
	state[u] = 1;
	order.push_back(u);
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> nbSommets >> nbPaires;
	for (int i(0); i < nbSommets; ++i)
	{
		id[i] = -1;
		nxt[i] = prv[i] = -1;
		cin >> par[i];
		if (!par[i])
			root = i;
		par[i]--;
		if (par[i] >= 0)
			G[par[i]].push_back(i);
	}
	dfs(root);
	vector<pair<int, int>> paires(nbPaires);
	for (auto &[u, v] : paires)
	{
		cin >> u >> v;
		--u, --v;
		nxt[u] = v;
		if (prv[v] != -1)
		{
			cout << 0 << endl;
			return 0;
		}
		prv[v] = u;
		if (pre[v] < pre[u] and post[v] > post[u])
		{
			cout << 0 << endl;
			return 0;
		}
		if (pre[v] >= pre[u] and post[v] <= post[u] and par[v] != u)
		{
			cout << 0 << endl;
			return 0;
		}
		if (!merge(u, v))
		{
			cout <<0 << endl;
			return 0;
		}
	}
	for (int u(0); u < nbSommets; ++u)
		for (auto v : G[u])
			if (find(u) != find(v))
				condensedGraph[find(u)].insert(find(v));
	for (int i(0); i < nbSommets; ++i)
		topSort(find(i));
	for (int i(SZ(order)-1); i >= 0; --i)
		printComp(order[i]);
	for (int u(0); u < nbSommets; ++u)
		for (auto v : G[u])
			if (rnk[u] > rnk[v])
			{
				cout << 0 << endl;
				return 0;
			}
	for (auto v : ret) cout <<v+1 << ' ';
	cout << endl;
}