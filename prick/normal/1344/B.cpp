#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

void fail() {
	cout << "-1\n";
	exit(0);
}

void dfs(int r, int c, const vector<vector<char>>& black, vector<vector<char>>& used) {
	if (r < 0 || r >= sz(black)) return;
	if (c < 0 || c >= sz(black[0])) return;
	if (used[r][c]) return;
	if (!black[r][c]) return;
	used[r][c] = true;
	dfs(r + 1, c, black, used);
	dfs(r - 1, c, black, used);
	dfs(r, c + 1, black, used);
	dfs(r, c - 1, black, used);
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<vector<char>> black(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == '#') {
				black[i][j] = true;
			}
		}
	}
	
	vector<int> row(n), col(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (black[i][j]) {
				++row[i];
				++col[j];
			}
		}
	}
	
	if (*min_element(row.begin(), row.end()) > 0 &&
		*min_element(col.begin(), col.end()) == 0
	) {
		fail();
	}
	if (*min_element(row.begin(), row.end()) == 0 &&
		*min_element(col.begin(), col.end()) > 0
	) {
		fail();
	}
	for (int i = 0; i < n; ++i) {
		bool was = false;
		bool prev = false;
		for (int j = 0; j < m; ++j) {
			if (black[i][j]) {
				if (was && !prev) {
					fail();
				}
				was = true;
				prev = true;
			} else {
				prev = false;
			}
		}
	}
	for (int j = 0; j < m; ++j) {
		bool was = false;
		bool prev = false;
		for (int i = 0; i < n; ++i) {
			if (black[i][j]) {
				if (was && !prev) {
					fail();
				}
				was = true;
				prev = true;
			} else {
				prev = false;
			}
		}
	}
	
	int ans = 0;
	vector<vector<char>> used(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (black[i][j] && !used[i][j]) {
				++ans;
				dfs(i, j, black, used);
			}
		}
	}
	cout << ans << '\n';
}