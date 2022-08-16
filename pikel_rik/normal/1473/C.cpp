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

		vector<int> p(k + 1);
		iota(p.begin(), p.end(), 0);
		reverse(p.begin() + k - (n - k), p.end());
		for (int i = 1; i <= k; i++) cout << p[i] << ' '; cout << '\n';
	}
	return 0;
}