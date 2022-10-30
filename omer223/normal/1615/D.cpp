
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

struct DisjointSet {
	int fcnt;
	vi f, sz;
	DisjointSet(int size) {
		f.resize(size);
		sz.resize(size);
		fcnt = size;
		foru(i, 0, size) {
			f[i] = i;
			sz[i] = 1;
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
		fcnt--;
		sz[fa] = max(sz[fa], sz[fb] + 1);
		return true;
	}
};

//REMEMBER TO RESET WTF!!!
int n, m;
const int sz = 5e5;
vector<pair<pii, int>> e, gam;
vector<int> adj[sz];
vector<int> fcol;

void reset() {
	fcol.clear();
	e.clear(); gam.clear();
	foru(i, 0, n)adj[i].clear();
}

//todo change
int getParity(int w) {
	if (w == -1)return w;
    return (__builtin_popcount(w) & 1);
}

bool dfs(int src, int prvColor) {
	fcol[src] = !prvColor;
	for (int x : adj[src]) {
		if (fcol[x] == -1) {
			if (!dfs(x, fcol[src])) {
				return 0;
			}
		}
		else {
			if (fcol[src] == fcol[x])return 0;
		}
	}
	return 1;
}

void solve() { //emtpy question mark!
    cin >> n >> m;
	DisjointSet dsu(n);
    reset();
	fcol.assign(n, -1);
	foru(i, 0, n - 1) {
		int x, y, w;
		cin >> x >> y >> w; x--; y--;
		e.push_back({ {x,y},w });
		if (getParity(w) == 0)dsu.unite(x, y);
	}
	foru(i, 0, m) {
		int x, y, w;
		cin >> x >> y >> w;
		gam.push_back({ {--x,--y},w });
		if (w == 0)dsu.unite(x, y);
	}
	bool bad = 0;


	for (auto ii : e) {
		int x = ii.ff.ff, y = ii.ff.ss, w = getParity(ii.ss);
		if (w == 1) {
			int f1 = dsu.father(x), f2 = dsu.father(y);
			if (f1==f2) {
				bad = 1;
				break;
			}
			adj[f1].push_back(f2);
			adj[f2].push_back(f1);
		}
	}
	for (auto ii : gam) {
		int x = ii.ff.ff, y = ii.ff.ss, w = ii.ss;
		if (w == 1) {
			int f1 = dsu.father(x), f2 = dsu.father(y);
			if (f1 == f2) {
				bad = 1;
				break;
			}
			adj[f1].push_back(f2);
			adj[f2].push_back(f1);
		}
	}
	if (bad) {
		cout << "NO\n";
		return;
	}
	foru(i, 0, n) {
		if (fcol[i] == -1) {
			if (!dfs(i, 0)) {
				bad = 1;
				break;
			}
		}
	}
	if (bad) {
		cout << "NO\n";
		return;
	}
	else {
		cout << "YES\n";
		for (auto ii : e) {
			int x = ii.ff.ff, y = ii.ff.ss, w = ii.ss;
			if (w != -1)cout << x + 1 << ' ' << y + 1 << ' ' << w << '\n';
			else {
				if (fcol[dsu.father(x)] == fcol[dsu.father(y)])cout << x + 1 << ' ' << y + 1 << ' ' << 0 << '\n';
				else cout << x + 1 << ' ' << y + 1 << ' ' << 1 << '\n';
			}
		}
	}
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}