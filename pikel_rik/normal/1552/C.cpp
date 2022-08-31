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

		vector<int> x(k), y(k);
		for (int i = 0; i < k; i++) {
			cin >> x[i] >> y[i], --x[i], --y[i];
			if (x[i] > y[i]) {
				swap(x[i], y[i]);
			}
		}

		vector<bool> marked(2 * n);
		for (int i = 0; i < k; i++) {
			marked[x[i]] = marked[y[i]] = true;
		}

		vector<int> unmarked;
		for (int i = 0; i < 2 * n; i++) {
			if (!marked[i]) {
				unmarked.push_back(i);
			}
		}

		int half = (int) unmarked.size() / 2;
		for (int i = 0; i < half; i++) {
			x.push_back(unmarked[i]);
			y.push_back(unmarked[i + half]);
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (x[j] < x[i] && x[i] < y[j] && y[j] < y[i]) {
					ans += 1;
				} else if (x[i] < x[j] && x[j] < y[i] && y[i] < y[j]) {
					ans += 1;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}