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

		vector<int> a(n + 1), b(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

		vector<int> tm(n + 1);
		for (int i = 1; i <= n; i++) cin >> tm[i];

		int current_time = 0;
		for (int i = 1; i <= n; i++) {
			current_time += a[i] - b[i - 1] + tm[i];
			if (i != n) {
				current_time = max(current_time + (b[i] - a[i] + 1) / 2, b[i]);
			}
		}
		cout << current_time << '\n';
	}
	return 0;
}