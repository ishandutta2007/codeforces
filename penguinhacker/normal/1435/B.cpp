#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> row(n, vector<int>(m));
		vector<vector<int>> col(m, vector<int>(n));
		vector<vector<int>> ans;
		vector<int> which(n * m + 1);
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> row[i][j], which[row[i][j]] = i;
		for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) cin >> col[i][j];
		for (int i = 0; i < n; ++i) ans.push_back(row[which[col[0][i]]]);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) cout << ans[i][j] << (j + 1 < m ? " " : "");
			cout << "\n";
		}
	}
	return 0;
}