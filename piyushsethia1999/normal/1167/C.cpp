#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair


using namespace std;
class DSU
{
public:
	int *parent;
	int n;
	DSU(int n) : n(n) { parent = new int[n]; for (int i = 0; i < n; ++i) parent[i] = -1; };
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
}

bool DSU::areInSame(int x, int y) { return (root(x) == root(y)); }

DSU::~DSU()
{
	delete parent;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	DSU d(n);
	int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		int k; cin >> k;
		int u = -1;
		for (int i = 0; i < k; ++i) {
			int p; cin >> p; p--;
			if (u != -1) {
				d.merge(p, u);
			} 
			u = p;
		}
	} 
	for (int i = 0; i < n; ++i) {
		cout << -d.parent[d.root(i)] << " ";
	}
}