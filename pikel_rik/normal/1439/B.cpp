#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, m, k, deg[N];
vector<int> g[N];
bool visited[N];

struct comp {
	bool operator()(int i, int j) const {
		return deg[i] < deg[j] || (deg[i] == deg[j] && i < j);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) g[i].clear();

		for (int i = 0, u, v; i < m; i++) {
			cin >> u >> v;
			--u; --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		for (int i = 0; i < n; i++) {
			sort(g[i].begin(), g[i].end());
			deg[i] = g[i].size();
			visited[i] = false;
		}

		set<int, comp> s;
		for (int i = 0; i < n; i++) {
			s.insert(i);
		}

		while (!s.empty() && deg[*s.begin()] < k) {
			int x = *s.begin();
			s.erase(s.begin());
			visited[x] = true;

			for (int i : g[x]) {
				if (!visited[i]) {
					s.erase(i);
					deg[i]--;
					s.insert(i);
				}
			}
		}

		if (!s.empty()) {
			cout << 1 << ' ' << s.size() << '\n';
			for (int x : s) cout << x + 1 << ' '; cout << '\n';
			continue;
		}

		for (int i = 0; i < n; i++) {
			deg[i] = g[i].size();
			visited[i] = false;
		}

		s.clear();
		for (int i = 0; i < n; i++) {
			s.insert(i);
		}

		vector<int> ans;
		while (!s.empty()) {
			int x = *s.begin();
			s.erase(s.begin());
			visited[x] = true;

			if (deg[x] < k - 1) {
				for (int i : g[x]) {
					if (!visited[i]) {
						s.erase(i);
						deg[i]--;
						s.insert(i);
					}
				}
			} else if (deg[x] == k - 1) {
				ans = {x};
				for (int i : g[x]) {
					if (!visited[i]) {
						ans.push_back(i);
					}
				}
				bool ok = true;
				for (int i = 0; i < k; i++) {
					for (int j = 0; j < i; j++) {
						ok &= binary_search(g[ans[i]].begin(), g[ans[i]].end(), ans[j]);
					}
				}
				if (!ok) {
					for (int i : g[x]) {
						if (!visited[i]) {
							s.erase(i);
							deg[i]--;
							s.insert(i);
						}
					}
					ans.clear();
				} else {
					break;
				}
			}
		}

		if (ans.empty()) {
			cout << "-1\n";
		} else {
			cout << 2 << '\n';
			for (int x : ans) cout << x + 1 << ' '; cout << '\n';
		}
	}
	return 0;
}