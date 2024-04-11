#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		int c = count(a.begin(), a.end(), 0), sum = accumulate(a.begin(), a.end(), 0);

		int ans = c;
		ans += sum + c == 0;
		cout << ans << '\n';
	}
	return 0;
}