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

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		vector<int> pref(n); pref[0] = a[0];
		for (int i = 1; i < n; i++) {
			pref[i] = min(a[i] - i, pref[i - 1]);
		}

		vector<int> suf(n); suf[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			suf[i] = min(a[i] - (n - 1 - i), suf[i + 1]);
		}

		bool possible = false;
		for (int i = 0; i < n; i++) {
			if (a[i] >= max(i, n - i - 1)) {
				bool ok = true;
				ok &= i == 0 || pref[i - 1] >= 0;
				ok &= i + 1 == n || suf[i + 1] >= 0;
				possible |= ok;
			}
		}
		cout << (possible ? "Yes" : "No") << '\n';
	}
	return 0;
}