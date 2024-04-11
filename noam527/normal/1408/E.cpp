#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

struct dsu {
	int n;
	vector<int> p, r;
	dsu() {}
	dsu(int sz) {
		n = sz;
		p.resize(n);
		r.resize(n, 0);
		for (int i = 0; i < n; i++) p[i] = i;
	}
	int find(int x) {
		return x == p[x] ? x : p[x] = find(p[x]);
	}
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		if (r[x] < r[y]) p[x] = y;
		else {
			p[y] = x;
			if (r[x] == r[y]) r[x]++;
		}
		return true;
	}
};

struct edge {
	int u, v;
	ll w;
	edge() {}
	edge(int uu, int vv, ll ww) {
		u = uu;
		v = vv;
		w = ww;
	}
	bool operator < (const edge &a) const {
		return w > a.w;
	}
};

int n, m;
vector<int> a; // size m;
vector<int> b; // size n;
vector<edge> e;
dsu D;

void solve() {
	cin >> m >> n;
	D = dsu(n + m);
	a.resize(m);
	b.resize(n);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	for (int i = 0; i < m; i++) {
		int sz;
		cin >> sz;
		while (sz--) {
			int x;
			cin >> x;
			x--;
			e.push_back(edge(x, i + n, a[i] + b[x]));
		}
	}
	sort(e.begin(), e.end());
	ll sum = 0;
	for (const auto &i : e) {
		if (!D.unite(i.u, i.v))
			sum += i.w;
	}
	cout << sum << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
//	cin >> tst;
	while (tst--) solve();
}