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
		int d;
		cin >> d;

		long long ans1 = 1, ans2 = 1;
		for (int i = d + 1;; i++) {
			if (is_prime(i)) {
				ans1 *= i;
				if (ans1 != i)
					break;
				else {
					ans2 = (long long)i * i * i * i;
					i += d - 1;
				}
			}
		}
		cout << min(ans1, ans2) << '\n';
	}
	return 0;
}