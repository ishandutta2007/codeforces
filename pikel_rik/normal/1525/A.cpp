#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int k;
		cin >> k;

		cout << 100 / __gcd(k, 100) << '\n';
	}
	return 0;
}