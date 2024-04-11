#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		if (k == 1) {
			cout << (count(a.begin(), a.end(), a[0]) == n ? 1 : -1) << "\n";
			continue;
		}
		int cnt = 0;
		for (int i = 1; i < n; ++i) {
			if (a[i] != a[i - 1]) {
				++cnt;
			}
		}
		int ans = (cnt + k - 2) / (k - 1);
		if (ans == 0) {
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}