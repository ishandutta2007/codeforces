#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, m;
vector<int> H[100005];
vector<int> deg;
ll ans = 0;

void add(int v, ll mul) {
	ans += (ll)(deg[v] - (ll)H[v].size()) * (ll)H[v].size() * mul;
}

void work(int v, int mv) {
	add(v, -1);
	H[v].push_back(mv);
	add(v, 1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	deg.resize(n, 0);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		--u, --v;
		if (u > v) swap(u, v);
		H[u].push_back(v);
		deg[u]++;
		deg[v]++;
	}
	for (int i = 0; i < n; i++)
		add(i, 1);
	cout << ans << '\n';

	int q;
	cin >> q;
	while (q--) {
		int v;
		cin >> v;
		--v;
		for (const auto &i : H[v])
			work(i, v);
		add(v, -1);
		H[v].clear();
		
		cout << ans << '\n';
	}
}