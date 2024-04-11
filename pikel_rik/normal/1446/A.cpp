#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n; ll W;
		cin >> n >> W;

		vector<int> w(n);
		for (int i = 0; i < n; i++) cin >> w[i];

		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 0);

		sort(ind.begin(), ind.end(), [&] (int i, int j) {
			return w[i] < w[j];
		});

		int there = -1;
		for (int i = 0; i < n; i++) {
			if ((W + 1) / 2 <= w[ind[i]] && w[ind[i]] <= W) {
				there = ind[i];
				break;
			}
		}

		ll cur = 0;
		vector<int> ans;

		for (int i = 0; i < n; i++) {
			if (cur + w[ind[i]] <= W) {
				cur += w[ind[i]];
				ans.push_back(ind[i]);
			}
		}

		if (there != -1 || ((W + 1) / 2 <= cur && cur <= W)) {
			if (there != -1) {
				cout << 1 << '\n' << there + 1 << '\n';
			} else {
				cout << ans.size() << '\n';
				for (int j : ans) cout << j + 1 << ' ';
				cout << '\n';
			}
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}