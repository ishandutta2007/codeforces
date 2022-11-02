
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
#include <bitset>
#include <unordered_map>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef pair<ld, pii> pp;

struct DisjointSet {
	int fcnt;
	vector<int> f, sz;
	DisjointSet(int size) {
		f.resize(size);
		sz.resize(size);
		fcnt = size;
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
		fcnt--;
		sz[fa] = max(sz[fa], sz[fb] + 1);
		return true;
	}
};


const int sz = 3e5;
vector<pii> adj[sz];
int n, m;
vector<pair<int, pii>> e;

void input() {
	cin >> n >> m;
	foru(i, 0, m) {
		int a, b, x;
		cin >> a >> b >> x;
		adj[--a].pb({ --b,x });
		adj[b].pb({ a,x });
		e.pb({ x,{a,b} });
	}
}

vector<vector<pii>> init() {
	vector<vector<pii>> ve;
	vector<pii> tmpv;
	foru(i, 0, m) {
		if (!i || e[i].first == e[i - 1].first)tmpv.pb(e[i].second);
		else {
			ve.pb(tmpv);
			tmpv.clear();
			tmpv.pb(e[i].second);
		}
	}
	ve.pb(tmpv);
	return ve;
}

int main() {
	fast;
	input();
	DisjointSet dsu(n);
	sort(e.begin(), e.end());
	vector<vector<pii>> ve = init();
	int ves = ve.size();
	vector<int> valid(ves, 0), used(ves, 0);
	foru(i, 0, ves) {
		for (pii x : ve[i])valid[i] += (dsu.father(x.first) != dsu.father(x.second));
		for (pii x : ve[i])used[i] += dsu.unite(x.first, x.second);
	}
	int tot = 0;
	foru(i, 0, ves)tot += (valid[i] - used[i]);
	cout << tot << endl;
	return 0;
}