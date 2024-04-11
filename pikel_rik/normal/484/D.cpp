#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7, inf = INT_MAX;
const double pi = acos(-1.0);
const int N = 1e6 + 5;

int n, a[N];
ll dp[N][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> temp = {0};
	for (int i = 1; i < n - 1; i++) {
		if (a[i] >= a[i - 1] and a[i] >= a[i + 1]) {
			temp.push_back(i);
		} else if (a[i] <= a[i - 1] and a[i] <= a[i + 1]) {
			temp.push_back(i);
		}
	}
	if (n != 1) {
		temp.push_back(n - 1);
	}

	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i < temp.size(); i++) {
		dp[i][1] = max(abs(a[temp[i]] - a[temp[i - 1]]) + dp[i - 1][0], abs(a[temp[i]] - a[temp[i - 1] + 1]) + dp[i - 1][1]);
		dp[i][0] = abs(a[temp[i] - 1] - a[temp[i - 1]]) + dp[i - 1][0];
		if (temp[i] != temp[i - 1] + 1) {
			dp[i][0] = max(dp[i][0], abs(a[temp[i] - 1] - a[temp[i - 1] + 1]) + dp[i - 1][1]);
		} else {
			dp[i][0] = max(dp[i][0], dp[i - 1][1]);
		}
	}
	cout << dp[(int)temp.size() - 1][1] << '\n';
	return 0;
}