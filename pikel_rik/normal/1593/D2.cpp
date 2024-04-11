#include <bits/stdc++.h>
using namespace std;

template<typename T>
std::vector<T> divisors(T n) {
	std::vector<T> divisors;
	for (int i = 1; (T) i * i <= n; i++) {
		if (n % i == 0) {
			divisors.push_back(i);
			if (i != n / i) {
				divisors.push_back(n / i);
			}
		}
	}
	return divisors;
}

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

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (2 * count(a.begin(), a.end(), a[i]) >= n) {
				ans = -1;
				break;
			}
			for (int j = i + 1; j < n; j++) {
				int diff = abs(a[i] - a[j]);
				auto div = divisors(diff);
				for (int d : div) {
					int c = 0;
					for (int k = 0; k < n; k++) {
						if (abs(a[i] - a[k]) % d == 0) {
							c += 1;
						}
					}
					if (2 * c >= n) {
						ans = max(ans, d);
					}
				}
			}
		}

		cout << ans << '\n';
	}
	return 0;
}