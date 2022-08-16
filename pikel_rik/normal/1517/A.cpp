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

		if (n % 2050 != 0) {
			cout << "-1\n";
		} else {
			n /= 2050;

			int sod = 0;
			for (; n; n /= 10) {
				sod += n % 10;
			}
			cout << sod << '\n';
		}
	}
	return 0;
}