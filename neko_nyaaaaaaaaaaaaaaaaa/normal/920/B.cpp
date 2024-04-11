#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first >> a[i].second;
		}
		int ans = 1;
		for (int i = 0; i < n; i++) {
			while (a[i].first > ans) {
				ans++;
			}
			if (a[i].second >= ans) {
				cout << ans << " ";
				ans++;
			} else {
				cout << 0 << " ";
				continue;
			}
		}
		cout << "\n";
	}
	
	return 0;
}