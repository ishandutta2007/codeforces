#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
		cin >> a[i];
    }

    int ans = n;
    for (int prefix = 0; prefix < n; prefix++) {
		set<int> p;
		int valid = 1;
		for (int i = 0; i < prefix; i++) {
			if (p.find(a[i]) != p.end()) {valid = 0; break;}
			p.insert(a[i]);
		}
        if (!valid) break;
		ans = min(ans, n - prefix);

        for (int i = n-1; i >= 0; i--) {
            if (p.find(a[i]) != p.end()) break;
            ans = min(ans, i - prefix);
            p.insert(a[i]);
        }
    }
    cout << ans;

    return 0;
}