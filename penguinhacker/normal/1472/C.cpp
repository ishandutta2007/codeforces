#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> a(n); for (int& i : a) cin >> i;
		vector<ll> dp(n);
		for (int i = n - 1; i >= 0; --i) {
			dp[i] = a[i];
			if (i + a[i] < n) dp[i] += dp[i + a[i]];
		}
		cout << *max_element(dp.begin(), dp.end()) << "\n";
	}
	return 0;
}