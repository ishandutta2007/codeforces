#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, x;
		cin >> n >> x;

		vector<pair<int, long long>> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = 1;
		}

		long long sum = 0;
		bool stop = false;
		for (int i = 0; i < int(a.size()); i++) {
			sum += (long long)a[i].first * a[i].second;
			if (a[i].first % x == 0 && !stop) {
				a.emplace_back(a[i].first / x, a[i].second * x);
			} else stop = true;
		}
		cout << sum << '\n';
	}
	return 0;
}