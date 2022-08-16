#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	auto sod = [&](long long x) -> int {
		int sum = 0;
		for (; x; x /= 10) {
			sum += x % 10;
		}
		return sum;
	};

	while (t--) {
		long long n;
		cin >> n;

		while (__gcd(n, (long long)sod(n)) == 1) {
			n += 1;
		}

		cout << n << '\n';
	}
	return 0;
}