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

		int zeroes = 0;
		vector<int> cnt(30);

		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				zeroes += 1;
			} else {
				for (int j = 0; j < 30; j++) {
					if (a[i] >> j & 1) {
						cnt[j] += 1;
					}
				}
			}
		}

		int g = 0;
		for (int j = 0; j < 30; j++) {
			g = gcd(g, cnt[j]);
		}

		if (g == 0) {
			for (int i = 1; i <= n; i++) {
				cout << i << ' ';
			}
			cout << '\n';
		} else {
			auto ans = divisors(g);
			sort(ans.begin(), ans.end());
			for (int k : ans) {
				cout << k << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}