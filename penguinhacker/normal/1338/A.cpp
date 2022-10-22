#include <bits/stdc++.h>
using namespace std;

int n, a[100000];
void solve() {
	cin >> n;
	int ans=0, largest=-2e9;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		largest = max(largest, a[i]);
		while (largest-a[i]>=(1ll<<ans))
			ans++;
	}
	cout << ans << '\n';
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}