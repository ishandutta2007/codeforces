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

		vector<int> h(n), w(n);
		for (int i = 0; i < n; i++) cin >> h[i] >> w[i];

		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](auto i, auto j) {
			return h[i] < h[j] || (h[i] == h[j] && w[i] < w[j]);
		});

		vector<int> temp = h;
		sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(), temp.end()), temp.end());

		vector<int> ans(n, -1), mn(n);

		int ih = 0;
		mn[0] = ind[0];
		for (int i = 1; i < n; i++) {
			if (h[ind[i]] != h[ind[i - 1]]) {
				ih += 1;
				mn[ih] = mn[ih - 1];
			}
			if (w[ind[i]] < w[mn[ih]]) {
				mn[ih] = ind[i];
			}
			if (ih != 0 && w[mn[ih - 1]] < w[ind[i]]) {
				ans[ind[i]] = mn[ih - 1];
			}
		}

		for (int i = 0; i < n; i++) {
			int iw = lower_bound(temp.begin(), temp.end(), w[ind[i]]) - temp.begin() - 1;
			if (iw >= 0 && w[mn[iw]] < h[ind[i]]) {
				ans[ind[i]] = mn[iw];
			}
		}

		for (int i : ans) {
			cout << (i == -1 ? -1 : i + 1) << ' ';
		}
		cout << '\n';
	}
	return 0;
}