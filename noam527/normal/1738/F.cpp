#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

struct dsu {
	int n;
	vector<int> p;
	dsu() {}
	dsu(int sz) {
		n = sz;
		p.resize(n);
		for (int i = 0; i < n; i++) p[i] = i;
	}
	int find(int x) {
		if (x == p[x]) return x;
		return p[x] = find(p[x]);
	}
	void unite(int from, int to) {
		from = find(from);
		to = find(to);
		p[from] = to;
	}
};

int ask(int v) {
	cout << "? " << v + 1 << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x - 1;
}

void output(const vector<int> &c) {
	cout << "! ";
	for (const auto &i : c) cout << i << " ";
	cout << endl;
	fflush(stdout);
	return;
}
void output(int n, dsu &D) {
	cout << "! ";
	for (int i = 0; i < n; i++) {
		cout << D.find(i) + 1 << " ";
	}
	cout << endl;
	fflush(stdout);
	return;
}

int n;
vector<int> d;

void solve() {
	cin >> n;
	d.resize(n);
	for (auto &i : d) cin >> i;
	vector<pair<int, int>> ord(n);
	vector<int> vis(n);
	for (int i = 0; i < n; i++) {
		ord[i] = { d[i], i };
	}
	sort(ord.rbegin(), ord.rend());
	dsu D(n);
	for (const auto &i : ord) {
		int v = i.second, deg = i.first;
		if (deg == 0) break;
		if (vis[v]) continue;
		vis[v] = 1;
		for (int j = 0; j < deg; j++) {
			int u = ask(v);
			if (vis[u] == 0) {
				D.unite(u, v);
				vis[u] = 1;
			}
			else {
				D.unite(u, v);
				break;
			}
		}
	}
	output(n, D);
}

int main() {
	//ios::sync_with_stdio(0), cin.tie(0);

	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}