#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> grid(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}

		vector<vector<int>> pref_min(n, vector<int>(m)), suf_min(n, vector<int>(m));
		vector<vector<int>> pref_max(n, vector<int>(m)), suf_max(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			partial_sum(grid[i].begin(), grid[i].end(), pref_min[i].begin(), [](int x, int y) { return x < y ? x : y; });
			partial_sum(grid[i].begin(), grid[i].end(), pref_max[i].begin(), [](int x, int y) { return x > y ? x : y; });
			partial_sum(grid[i].rbegin(), grid[i].rend(), suf_min[i].rbegin(), [](int x, int y) { return x < y ? x : y; });
			partial_sum(grid[i].rbegin(), grid[i].rend(), suf_max[i].rbegin(), [](int x, int y) { return x > y ? x : y; });
		}

		bool found = false;
		string coloring(n, 'B');

		vector<int> ind(n), suf(n);
		vector<pair<int, int>> left(n), right(n);

		int k;
		for (k = 0; k + 1 < m; k++) {
			for (int i = 0; i < n; i++) {
				left[i] = make_pair(pref_min[i][k], pref_max[i][k]);
				right[i] = make_pair(suf_min[i][k + 1], suf_max[i][k + 1]);
			}

			iota(ind.begin(), ind.end(), 0);
			sort(ind.begin(), ind.end(), [&](int i1, int i2) {
				return left[i1].second > left[i2].second;
			});

			for (int i = 0; i < n; i++) {
				suf[i] = right[ind[i]].first;
			}
			partial_sum(suf.rbegin(), suf.rend(), suf.rbegin(), [](int x, int y) { return x < y ? x : y; });

			int mn = INT_MAX, mx = INT_MIN;
			for (int i = 0; i + 1 < n; i++) {
				mn = min(mn, left[ind[i]].first);
				mx = max(mx, right[ind[i]].second);
				coloring[ind[i]] = 'R';
				if (left[ind[i + 1]].second < mn && mx < suf[i + 1]) {
					found = true;
					break;
				}
			}
			if (found) {
				break;
			}
			fill(coloring.begin(), coloring.end(), 'B');
		}

		if (!found) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			cout << coloring << ' ';
			cout << k + 1 << '\n';
		}
	}
	return 0;
}