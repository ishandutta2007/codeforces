#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<vector<int>> ans(n, vector<int>(n, -1));
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j <= (n - 1) / 2; ++j) {
				int k = (i + j) % n;
				ans[i][k] = 1;
				ans[k][i] = -1;
			}
		}
		if (n % 2 == 0) {
			for (int i = 0; i < n; ++i) {
				int j = (i + n / 2) % n;
				ans[i][j] = ans[j][i] = 0;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				cout << ans[i][j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}