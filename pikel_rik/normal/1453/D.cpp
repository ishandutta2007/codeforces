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

	vector<ull> E = {0, 2};
	for (; E.back() < (ull)1e18;) {
		E.push_back((E.back() + 1) << 1);
	}

	int t;
	cin >> t;

	while (t--) {
		ll k;
		cin >> k;

		if (k % 2 != 0) {
			cout << "-1\n";
			continue;
		}

		vector<int> ans;
		for (int i = int(E.size()) - 1; i >= 1; i--) {
			ull times = k / E[i];
			k %= E[i];
			while (times--) {
				ans.push_back(1);
				for (int j = 1; j < i; j++) ans.push_back(0);
			}
		}

		cout << ans.size() << '\n';
		for (int i : ans) cout << i << ' '; cout << '\n';
	}
	return 0;
}