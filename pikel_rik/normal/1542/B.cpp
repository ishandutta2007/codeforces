#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;

		if (a == 1) {
			cout << ((n - 1) % b == 0 ? "Yes" : "No") << '\n';
		} else {
			bool possible = false;
			for (long long pw = 1; pw <= n; pw *= a) {
				possible |= (n - pw) % b == 0;
			}
			cout << (possible ? "Yes" : "No") << '\n';
		}
	}
	return 0;
}