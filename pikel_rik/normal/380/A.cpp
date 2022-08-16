#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m;
	cin >> m;

	vector<pair<int, int>> ops(m + 1);
	vector<long long> lens(m + 1);

	vector<int> prefix;
	prefix.reserve(100000);

	for (int o = 1; o <= m; o++) {
		int t;
		cin >> t;

		if (t == 1) {
			int x;
			cin >> x;
			ops[o].first = x, ops[o].second = -1;
			if (prefix.size() < 100000) {
				prefix.push_back(x);
			}
			lens[o] = lens[o - 1] + 1;
		} else {
			int l, c;
			cin >> l >> c;
			ops[o].first = l, ops[o].second = c;
			lens[o] = lens[o - 1] + l * c;
			for (int i = 0; i < c && prefix.size() < 100000; i++) {
				for (int j = 0; j < l && prefix.size() < 100000; j++) {
					prefix.push_back(prefix[j]);
				}
			}
		}
	}

	int n;
	cin >> n;

	long long p;
	for (int i = 0, j = 0; i < n; i++) {
		cin >> p;
		while (p > lens[j]) {
			j += 1;
		}
		if (ops[j].second == -1) {
			cout << ops[j].first << ' ';
		} else {
			cout << prefix[(p - lens[j - 1] - 1) % ops[j].first] << ' ';
		}
	}
	cout << '\n';
	return 0;
}