#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
ll c[100000];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	ll ans = n * (c[0] + c[1]), pre = c[0] + c[1];
	ll mn[2] = {c[0], c[1]};
	for (int i = 3; i <= n; ++i) {
		mn[(i - 1) % 2] = min(mn[(i - 1) % 2], c[i - 1]);
		pre += c[i - 1];
		ans = min(ans, pre + (n - (i + 1) / 2) * mn[0] + (n - i / 2) * mn[1]);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}