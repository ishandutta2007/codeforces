#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<int> pref(a.begin(), a.end());
	for (int i = 1; i < n; i++) pref[i] |= pref[i - 1];

	vector<int> suf(a.begin(), a.end());
	for (int i = n - 2; i >= 0; i--) suf[i] |= suf[i + 1];

	int best = -1, best_value = -1;
	for (int i = 0; i < n; i++) {
		int value = (i > 0 ? pref[i - 1] : 0) | (i + 1 < n ? suf[i + 1] : 0);
		if ((a[i] & ~value) > best_value) {
			best_value = a[i] & ~value;
			best = i;
		}
	}
	cout << a[best] << ' ';
	for (int i = 0; i < n; i++) {
		if (i != best) {
			cout << a[i] << ' ';
		}
	}
	cout << '\n';
	return 0;
}