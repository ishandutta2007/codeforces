#include <bits/stdc++.h>
using namespace std;

vector<int> sort_by;

bool cmp(vector<int> &a, vector<int> &b) {
	for (int i: sort_by) {
		if (a[i] != b[i]) return a[i] < b[i];
	}
	return a.back() < b.back();
}

void check(int n, int m, vector<vector<int>> a, vector<vector<int>> b, vector<int> ans) {
	sort_by = ans;

	for (int i = 0; i < n; i++) {
		a[i].push_back(i);
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < n; i++) {
		a[i].pop_back();
	}

	if (a != b) {
		cout << "-1\n";
		exit(0);
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	vector<vector<int>> b(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	if (a == b) {
		cout << "0\n"; exit(0);
	}

	vector<int> row_avail(n, 1);
	vector<int> col_avail(m, 1);

	vector<int> bad_cnt(m);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] < b[i-1][j]) {
				bad_cnt[j]++;
			}
		}
	}

	vector<int> ans;
	while (1) {
		int col = -1;
		for (int i = 0; i < m; i++) {
			if (col_avail[i] && bad_cnt[i] == 0) {
				col = i; break;
			}
		}
		if (col == -1) break;

		col_avail[col] = 0;
		ans.push_back(col);

		for (int i = 1; i < n; i++) {
			if (row_avail[i] && b[i][col] > b[i-1][col]) {
				row_avail[i] = 0;
				for (int j = 0; j < m; j++) {
					if (b[i][j] < b[i-1][j]) {
						bad_cnt[j]--;
					}
				}
			}
		}
	}
	if (ans.empty()) {
		cout << "-1\n"; exit(0);
	}
	check(n, m, a, b, ans);

	reverse(ans.begin(), ans.end());	
	cout << ans.size() << '\n';
	for (int i: ans) cout << i+1 << ' ';

	return 0;
}