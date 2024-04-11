#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long a, b, x;
		cin >> a >> b >> x;

		long long g = gcd(a, b);

		if (x % g != 0) {
			cout << "NO\n";
			continue;
		}

		if (a > b) {
			swap(a, b);
		}

		bool possible = false;
		while (a != 0) {
			possible |= x % a == b % a && x <= b;
			swap(a, b %= a);
		}

		possible |= x == b;
		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}