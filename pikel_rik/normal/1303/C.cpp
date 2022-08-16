#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int n = int(s.length());
		vector<vector<int>> adj(26, vector<int>(26));

		for (int i = 1; i < n; i++) {
			adj[s[i] - 'a'][s[i - 1] - 'a'] = 1;
			adj[s[i - 1] - 'a'][s[i] - 'a'] = 1;
		}

		bool ok = true;
		for (int i = 0; i < 26; i++) {
			ok &= accumulate(adj[i].begin(), adj[i].end(), 0) <= 2;
		}

		if (!ok) {
			cout << "NO\n";
			continue;
		}

		string ans;
		vector<bool> visited(26);

		auto dfs = [&](int x, const auto &dfs) -> void {
			visited[x] = true;
			ans += 'a' + x;
			for (int i = 0; i < 26; i++) {
				if (adj[x][i] && !visited[i]) {
					dfs(i, dfs);
				}
			}
		};

		for (int i = 0; i < 26; i++) {
			if (!visited[i] && accumulate(adj[i].begin(), adj[i].end(), 0) == 1) {
				dfs(i, dfs);
			}
		}

		for (int i = 0; i < 26; i++) {
			ok &= accumulate(adj[i].begin(), adj[i].end(), 0) == 0 || visited[i];
			if (!count(ans.begin(), ans.end(), 'a' + i)) {
				ans += 'a' + i;
			}
		}

		if (ok) {
			cout << "YES\n" << ans << '\n';
		} else cout << "NO\n";
	}
	return 0;
}