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

	vector<int> primes;
	for (int i = 3; i * i <= 1000 * 1000 * 1000; i++) {
		if (is_prime(i)) {
			primes.push_back(i);
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		while (k > 3) {
			cout << 1 << ' ';
			k -= 1, n -= 1;
		}

		bool done = false;
		for (int p : primes) {
			if (n % p == 0) {
				n /= p;
				cout << n * (p - 1) / 2 << ' ' << n * (p - 1) / 2 << ' ' << n << '\n';
				done = true;
				break;
			}
		}

		if (done)
			continue;

		int two = 1;
		while (n % 2 == 0) {
			two *= 2;
			n /= 2;
		}

		if (n > 1) {
			cout << two << ' ' << two * (n - 1) / 2 << ' ' << two * (n - 1) / 2 << '\n';
		} else {
			cout << two / 2 << ' ' << two / 4 << ' ' << two / 4 << '\n';
		}
	}
	return 0;
}