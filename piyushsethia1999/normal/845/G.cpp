#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

class DSU
{
public:
	int *parent;
	int *val;
	int n;
	std::vector<std::vector<int> > vv;
	DSU(int n) : n(n) { parent = new int[n]; val = new int[n]; for (int i = 0; i < n; ++i) parent[i] = -1, val[i] = 0; vv.resize(n, std::vector<int> (28, -1)); };
	int root(int x);
	void merge(int x, int y, int w);
	bool areInSame(int x, int y);
	int minn(int u, int v);
	~DSU();
};

int DSU::root(int x) {
	if (parent[x] < 0) return x;
	int rr = root(parent[x]);
	val[x] ^= val[parent[x]];
	return (parent[x] = rr); 
}

void DSU::merge(int x, int y, int w)	
{
	int x_r = root(x);
	int y_r = root(y);
	if (x_r == y_r) {
		w ^= (val[x] ^ val[y]);
		for (int i = 27; i >= 0; --i) {
			if ((1 << i) & w) {
				if (vv[x_r][i] == -1) {
					vv[x_r][i] = w;
					return;
				} else {
					w ^= vv[x_r][i];
				}
			} 
		}
		return;
	}
	if (parent[x_r] > parent[y_r]) swap(x_r, y_r), swap(x, y);
	val[y_r] = (val[y] ^ w ^ val[x]);
	parent[x_r] += parent[y_r];
	parent[y_r] = x_r;
	for (int i = 27; i >= 0; --i) {
		w = vv[y_r][i];
		if (w == -1) continue; 
		for (int j = i; j >= 0; --j) {
			if ((1 << j) & w) {
				if (vv[x_r][j] == -1) {
					vv[x_r][j] = w;
					break;
				} else {
					w ^= vv[x_r][j];
				}
			}	
		}
	}
}

int DSU::minn(int u, int v) {
	root(u);
	int r = root(v);
	int w = val[u] ^ val[v];
	for (int i = 28; i >= 0; --i)
		if ((w & (1 << i)) && (vv[r][i] != -1)) 
			w ^= vv[r][i];
	return w;
}

DSU::~DSU()
{
	delete parent;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	DSU d(n);
	for (int i = 0; i < m; ++i) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		int w; cin >> w;
		d.merge(u, v, w);
	}
	cout << d.minn(0, n - 1);	
}