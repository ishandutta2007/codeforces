#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, m; cin >> n >> m;
	map<int, vector<int>> ids;
	for (int i = 0; i < n*m; i++) {
		int x; cin >> x;
		ids[x].push_back(i);
	}
	
	vector<vector<int>> ans(n, vector<int>(m));
	int i = 0, j = 0;
	for (auto [u, v]: ids) {
		reverse(v.begin(), v.end());
		while (v.size()) {
			int slots = v.size();
			if (m-j < v.size()) {
				slots = m-j;
			}

			// take out smallest indices
			vector<int> vs;
			for (int i = 0; i < slots; i++) {
				vs.push_back(v.back());
				v.pop_back();
			}

			// arrange them largest first
			while (vs.size()) {
				ans[i][j] = vs.back(); 
				vs.pop_back();
				j++;
				if (j == m) {
					i++; j = 0;
				}
			}
		}
	}

	int res = 0;
	for (auto v: ans) {
		for (int i = 0; i < m; i++) {
			for (int j = i+1; j < m; j++) {
				if (v[i] < v[j]) res++;
			}
		}
	}
	cout << res << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}