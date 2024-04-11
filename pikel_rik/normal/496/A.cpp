#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int ans = a.back() - a.front();
    for (int i = 1; i < n - 1; i++) {
        int mx = 0;
        for (int j = 1; j < n; j++) {
            if (j == i + 1) {
                mx = max(mx, a[j] - a[j - 2]);
            } else mx = max(mx, a[j] - a[j - 1]);
        }
        ans = min(ans, mx);
    }
    cout << ans << '\n';
	return 0;
}