#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, dp[N], pref[N];

int f(int k) {
	return (k * k - k) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 3; i <= n; i++) {
		vector<int> vals;
		for (int k = 2; k <= min(i, 500); k++) {
			if (i > f(k) && (i - f(k)) % k == 0) {
				int a = (i - f(k)) / k;
				vals.push_back(pref[a + k - 1] ^ pref[a - 1]);
			}
		}

		sort(vals.begin(), vals.end());
		vals.erase(unique(vals.begin(), vals.end()), vals.end());
		dp[i] = -1;

		for (int j = 0; j < vals.size(); j++) {
			if (vals[j] != j) {
				dp[i] = j;
				break;
			}
		}
		if (dp[i] == -1) {
			dp[i] = vals.size();
		}
		pref[i] = dp[i] ^ pref[i - 1];
	}

	int ans = -1;
	for (int k = 2; k <= min(n, 500); k++) {
		if (n > f(k) && (n - f(k)) % k == 0) {
			int a = (n - f(k)) / k;
			if ((pref[a + k - 1] ^ pref[a - 1]) == 0) {
				ans = k;
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}