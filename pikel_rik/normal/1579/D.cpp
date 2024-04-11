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

		priority_queue<pair<int, int>> pq;
		for (int i = 0; i < n; i++) {
			if (a[i] > 0) {
				pq.emplace(a[i], i);
			}
		}

		vector<pair<int, int>> talks;
		while (pq.size() > 1) {
			int i = pq.top().second; pq.pop();
			int j = pq.top().second; pq.pop();

			talks.emplace_back(i, j);

			if (--a[i] > 0) {
				pq.emplace(a[i], i);
			}
			if (--a[j] > 0) {
				pq.emplace(a[j], j);
			}
		}

		cout << talks.size() << '\n';
		for (auto &[i, j] : talks) {
			cout << i + 1 << ' ' << j + 1 << '\n';
		}
	}
	return 0;
}