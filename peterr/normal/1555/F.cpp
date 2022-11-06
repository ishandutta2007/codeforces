#include <bits/stdc++.h>

using namespace std;

struct bit
{
	bit() = default;
	bit(int n) : n_(n)
	{
		arr = vector<int>(n + 1);
	}
	
	int query(int pos)
	{
		int ans = 0;
		while (pos)
		{
			ans += arr[pos];
			pos -= pos & -pos;
		}
		return ans;
	}
	
	void inc(int pos, int amt)
	{
		while (pos <= n_)
		{
			arr[pos] += amt;
			pos += pos & -pos;
		}
	}
	
	vector<int> arr;
	int n_;
};

const int MAXQ = 5E5;
const int LOGN = 19;
const int MAXN = 3E5;
int par[MAXN + 1];
int sz[MAXN + 1];
vector<pair<int, int>> adjList[MAXN + 1];
int start_[MAXN + 1];
int end_[MAXN + 1];
tuple<int, int, int> a[MAXQ];
bool ans[MAXQ];
int anc[LOGN][MAXN + 1];
int dep[MAXN + 1];
bit tree;
bit taken;

int getRoot(int x)
{
	if (par[x] != x)
		par[x] = getRoot(par[x]);
	return par[x];
}

bool mge(int x, int y)
{
	x = getRoot(x);
	y = getRoot(y);
	if (x == y)
		return false;
	if (sz[x] > sz[y])
		swap(x, y);
	par[x] = y;
	sz[y] += sz[x];
	return true;
}

int cnt = 1;
void dfs1(int v, int p, int d=0)
{
	dep[v] = d;
	anc[0][v] = p;
	start_[v] = cnt++;
	for (pair<int, int> edge : adjList[v])
	{
		int adj = edge.first;
		int w = edge.second;
		if (adj == p)
			continue;
		dfs1(adj, v, d + 1);
		tree.inc(start_[adj], w);
		tree.inc(end_[adj], -w);
	}
	end_[v] = cnt++;
}

int lca(int u, int v)
{
	if (dep[u] < dep[v])
		swap(u, v);
	int diff = dep[u] - dep[v];
	for (int i = 0; i < LOGN; i++)
	{
		if (diff & (1 << i))
			u = anc[i][u];
	}
	if (u == v)
		return u;
	for (int i = LOGN - 1; i >= 0; i--)
	{
		if (anc[i][u] != anc[i][v])
		{
			u = anc[i][u];
			v = anc[i][v];
		}
	}
	return anc[0][u];
}

int queryPath(bit& b, int u, int v)
{
	int l = lca(u, v);
	int ans = 0;
	ans += b.query(start_[u]);
	ans += b.query(start_[v]);
	ans -= 2 * b.query(start_[l]);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	tree = bit(2 * n);
	taken = bit(2 * n);
	for (int i = 1; i <= n; i++)
	{
		par[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < q; i++)
	{
		int u, v, x;
		cin >> u >> v >> x;
		a[i] = {u, v, x};
		if (getRoot(u) != getRoot(v))
		{
			adjList[v].push_back({u, x});
			adjList[u].push_back({v, x});
			mge(u, v);
			ans[i] = true;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!start_[i])
			dfs1(i, i);
		//cout << "times " << i << " " << start_[i] << " " << end_[i] << endl;
	}
	for (int i = 1; i < LOGN; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			anc[i][j] = anc[i - 1][anc[i - 1][j]];
		}
	}
	for (int i = 0; i < q; i++)
	{
		if (ans[i])
			continue;
		int u = get<0>(a[i]);
		int v = get<1>(a[i]);
		int w = get<2>(a[i]);
		int l = lca(u, v);
		if (queryPath(taken, u, v))
			continue;
		if ((queryPath(tree, u, v) & 1) == w)
			continue;
		ans[i] = true;
		while (u != l)
		{
			taken.inc(start_[u], 1);
			taken.inc(end_[u], -1);
			u = anc[0][u];
		}
		while (v != l)
		{
			taken.inc(start_[v], 1);
			taken.inc(end_[v], -1);
			v = anc[0][v];
		}
	}
	for (int i = 0; i < q; i++)
		cout << (ans[i] ? "YES" : "NO") << "\n";
	return 0;
}