/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

struct edge {
	int from, to, id;
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<vector<edge>> edges(n);
	for (int i = 0; i + 1 < n; i++) {
		int from, to;
		cin >> from >> to;
		--from;
		--to;
		edges[from].push_back({from, to, i});
		edges[to].push_back({to, from, i});
	}
	vector<int> ans(n - 1, -1);
	int cc = 0;
	for (int i = 0; i < n; i++) {
		if (edges[i].size() > 2) {
			ans[edges[i][0].id] = cc++;
			ans[edges[i][1].id] = cc++;
			ans[edges[i][2].id] = cc++;
			break;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (ans[i] < 0) {
			ans[i] = cc++;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		cout << ans[i] << '\n';
	}
}