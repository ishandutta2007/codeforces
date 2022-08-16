#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, x, y;
		cin >> n >> x >> y;

		vector<int> ans(n, -1), b(n);
		for (int i = 0; i < n; i++) cin >> b[i], --b[i];

		vector<vector<int>> pos(n + 1);
		for (int i = 0; i < n; i++) {
			pos[b[i]].push_back(i);
		}

		int extra = find_if(pos.begin(), pos.end(), [&](const auto &v) { return v.empty(); }) - pos.begin();

		priority_queue<pair<int, int>> pq;
		for (int i = 0; i <= n; i++) {
			pq.emplace(pos[i].size(), i);
		}

		for (int i = 0; i < x; i++) {
			auto [sz, j] = pq.top();
			pq.pop();
			ans[pos[j][sz - 1]] = j;
			pos[j].pop_back();
			pq.emplace(sz - 1, j);
		}

		vector<int> ind;
		for (int i = 0; i < n; i++) {
			if (ans[i] == -1) {
				ind.push_back(i);
			}
		}

		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return b[i] < b[j];
		});

		int mx = 0;
		for (int i = 0; i <= n; i++) {
			mx = max(mx, (int) pos[i].size());
		}

		vector<int> r_ind = ind;
		rotate(r_ind.begin(), r_ind.begin() + mx, r_ind.end());

		int must_do = y - x;
		for (int i = 0; i < (int) ind.size(); i++) {
			if (b[ind[i]] != b[r_ind[i]]) {
				ans[ind[i]] = b[r_ind[i]];
				must_do -= 1;
			} else {
				ans[ind[i]] = extra;
			}
		}

		if (must_do > 0) {
			cout << "NO\n";
			continue;
		}

		for (int i = 0; must_do != 0 && i < (int) ind.size(); i++) {
			if (b[ind[i]] != b[r_ind[i]]) {
				ans[ind[i]] = extra;
				must_do += 1;
			}
		}

		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			cout << ans[i] + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}