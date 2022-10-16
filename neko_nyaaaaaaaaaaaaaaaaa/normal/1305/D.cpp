#include <bits/stdc++.h>
using namespace std;

int tmm = 0;
vector<int> adj[1001];
vector<int> in(1001);
int lca[1001][1001];
vector<pair<int, int>> edges;
vector<int> deg(1001);
vector<int> leafs;
vector<int> lv(1001);

vector<int> dfs(int now, int prev) {
	in[now] = ++tmm;
	lv[now] = lv[prev] + 1;
	if (deg[now] == 1) {
		leafs.push_back(now);
	}
	vector<int> st;

	for (int u: adj[now]) {
		if (u != prev) {
			vector<int> g = dfs(u, now);

			for (int i: st) {
				for (int j: g) {
					lca[i][j] = lca[j][i] = now;
				}
			}

			for (int i: g) st.push_back(i);
		}
	}
	for (int i: st) lca[now][i] = lca[i][now] = now;
	lca[now][now] = now;
	st.push_back(now);
	return st;
}

bool cmp(int x, int y) {
	return in[x] < in[y];
}

vector<tuple<int, int, int>> ques;

bool possible(int r) {
	// check if r is root
	//cout << "Checking " << r << endl;
	for (auto [u, v, k]: ques) {
		int x = lca[u][r];
		int y = lca[v][r];
		int z = lca[u][v];

		int ans = x;
		if (lv[y] > lv[ans]) ans = y;
		if (lv[z] > lv[ans]) ans = z;

		//cout << u << ' ' << v << ' ' << ans << endl;

		if (ans != k) {
			return 0;
		}
	}
	return 1;
}

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		edges.emplace_back(x, y);
		adj[x].push_back(y);
		adj[y].push_back(x);
		deg[x]++; deg[y]++;
	}
	if (n == 2) {
		cout << "? 1 2\n";
		int x; cin >> x;
		cout << "! " << x << endl;
		exit(0);
	}
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() > 1) {
			dfs(i, 0); break;
		}
	}
	sort(leafs.begin(), leafs.end(), cmp);

	vector<int> candidates;
	for (int i = 0, j = leafs.size()/2; j < leafs.size(); i++, j++) {
		cout << "? " << leafs[i] << ' ' << leafs[j] << endl;
		int x; cin >> x; assert(x != -1);
		ques.emplace_back(leafs[i], leafs[j], x);
		candidates.push_back(x);
	}

	for (int i: candidates) {
		if (possible(i)) {
			cout << "! " << i << endl;
			exit(0);
		}
	}

	return 0;
}