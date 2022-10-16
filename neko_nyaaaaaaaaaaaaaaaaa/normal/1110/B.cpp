#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n), b;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		b.push_back(a[i] - a[i-1] - 1);
	}
	sort(b.begin(), b.end());
	//cout << b << endl;
	int ans = n;

    int pie = n;
    for (int i = 0; pie > k; pie--, i++) {
		ans += b[i];
    }
    cout << ans;

	return 0;
}