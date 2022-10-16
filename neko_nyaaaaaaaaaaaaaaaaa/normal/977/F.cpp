#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	int n, ans = 0, num;
	cin >> n;
	vector<int> a(n+1), dp(n+1);
	map<int, int> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		if (m[a[i] - 1] == 0) {
			dp[i] = 1;
			m[a[i]] = i;
		} else {
			dp[i] = dp[m[a[i] - 1]] + 1;
			m[a[i]] = i;
		}

		if (dp[i] > ans) {
			ans = dp[i];
			num = a[i];
		}
	}
	cout << endl;

	cout << ans << '\n';
	int pt = num - ans + 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == pt) {cout << i << " "; pt++;}
	}

	return 0;
}