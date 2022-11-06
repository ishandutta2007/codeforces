#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int max(int a, int b)
{
	if(a > b)
		return a;
	return b;
}

class DSU
{
private:
	int *parent;
	int n;
	int *size;
	int *rad;
	int *dia;

public:
	DSU(int n);
	int root(int x);
	void merge(int x, int y);
	bool areInSame(int x, int y);
	void set(int d, int r, int x) {dia[x] = d, rad[x] = r;};
	int getdia(int x) { return dia[root(x)];}
	~DSU();
};

DSU::DSU(int n) 
{
	this->n = n;
	parent = new int[n];
	size = new int[n];
	dia = new int[n];
	rad = new int[n];
	for (int i = 0; i < n; ++i) {
		parent[i] = i;
		size[i] = 1;
	}
}

int DSU::root(int x)
{
	if(parent[x] == x)
		return x;
	return parent[x] = root(parent[x]);
}

void DSU::merge(int x, int y)
{
	x = root(x);
	y = root(y);
	if(x != y) {
		if(size[x] < size[y])
			swap(x, y);
		parent[y] = x;
		set(max(dia[x], max(dia[y], rad[x]+rad[y]+1)), min(max(rad[x], rad[y]+1), max(rad[y], rad[x]+1)), x);
		size[x] += size[y];
	}
}

bool DSU::areInSame(int x, int y)
{
	if(root(x) == root(y))
		return true;
	return false;
}

DSU::~DSU()
{
	delete parent;
	delete size;
}

std::vector<int> in;
std::vector<int> ex;

pair<int, int> dfs(std::vector<std::vector<int> >& adj, int u, int p, int l, std::vector<bool>& vis)
{
	vis[u] = true;
	std::pair<int, int> p1 = mp(l, u);
	for (int v : adj[u])
		if(v != p)
			p1 = max(p1, dfs(adj, v, u, l+1, vis));
	return p1;
}

int dfs2(std::vector<std::vector<int> >& adj, int u, int p, int l)
{
	int m = l;
	for (auto v : adj[u])
		if(v != p)
			m = max(m, dfs2(adj, v, u, l + 1));
	return m;
}

std::pair<int, int> dfsUTIL(std::vector<std::vector<int> >& adj, int i, std::vector<bool>& vis)
{
	pair<int, int> far = dfs(adj, i, -1, 0, vis);
	int dia = dfs2(adj, far.second, -1, 0);
	return mp(dia, (dia+1)/2);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, m, q;
	cin >> n >> m >> q;
	DSU d(n);
	in.resize(n);
	ex.resize(n);
	std::vector<std::vector<int> > adj(n);
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		d.merge(x, y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	std::vector<bool> vis(n, false);
	for (int i = 0; i < n; ++i)
		if(!vis[i]) {
			auto r = dfsUTIL(adj, i, vis);
			d.set(r.first, r.second, d.root(i));
		}
	for (int i = 0; i < q; ++i)
	{
		int t;
		cin >> t;
		if(t == 1)
		{
			int x;
			cin >> x;
			cout << d.getdia(x-1) << "\n";
		}
		else 
		{
			int x, y;
			cin >> x >> y;
			if(d.root(x-1) != d.root(y-1))
				d.merge(x-1, y-1);
		}
	}
}