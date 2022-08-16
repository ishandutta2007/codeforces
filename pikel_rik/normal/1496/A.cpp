#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		bool possible = false;
		for (int i = k; 2 * i < n; i++) {
			bool ok = true;
			for (int j = 0; j < i; j++) {
				ok &= s[j] == s[n - j - 1];
			}
			possible |= ok;
		}
		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}