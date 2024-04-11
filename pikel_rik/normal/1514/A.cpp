#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		bool possible = false;
		for (auto &x : a) {
			int sq = (int)sqrt(x);
			possible |= sq * sq != x && (sq + 1) * (sq + 1) != x;
		}
		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}