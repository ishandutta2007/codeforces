#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long n, m;
		cin >> n >> m;

		long long ans = (n - n % 3) * m / 3;
		ans += (n %= 3) * (m - m % 3) / 3;
		m %= 3;

		if (n * m == 1 || n * m == 2) {
			ans += 1;
		} else if (n * m == 4) {
			ans += 2;
		}
		cout << ans << '\n';
	}
	return 0;
}