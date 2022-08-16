#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	auto choose3 = [](long long n) -> long long {
		return (n * (n - 1) * (n - 2)) / 6;
	};

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i], --a[i], --b[i];
		}

		vector<int> cnt_a(n), cnt_b(n);
		for (int i = 0; i < n; i++) {
			cnt_a[a[i]] += 1;
			cnt_b[b[i]] += 1;
		}

		long long ans = choose3(n);
		for (int i = 0; i < n; i++) {
			ans -= (long long)(cnt_a[a[i]] - 1) * (cnt_b[b[i]] - 1);
		}

		cout << ans << '\n';
	}
	return 0;
}