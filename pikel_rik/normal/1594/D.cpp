#include <bits/stdc++.h>
using namespace std;

struct union_find {
	int n, c;
	std::vector<int> p;
	std::vector<std::vector<int>> v;

	union_find(): n(), c() {}
	union_find(int n): n(n), c(n), p(n), v(n) {
		for (int i = 0; i < n; i++) {
			p[i] = i, v[i] = {i};
		}
	}

	int count() const noexcept {
		return c;
	}

	int find(int x) {
		return p[x];
	}

	bool merge(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);
		if (s1 == s2) {
			return false;
		}
		if (v[s2].size() > v[s1].size()) {
			std::swap(s1, s2);
		}
		for (int i : v[s2]) {
			v[s1].push_back(i);
			p[i] = s1;
		}
		v[s2].clear();
		c -= 1;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<tuple<int, int, int>> comments(m);
		for (auto &[x, y, c] : comments) {
			string s;
			cin >> x >> y >> s, --x, --y;
			c = (s == "imposter");
		}

		vector<vector<int>> g(n);
		for (int i = 0; i < m; i++) {
			auto [x, y, c] = comments[i];
			g[x].push_back(i);
			g[y].push_back(i);
		}

		vector<int> role1(n, -1), role2(n, -1);

		bool possible = true;
		for (int s = 0; s < n; s++) {
			if (role1[s] != -1) {
				continue;
			}

			vector<int> component;
			auto dfs = [&](int u, const auto &self) -> void {
				component.push_back(u);
				for (int i : g[u]) {
					auto [x, y, c] = comments[i];
					int v = x ^ y ^ u;
					if (role1[v] == -1) {
						role1[v] = role1[u] ^ c;
						role2[v] = role2[u] ^ c;
						self(v, self);
					}
				}
			};

			role1[s] = 0, role2[s] = 1;
			dfs(s, dfs);

			int cnt1 = 0, cnt2 = 0;
			for (int u : component) {
				cnt1 += role1[u];
				cnt2 += role2[u];
				for (int i : g[u]) {
					auto [x, y, c] = comments[i];
					if (role1[x] ^ role1[y] ^ c) {
						cnt1 = -3 * n;
					}
					if (role2[x] ^ role2[y] ^ c) {
						cnt2 = -3 * n;
					}
				}
			}

			possible &= cnt1 >= 0 || cnt2 >= 0;
			if (cnt1 < cnt2) {
				for (int u : component) {
					swap(role1[u], role2[u]);
				}
			}
		}

		if (possible) {
			cout << count(role1.begin(), role1.end(), 1) << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
	return 0;
}