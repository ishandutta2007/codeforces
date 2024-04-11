#include <bits/stdc++.h>

using namespace std; // I don't like this anyway...

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 1; i < n - 1; ++i) {
			b[i] = max(a[i - 1], a[i + 1]) - a[i] + 1;
			b[i] = max(b[i], 0);
		}
		if (n & 1) {
			long long ans = 0;
			for (int i = 1; i + 1 < n; i += 2)
				ans += b[i];
			cout << ans << '\n';
		}	
		else {
			long long ans = 0;
			for (int i = 2; i + 1 < n; i += 2) 
				ans += b[i];
			long long sum = ans;
			for (int i = 2; i + 1 < n; i += 2) {
				sum -= b[i];
				sum += b[i - 1];
				ans = min(ans, sum);
			}
			cout << ans << '\n';
		}
	}
}