#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, sq;
	cin >> n >> m; sq = round(ceil(sqrt(n)));

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	set<int> s;
	vector<int> lvl(n), p(n);
	vector<bool> visited(n);

	auto dfs = [&](int x, const auto &self) -> void {
		visited[x] = true;
		bool f = true;
		for (int i : g[x]) {
			if (!visited[i]) {
				p[i] = x;
				lvl[i] = 1 + lvl[x];
				self(i, self);
			} else if (lvl[x] > lvl[i] + 1 && lvl[x] - lvl[i] + 1 >= sq) {
				cout << 2 << '\n' << lvl[x] - lvl[i] + 1 << '\n';
				for (int j = x; j != p[i]; j = p[j]) {
					cout << j + 1 << ' ';
				}
				cout << '\n';
				exit(0);
			}
			f &= !s.count(i);
		}
		if (f) {
			s.insert(x);
		}
	};

	p[0] = -1;
	dfs(0, dfs);

	int c = 0;
	cout << 1 << '\n';
	for (int x : s) {
		if (++c <= sq) {
			cout << x + 1 << ' ';
		} else {
			break;
		}
	}
	cout << '\n';
	return 0;
}