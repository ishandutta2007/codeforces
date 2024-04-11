#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	long long ans = 0;
	for (int i = 0; i <= n / 2; i++) {
		ans += std::max(0, a[i] - s);
	}
	for (int i = n / 2; i < n; i++) {
		ans += std::max(0, s - a[i]);
	}
	cout << ans << endl;
}