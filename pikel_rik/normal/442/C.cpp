#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<int> b;
	b.reserve(n);

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		while (b.size() > 1 && b[b.size() - 2] >= b[b.size() - 1] && b[b.size() - 1] <= a[i]) {
			b.pop_back();
			ans += min(b.back(), a[i]);
		}
		b.push_back(a[i]);
	}

	for (int i = 1; i + 1 < b.size(); i++) {
		ans += min(b[i - 1], b[i + 1]);
	}
	cout << ans << '\n';
	return 0;
}