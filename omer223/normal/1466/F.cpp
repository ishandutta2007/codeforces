#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>

using namespace std;
struct DisjointSet {
	vector<int> f, sz;
	DisjointSet(int size) {
		f.resize(size);
		sz.resize(size);
		foru(i, 0, size) {
			f[i] = i;
			sz[i] = i;
		}
	}
	int father(int src) {
		if (src == f[src])return src;
		return f[src] = father(f[src]);
	}
	bool unite(int a, int b) {
		int fa = father(a), fb = father(b);
		if (sz[fa] < sz[fb])swap(fa, fb);
		if (fa == fb)return false;
		f[fb] = fa;
		sz[fa] = max(sz[fa], sz[fb] + 1);
		return true;
	}
};
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 5e5;
int n, m;
bitset<sz> used, unit;
vector<pii> adj[sz];

void dfs(int src) {
	unit[src] = 1;
	for (pii x : adj[src]) {
		if (!unit[x.first])dfs(x.first);
	}
}


int main() {
	fast;
	cin >> n >> m;
	DisjointSet dsu(m + 3);
	foru(i, 0, n) {
		int x, a, b = m + 2;
		cin >> x >> a;
		if (x == 2)cin >> b;
		if (dsu.unite(a, b))used[i] = 1;
	}
	ll tot = 1, cnt = used.count();
	foru(i, 0, cnt) {
		tot <<= 1;
		tot %= ((ll)(1e9 + 7));
	}
	cout << tot << ' ' << cnt << '\n';
	foru(i, 0, n) {
		if (used[i])cout << i  + 1<< ' ';
	}
	cout << '\n';
	return 0;
}