#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        sort(a.begin(), a.end());

        long long ans = accumulate(a.begin(), a.begin() + n - 2 * k, 0ll);
        for (int i = n - 2 * k; i < n - k; i++) {
            ans += a[i] / a[i + k];
        }
        cout << ans << '\n';
    }
    return 0;
}