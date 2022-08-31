#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long u, v;
		cin >> u >> v;

		cout << u * u << ' ' << -v * v << '\n';
	}
	return 0;
}