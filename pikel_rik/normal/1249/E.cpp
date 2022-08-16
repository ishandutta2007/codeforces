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

	int n, c;
	cin >> n >> c;

	vector<int> a(n - 1), b(n - 1);
	for (int i = 0; i < n - 1; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) cin >> b[i];

	vector<array<int, 2>> dp(n);
	dp[1][0] = a[0];
	dp[1][1] = c + b[0];

	for (int i = 2; i < n; i++) {
		dp[i][0] = a[i - 1] + min(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = min(c + b[i - 1] + dp[i - 1][0], b[i - 1] + dp[i - 1][1]);
	}

	cout << 0 << ' ';
	for (int i = 1; i < n; i++) {
		cout << min(dp[i][0], dp[i][1]) << ' ';
	}
	cout << '\n';
	return 0;
}