#include <bits/stdc++.h>
using namespace std;

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);

	constexpr int N = 200000;

	vector<vector<int>> div(N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			div[j].push_back(i);
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n), color(n);
		for (auto &x : a) cin >> x, --x;

		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return a[i] < a[j];
		});

		vector<int> cnt(n);
		for (int i = 0; i < n; i++) {
			cnt[a[i]] += 1;
		}

		int take = 0;
		for (int i = 0; i < n; i++) {
			cnt[i] = min(cnt[i], k);
			take += cnt[i];
		}

		take -= take % k;

		int cur_color = 1;
		for (int i = 0; i < n && take > 0; i++) {
			int j = ind[i];
			if (cnt[a[j]] > 0) {
				color[j] = cur_color;
				cur_color = 1 + cur_color % k;
				cnt[a[j]] -= 1, take -= 1;
			}
		}

		for (int i = 0; i < n; i++) {
			cout << color[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}