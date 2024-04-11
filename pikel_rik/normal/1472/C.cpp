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

		vector<long long> a(n);
		for (auto &x : a) cin >> x;

		for (int i = n - 2; i >= 0; i--) {
			if (i + a[i] < n) {
				a[i] += a[i + a[i]];
			}
		}

		cout << *max_element(a.begin(), a.end()) << '\n';
	}
	return 0;
}