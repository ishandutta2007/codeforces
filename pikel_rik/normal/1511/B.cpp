#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto ten = [&](int n) -> int {
		int pw = 1;
		for (int i = 0; i < n; i++) {
			pw *= 10;
		}
		return pw;
	};

	int t;
	cin >> t;

	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;

		a = ten(a - 1), b = ten(b - 1), c = ten(c - 1);

		while (__gcd(a, b) != c) {
			a += c;
		}

		cout << a << ' ' << b << '\n';
	}
	return 0;
}