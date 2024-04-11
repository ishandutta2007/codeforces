#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<vector<int>> a(2*n, vector<int>(2*n));
	for (auto &v: a) for (int &x: v) cin >> x;

	vector<int> xs = {0,n-1,n,2*n-1};
	long long res = 2e9;
	for (int x: xs) for (int y: xs) {
		if ((x < n) == (y < n)) continue;
		res = min(res, (long long) a[x][y]);
	}
	for (int i = n; i < 2*n; i++) {
		for (int j = n; j < 2*n; j++) {
			res += a[i][j];
		}
	}
	cout << res << '\n';	
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}