#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	if (n < 6) {
		cout << "-1\n";
	} else {
		cout << 1 << ' ' << 2 << '\n';
		for (int i = 3; i <= n / 2 + 1; i++) {
			cout << 2 << ' ' << i << '\n';
		}
		for (int i = n / 2 + 2; i <= n; i++) {
			cout << 1 << ' ' << i << '\n';
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << 1 << ' ' << i << '\n';
	}
	return 0;
}