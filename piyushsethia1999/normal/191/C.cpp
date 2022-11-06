#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;

class LCA_B
{
	std::vector<std::vector<int> > bin_parent;
	std::vector<int> tin, tout;
	int l;
public:
	LCA_B(std::vector<std::vector<int> >& adj, int siz);
	void precompute_dfs(std::vector<std::vector<int> >& adj, int u, int p, int& ticker);
	int query(int u, int v);
};

LCA_B::LCA_B(std::vector<std::vector<int> >& adj, int siz)
{
	tin.resize(siz);
	tout.resize(siz);
	int ticker = 0;
	l = ceil(log2(siz));
	bin_parent.resize(siz, std::vector<int> (l + 1));
	precompute_dfs(adj, 0, 0, ticker);
}
void LCA_B::precompute_dfs(std::vector<std::vector<int> >& adj, int u, int p, int& ticker)
{
	tin[u] = ++ticker;
	bin_parent[u][0] = p;
	for (int i = 1; i <= l; ++i)
		bin_parent[u][i] = bin_parent[bin_parent[u][i-1]][i-1];
	for (int v : adj[u])
		if(v != p)
			precompute_dfs(adj, v, u, ticker);
	tout[u] = ++ticker;
}
int LCA_B::query(int u, int v)
{
	auto is_ancestor = [&](int a, int b){ return (tin[a] <= tin[b] && tout[b] <= tout[a]); };
	if(is_ancestor(u, v))
		return u;
	if(is_ancestor(v, u))
		return v;
	for (int i = l; i >= 0 ; --i)
		if (!is_ancestor(bin_parent[u][i], v))
			u = bin_parent[u][i];
	return bin_parent[u][0];
}

int dfs(std::vector<std::vector<int> > &adj, std::vector<std::vector<int> > &adjpos, std::vector<int> &in, std::vector<int> &fill, int n, int u, int p)
{
	int posutop = -1;
	int ho = in[u];
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(v != p)
			ho += dfs(adj, adjpos, in, fill, n, v, u);
		else
			posutop = adjpos[u][i];
	}
	if (posutop != -1)
		fill[posutop] = ho;
	return ho;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#endif
	int n; cin >> n;
	std::vector<std::vector<int> > adjpos(n);
	vector<vector<int> > adj(n); for (int o = 0; o < n - 1; ++o) { int x, y; cin >> x >> y; x--; y--; adj[x].pb(y); adj[y].pb(x); adjpos[x].pb(o); adjpos[y].pb(o);}
	LCA_B lca(adj, n);
	int k; cin >> k;
	std::vector<int> in(n, 0);
	while(k--)
	{
		int a; cin >> a;
		int b; cin >> b;
		a--;
		b--;
		int l = lca.query(a, b);
		in[a]++;
		in[b]++;
		in[l]-=2;
	}
	std::vector<int> fill(n-1, 0);
	dfs(adj, adjpos, in, fill, n, 0, -1);
	for (int i = 0; i < n-1; ++i)
		cout << fill[i] << " ";
}