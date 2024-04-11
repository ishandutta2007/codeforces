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

		vector<int> a(n);
		for (auto &x : a) cin >> x, --x;

		vector<int> transition(n);
		for (int i = 0; i < n; i++) {
			transition[i] = i - a[i];
		}

		vector<int> lis(n);
		for (int i = 0; i < n; i++) {
			if (transition[i] < 0) {
				continue;
			}
			lis[i] = 1;
			for (int j = 0; j < i; j++) {
				if (transition[j] <= transition[i] && transition[i] - transition[j] <= i - j - 1) {
					lis[i] = max(lis[i], 1 + lis[j]);
				}
			}
		}

		int mn = -1;
		for (int i = 0; i < n; i++) {
			if (transition[i] < 0) {
				continue;
			}
			if (lis[i] >= k && (mn == -1 || transition[i] < mn)) {
				mn = transition[i];
			}
		}
		cout << mn << '\n';
	}
	return 0;
}