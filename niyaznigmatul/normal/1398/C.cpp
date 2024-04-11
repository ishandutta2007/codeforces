#include <bits/stdc++.h>

/**
 * Author: Niyaz Nigmatullin
 */

using namespace std;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int SHIFT = n;
	vector<int> c(9 * n + 1);
	int sum = 0;
	c[sum + SHIFT]++;
	long long ans = 0;
	for (char ch : s) {
		sum += (int) ch - '0' - 1;
		ans += c[sum + SHIFT];
		c[sum + SHIFT]++;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
}