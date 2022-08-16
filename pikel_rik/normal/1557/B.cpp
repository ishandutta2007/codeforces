#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		map<int, int> pos;
		for (int i = 0; i < n; i++) {
			pos[a[i]] = i;
		}

		sort(a.begin(), a.end());

		int ans = 1;
		for (int i = 1; i < n; i++) {
			if (pos[a[i - 1]] + 1 != pos[a[i]]) {
				ans += 1;
			}
		}
		cout << (ans <= k ? "YES" : "NO") << '\n';
	}
	return 0;
}