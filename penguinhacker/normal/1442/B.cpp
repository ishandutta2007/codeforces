#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD = 998244353;
int n, k, a[200000], pos[200000], taken[200000];

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i], --a[i];
		pos[a[i]] = i;
		taken[i] = -1;
	}
	for (int i = 0; i < k; ++i) {
		int b; cin >> b, b = pos[b - 1];
		taken[b] = i;
	}
	int ans = 1;
	for (int i = 0; i < n; ++i) if (taken[i] != -1) {
		int cur = i > 0 && (taken[i - 1] == -1 || taken[i - 1] < taken[i]);
		cur += i + 1 < n && (taken[i + 1] == -1 || taken[i + 1] < taken[i]);
		ans = ans * cur % MOD;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}