#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 5e5 + 5;

int n, m, k, c[N];
vector<int> g[N], groups[N];
vector<pair<int, int>> c_edges[N];
vector<pair<int, int>> cross_edges[N];

int p[N], col[N];
bool visited[N], bip[N];

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

void dfs(int x, int cc) {
	visited[x] = true;
	col[x] = cc;
	for (int i : g[x]) {
		if (!visited[i] && c[i] == c[x]) {
			p[i] = x;
			dfs(i, cc ^ 1);
		}
	}
}

int p1[N], flip[N];

int find1(int x) {
	if (x != p1[x]) {
		int temp = find1(p1[x]);
		flip[x] ^= flip[p1[x]];
		p1[x] = temp;
	}
	return p1[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	iota(p, p + N, 0);
	iota(p1, p1 + N, 0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		groups[c[i]].push_back(i);
	}

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		if (c[u] == c[v]) {
			c_edges[c[u]].emplace_back(u, v);
		} else {
			cross_edges[c[u]].emplace_back(u, v);
			cross_edges[c[v]].emplace_back(v, u);
		}
	}

	int total_bip = 0;
	for (int i = 1; i <= k; i++) {
		for (int x : groups[i]) {
			if (!visited[x]) {
				dfs(x, 0);
			}
		}
		bip[i] = true;
		for (auto &[u, v] : c_edges[i]) {
			bip[i] &= col[u] != col[v];
		}
		total_bip += bip[i];
	}

	ll ans = 0;

	for (int i = 1; i <= k; i++) {
		if (!bip[i]) continue;
		map<int, vector<pair<int, int>>> mp;
		for (auto &[u, v] : cross_edges[i]) {
			if (!bip[c[v]]) continue;
			mp[c[v]].emplace_back(u, v);
		}

		for (auto &item : mp) {
			bool ok = true;
			for (auto &[u, v] : item.second) {
				int uu = find(u), vv = find(v);
				find1(uu);
				find1(vv);
				if (p1[uu] != p1[vv]) {
					if ((col[u] ^ flip[uu]) == (col[v] ^ flip[vv])) {
						flip[p1[vv]] ^= 1;
					}
					p1[p1[vv]] = p1[uu];
				} else {
					ok &= (col[u] ^ flip[uu]) != (col[v] ^ flip[vv]);
				}
			}
			for (auto &[u, v] : item.second) {
				int uu = find(u), vv = find(v);
				p1[uu] = uu;
				p1[vv] = vv;
				flip[uu] = flip[vv] = 0;
			}
			ans += ok;
		}
		ans += total_bip - (int)mp.size() - 1;
	}
	ans /= 2;
	cout << ans << '\n';
	return 0;
}