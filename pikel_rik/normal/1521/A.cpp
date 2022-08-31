#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;

		if (b == 1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			if (b == 2) {
				b *= 2;
			}
			cout << (long long) a * (b - 1) << ' ';
			cout << (long long) a << ' ';
			cout << (long long) a * b << '\n';
		}
	}
	return 0;
}