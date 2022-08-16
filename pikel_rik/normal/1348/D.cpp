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
		int n;
		cin >> n;

		vector<int> ans = {1};

		int cur = 1, sum = 1;

		while (sum + 2 * cur <= n) {
			ans.push_back(2 * cur);
			cur += cur;
			sum += cur;
		}

		if (n - sum) {
			ans.push_back(n - sum);
		}

		sort(ans.begin(), ans.end());

		cout << ans.size() - 1 << '\n';
		for (int i = 1; i < ans.size(); i++) cout << ans[i] - ans[i - 1] << ' '; cout << '\n';
	}
	return 0;
}