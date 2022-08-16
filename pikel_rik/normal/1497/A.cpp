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

		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (a[j] == i) {
					swap(a[i], a[j]);
					break;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			cout << a[i] << " \n"[i + 1 == n];
		}
	}
	return 0;
}