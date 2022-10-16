#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	set<int> distinct;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (i != j) distinct.insert(a[i][j]);
		}
	}

	vector<int> sal(n), par(n);
	for (int i = 0; i < n; i++) {
		sal[i] = a[i][i];
		par[i] = i;
	}
	set<pair<int, int>> edges;
	int petr = n;

	vector<vector<int>> b(n, vector<int>(n));
	for (int val: distinct) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				b[i][j] = (i == j || a[i][j] <= val); 
			}
		}

		vector<int> groups(n, -1);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (groups[i] != -1) continue;
			for (int j = i; j < n; j++) {
				if (b[i][j]) groups[j] = cnt;
			}
			cnt++;
		}

		vector<set<int>> group(cnt);
		for (int i = 0; i < n; i++) {
			vector<int> aylmao;
			int cur = i;
			while (par[cur] != cur) {
				aylmao.push_back(cur);
				cur = par[cur];
			}
			for (int j: aylmao) {
				par[j] = cur;
			}

			group[groups[i]].insert(par[i]);
		}

		for (int i = 0; i < cnt; i++) {
			if (group[i].size() <= 1) continue;

			sal.push_back(val);
			par.push_back(petr);
			for (int j: group[i]) {
				edges.insert({j, petr});
				par[j] = petr;
			}

			petr++;
		}
	}

	cout << sal.size() << '\n';
	for (int i: sal) cout << i << ' ';
		cout << '\n';
	
	cout << sal.size() << '\n';
	for (auto [u, v]: edges) {
		cout << u+1 << ' ' << v+1 << '\n';
	}

	return 0;
}