#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q, k, a[100000], pre[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 1; i < n - 1; ++i) pre[i] = pre[i - 1] + a[i + 1] - a[i - 1] - 2;
	for (int i = 0; i < q; ++i) {
		int l, r; cin >> l >> r, --l, --r;
		if (l == r) cout << k - 1 << "\n";
		else {
			int ans = a[l + 1] - 2 + k - a[r - 1] - 1;
			ans += pre[r - 1] - pre[l];
			cout << ans << "\n";
		}
	}
	return 0;
}