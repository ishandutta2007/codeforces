#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> ans;
	int c = 0;

	for (int i = 1; i < n; i++) {
		if (__gcd(n, i) == 1) {
			ans.push_back(i);
			c += (long long)i * i % n == 1;
		}
	}
	if (n > 2 && c == 2) {
		ans.pop_back();
	}
	cout << ans.size() << '\n';
	for (auto &x : ans) cout << x << ' ';
	cout << '\n';
	return 0;
}