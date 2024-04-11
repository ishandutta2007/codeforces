#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

class DSU
{
private:
	int *parent;
	int n;
	int *size;

public:
	DSU(int n);
	int root(int x);
	void merge(int x, int y);
	bool areInSame(int x, int y);
};

DSU::DSU(int n) 
{
	this->n = n;
	parent = new int[n];
	size = new int[n];
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
		size[x] += size[y];
	}
}

bool DSU::areInSame(int x, int y)
{
	if(root(x) == root(y))
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, m, k;
	int INF = 1000000007;
	cin >> n >> m >> k;
	DSU d(n);
	bool iscorrect = true;
	std::vector<int> c(k+1, 0);
	std::vector<std::vector<std::pair<int, int> > > adj(n);
	for (int i = 1; i <= k; ++i)
	{
		cin >> c[i];
		c[i] += c[i-1];
	}
	int u, v, x;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v >> x; u--; v--;
		adj[u].pb(mp(v, x)); 
		adj[v].pb(mp(u, x)); 
		if(x == 0)
		{
			d.merge(u, v);
		}
	}
	std::vector<int> type(n);
	for (int i = 0; i < k; ++i)
	{
		int r = d.root(c[i]);
		for (int j = c[i]; j < c[i+1]; ++j)
		{
			type[j] = i;
			if(d.root(j) != r) {
				iscorrect = false;
				break;
			}
		}
	}
	if(!iscorrect) {
		cout << "No";
		exit(0);
	}
	cout << "Yes\n";
	std::vector<std::vector<int> > grid(k, std::vector<int> (k, INF));
	for (int u = 0; u < n; ++u)
	{
		int u_t = type[u];
		for(std::pair<int, int> p : adj[u])
		{
			int w = p.second;
			int v_t = type[p.first];
			if(grid[u_t][v_t] > w)
				grid[u_t][v_t] = w;
		}
	}

	//Floyd Warshall
	for (int K = 0; K < k; ++K)
	{
		grid[K][K] = 0;
		for (int i = 0; i < k; ++i)
		{
			for (int j = 0; j < k; ++j)
			{
				if(grid[i][j] > grid[i][K] + grid[K][j])
					grid[i][j] = grid[i][K] + grid[K][j];
			}
		}
	}
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			if(grid[i][j] == INF)
				grid[i][j] = -1;
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
}