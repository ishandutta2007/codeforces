#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<char>> c(502, vector<char>(502));
vector<vector<int>> v(502, vector<int>(502, 1));
vector<int> x, y;

void dfs(int i, int j) {
	v[i][j] = 1;
	if (!v[i-1][j]) dfs(i-1, j);
	if (!v[i+1][j]) dfs(i+1, j);
	if (!v[i][j-1]) dfs(i, j-1);
	if (!v[i][j+1]) dfs(i, j+1);
	
	x.push_back(i);
	y.push_back(j);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
			v[i][j] = (c[i][j] == '#');
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (v[i][j]) continue;
			dfs(i, j);
		}
	}
	
	for (int i = 0; i < k; i++) {
		c[x[i]][y[i]] = 'X';
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << c[i][j];
		}
		cout << '\n';
	}
	
	return 0;
}