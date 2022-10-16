#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {1, 0};
vector<int> dy = {0, 1};

int n, m, found; 
vector<string> s;

int dfs(int i, int j) {
	if (i == n-1 && j == m-1) {
		found = 1;
	}
	if (found) return 1;
	s[i][j] = '#';

	int res = 0;
	for (int k = 0; k < 2; k++) {
		if (found) return 1;

		int ii = i + dx[k];
		int jj = j + dy[k];

		if (ii >= 0 && ii < n && jj >= 0 && jj < m && s[ii][jj] == '.') {
			res |= dfs(ii, jj);
		} 
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	s.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	// if not 1, must be 2
	// dfs to find any path from (1, 1) to (n, m)
	if (!dfs(0, 0)) {
		cout << 0; return 0;
	}
	found = 0;
	if (!dfs(0, 0)) {
		cout << 1; return 0;
	}
	cout << 2;

	return 0;
}