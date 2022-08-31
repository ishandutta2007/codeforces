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

		string a, b;
		cin >> a >> b;

		vector<int> equal = {0};
		int c0 = 0, c1 = 0;

		for (int i = 0; i < n; i++) {
			c0 += a[i] == '0';
			c1 += a[i] == '1';
			if (c0 == c1) {
				equal.push_back(i + 1);
			}
		}

		bool possible = true;

		for (int i = 1; i < equal.size(); i++) {
			int no_equal = 0;
			for (int j = equal[i - 1]; j < equal[i]; j++) {
				no_equal += a[j] == b[j];
			}
			possible &= no_equal == 0 || no_equal == equal[i] - equal[i - 1];
		}

		for (int i = equal.back(); i < n; i++) {
			possible &= a[i] == b[i];
		}
		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}