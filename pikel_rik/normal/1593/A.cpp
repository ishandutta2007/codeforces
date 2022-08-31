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

		cout << max(max(b, c) + 1 - a, 0) << ' ';
		cout << max(max(a, c) + 1 - b, 0) << ' ';
		cout << max(max(a, b) + 1 - c, 0) << '\n';
	}
	return 0;
}