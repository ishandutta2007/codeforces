#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

class DSU
{
public:
	int *parent;
	int *ming;
	int n;
	DSU(int n) : n(n) { parent = new int[n]; ming = new int[n]; for (int i = 0; i < n; ++i) parent[i] = -1; };
	int root(int x);
	void merge(int x, int y);
	bool areInSame(int x, int y);
	~DSU();
};

int DSU::root(int x) { return (parent[x] < 0 ? x : (parent[x] = root(parent[x]))); }

void DSU::merge(int x, int y)
{
	if ((x = root(x)) == (y = root(y))) return;
	if (parent[x] > parent[y]) swap(x, y);
	parent[x] += parent[y];
	parent[y] = x;
	ming[x] = min(ming[x], ming[y]);
}

bool DSU::areInSame(int x, int y) { return (root(x) == root(y)); }

DSU::~DSU()
{
	delete parent;
	delete ming;
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int m; cin >> m;
	DSU d(n);
	for (int i = 0; i < n; ++i) cin >> d.ming[i];
	for (int i = 0; i < m; ++i) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		d.merge(u, v);
	}
	std::vector<bool> vis(n, false);
	int mm = 0;
	for (int i = 0; i < n; ++i) {
		if (!vis[d.root(i)]) 
			mm += d.ming[d.root(i)], vis[d.root(i)] = true;
	}
	cout << mm;
}