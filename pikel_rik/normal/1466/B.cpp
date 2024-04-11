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

		vector<int> a(n), cnt(2 * n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[--a[i]]++;
		}

		vector<bool> visited(2 * n + 1);
		for (int i = 0; i < 2 * n; i++) {
			if (cnt[i] == 1) {
				if (visited[i]) {
					visited[i + 1] = true;
				} else {
					visited[i] = true;
				}
			} else if (cnt[i] > 1) {
				visited[i] = visited[i + 1] = true;
			}
		}
		cout << count(visited.begin(), visited.end(), true) << '\n';
	}
	return 0;
}