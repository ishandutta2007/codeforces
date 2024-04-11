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
		int n;
		cin >> n;
		vector<string> g(n);
		for (int i = 0; i < n; ++i) {
			cin >> g[i];
		}
		vector<ar<int, 2>> ans;
		auto Add  = [&](int r, int c, int to) {
			if (g[r][c] - '0' != to) {
				ans.push_back({r + 1, c + 1});
			}
		};
		int a = g[0][1] - '0';
		int b = g[1][0] - '0';
		int c = g[n - 1][n - 2] - '0';
		int d = g[n - 2][n - 1] - '0';
		if (a != b && c != d) {
			Add(0, 1, 0);
			Add(1, 0, 0);
			Add(n - 1, n - 2, 1);
			Add(n - 2, n - 1, 1);
		}
		else if (a == b) {
			Add(n - 1, n - 2, a ^ 1);
			Add(n - 2, n - 1, a ^ 1);
		}
		else {
			assert(c == d);
			Add(0, 1, c ^ 1);
			Add(1, 0, c ^ 1);
		}
		assert(ans.size() <= 2);
		cout << ans.size() << "\n";
		for (auto x : ans) {
			cout << x[0] << " " << x[1] << "\n";
		}
	}
	return 0;
}