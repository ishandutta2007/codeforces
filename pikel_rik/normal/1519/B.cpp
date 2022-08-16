#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		int cost = (m - 1) + (n - 1) * m;
		cout << (cost == k ? "YES" : "NO") << '\n';
	}
	return 0;
}