#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> p(n);
		for (auto &x : p) cin >> x, --x;

		vector<int> fixed(n);
		for (int i = 0; i < n; i++) {
			int time = 0;
			if (p[i] < i) {
				time = i - p[i];
			} else if (p[i] > i) {
				time = n - p[i] + i;
			}
			fixed[time] += 1;
		}

		vector<int> ans;
		for (int k = 0; k < n; k++) {
			if ((n - fixed[k] + 1) / 2 > m) {
				continue;
			}
			vector<int> rotated(n);
			iota(rotated.begin() + k, rotated.end(), 0);
			iota(rotated.begin(), rotated.begin() + k, n - k);

			vector<int> pos(n);
			for (int i = 0; i < n; i++) {
				pos[rotated[i]] = i;
			}

			vector<bool> visited(n);

			int cycles = 0;
			for (int i = 0; i < n; i++) {
				if (visited[i]) {
					continue;
				}
				cycles += 1;
				for (int j = i; !visited[j]; j = pos[p[j]]) {
					visited[j] = true;
				}
			}

			if (n - cycles <= m) {
				ans.push_back(k);
			}
		}

		cout << ans.size() << ' ';
		for (auto &k : ans) cout << k << ' ' ;
		cout << '\n';
	}
	return 0;
}