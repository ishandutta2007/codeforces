#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;

		long long sum = a + 2ll * b + 3ll * c;
		cout << sum % 2 << '\n';
	}
	return 0;
}