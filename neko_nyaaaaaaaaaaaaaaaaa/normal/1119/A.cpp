#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> c(n);
	for (auto &i: c) cin >> i;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] != c[0]) {
			ans = max(ans, abs(i - 0));
		}
		if (c[i] != c[n-1]) {
			ans = max(ans, abs(i - (n-1)));
		}
	}
	cout << ans;

	return 0;
}