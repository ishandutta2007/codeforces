#include <bits/stdc++.h>

using namespace std; // I don't like this anyway...

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> c(n);
		vector<vector<int>> vec(n);
		for (int i = 0; i < n; ++i) {
			cin >> c[i];
			--c[i];
			vec[c[i]].push_back(i);
		}
		for (int i = 0; i < n; ++i) {
			int ans = 0, lst = -1;
			for (int x : vec[i]) {
				if (lst == -1 || (x & 1) != (lst & 1)) {
					++ans;
					lst = x;
				}
			}
			cout << ans << ' ';
		}
		cout << '\n';
	}
}