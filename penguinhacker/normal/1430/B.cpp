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
		sort(a.rbegin(), a.rend());
		ll ans = accumulate(a.begin(), a.begin() + k + 1, 0ll);
		cout << ans << "\n";
	}
	return 0;
}