#include <bits/stdc++.h>
using namespace std;

template<typename T>
bool is_prime(T x) {
	if (x == 1) {
		return false;
	}
	for (int i = 2; (T) i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
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

		int sum = accumulate(a.begin(), a.end(), 0);
		if (is_prime(sum)) {
			cout << n - 1 << '\n';
			auto it = find_if(a.begin(), a.end(), [](int x) { return x % 2; }) - a.begin();
			for (int i = 0; i < n; i++) {
				if (it != i) {
					cout << i + 1 << ' ';
				}
			}
		} else {
			cout << n << '\n';
			for (int i = 1; i <= n; i++) {
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}