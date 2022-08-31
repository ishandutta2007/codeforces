#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long n;
		cin >> n;

		while (n % 2 == 0) n /= 2;

		cout << (n != 1 ? "YES" : "NO") << '\n';
	}
	return 0;
}