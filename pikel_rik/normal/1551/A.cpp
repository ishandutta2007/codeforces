#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		cout << (n / 3) + (n % 3 == 1) << ' ' << (n / 3) + (n % 3 == 2) << '\n';
	}
	return 0;
}