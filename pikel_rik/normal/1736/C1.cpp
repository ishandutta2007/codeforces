#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i], a[i] -= i;
        }

        long long ans = 0;
        for (int l = 0, r = 0; l < n; l++) {
            while (r + 1 < n && a[r + 1] >= 1 - l) {
                r += 1;
            }
            ans += r - l + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}