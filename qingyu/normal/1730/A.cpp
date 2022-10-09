#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	for (int Case = 1; Case <= T; ++Case) {
		int n, c;
		cin >> n >> c;
		vector<int> a(n), b(101);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			++b[a[i]];
		}
		int ans = 0;
		for (int i = 1; i <= 100; ++i)
			ans += min(b[i], c);
		cout << ans << '\n';
	}
}