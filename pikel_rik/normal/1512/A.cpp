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

		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return a[i] < a[j];
		});

		if (a[ind[1]] == a[ind[n - 1]]) {
			cout << ind[0] + 1 << '\n';
		} else {
			cout << ind[n - 1] + 1 << '\n';
		}
	}
	return 0;
}