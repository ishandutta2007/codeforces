#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(i, j, n) for (int i(j); i < (n); ++i)
#define FORR(v, c) for (auto &v : (c))
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '

typedef	long long ll;

int solve(int testcase);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	solve(0);
}

const int MAXN = 3e5;

set<int> G[MAXN];
vector<set<int>> tree;
vector<pair<int, int> > bridges;
bool seen[MAXN];
int depth[MAXN];
int lo[MAXN];
int id[MAXN];
int cc[MAXN];
int nb_sommets, nb_aretes;
int nb_cc;

void read_input(void)
{
	cin >> nb_sommets >> nb_aretes;
	FOR(i,0,nb_aretes)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		G[u].insert(v);
		G[v].insert(u);
	}
}

void dfs(int u, int d, int p)
{
	depth[u] = d;
	seen[u] = true;
	lo[u] = d;
	for (auto v : G[u])
		if (v != p)
		{
			if (!seen[v])
			{
				dfs(v, d+1, u);
				if (lo[v] > depth[u])
					bridges.emplace_back(u,v);
			}
			lo[u] = min(lo[u], lo[v]);
		}
}

void find_bridges()
{
	dfs(0,0, 0);
}

int find(int u) { return (id[u] < 0 ? u : id[u] = find(id[u])); }

bool merge(int u, int v)
{
	u = find(u), v = find(v);
	if (u==v) return false;
	if (id[u]>id[v]) swap(u,v);
	id[u]+=id[v];
	id[v]=u;
	return true;
}

void build_tree()
{
	for (auto [u,v] : bridges)
	{
		G[u].erase(v);
		G[v].erase(u);
	}
	FOR(i,0,nb_sommets)
		id[i]=-1;
	FOR(u,0, nb_sommets)
		FORR(v, G[u])
			merge(u,v);
	nb_cc=0;
	FOR(i,0, nb_sommets)
		if (id[i] < 0)
			cc[i] = nb_cc++;
	tree.resize(nb_cc);
	FOR(i,0, nb_sommets)
		cc[i] = cc[find(i)];


	for (auto [u,v] : bridges)
	{
		if (cc[u] != cc[v])
		{
			tree[cc[v]].insert(cc[u]);
			tree[cc[u]].insert(cc[v]);
		}
	}
}

pair<int, int> bfs(int source)
{
	vector<int> dis(nb_cc, -1);
	dis[source]=0;
	queue<int> Q;
	Q.push(source);
	int lst(source);
	while (SZ(Q))
	{
		int u = Q.front(); Q.pop();
		lst = u;
		FORR(v, tree[u])
			if (dis[v]==-1)
			{
				dis[v]=dis[u]+1;
				Q.push(v);
			}
	}
	return make_pair(lst, dis[lst]);
}

int find_diam()
{
	return bfs( bfs(0).first).second;
}

int solve(int testcase)
{
	read_input();
	find_bridges();
	build_tree();
	cout << find_diam() << endl;
	return 1;
}