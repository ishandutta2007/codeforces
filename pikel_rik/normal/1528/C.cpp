#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> pa(n);
		vector<vector<int>> ga(n);

		for (int i = 1; i < n; i++) {
			cin >> pa[i];
			ga[--pa[i]].push_back(i);
		}

		vector<int> pb(n);
		vector<vector<int>> gb(n);
		for (int i = 1; i < n; i++) {
			cin >> pb[i];
			gb[--pb[i]].push_back(i);
		}

		int timer = 0;
		vector<int> tin(n), tout(n);

		auto dfsb = [&](int x, int p, const auto &self) -> void {
			tin[x] = timer++;
			for (int i : gb[x]) {
				self(i, x, self);
			}
			tout[x] = timer++;
		};

		dfsb(0, -1, dfsb);

		int ans = 1;

		set<pair<int, int>> s;
		auto dfsa = [&](int x, int p, const auto &self) -> void {
			auto it = s.upper_bound(make_pair(tin[x], tout[x]));
			pair<int, int> added(-1, -1), deleted(-1, -1);
			if (it == s.begin()) {
				added = make_pair(tin[x], tout[x]);
				s.insert(added);
			} else {
				it--;
				if (it->first <= tin[x] && tout[x] <= it->second) {
					added = make_pair(tin[x], tout[x]);
					deleted = *it;
					s.erase(it), s.insert(added);
				} else if (it->second < tin[x]) {
					added = make_pair(tin[x], tout[x]);
					s.insert(added);
				}
			}
			ans = max(ans, (int)s.size());
			for (int i : ga[x]) {
				self(i, x, self);
			}
			if (added.first != -1) {
				s.erase(added);
			}
			if (deleted.first != -1) {
				s.insert(deleted);
			}
		};

		dfsa(0, -1, dfsa);
		cout << ans << '\n';
	}
	return 0;
}