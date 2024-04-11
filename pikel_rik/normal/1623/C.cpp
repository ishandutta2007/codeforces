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
        for (auto &x : a) cin >> x;

        vector<int> add(n);
        auto f = [&](int x) -> bool {
            fill(add.begin(), add.end(), 0);
            for (int i = n - 1; i > 1; i--) {
                int d = min(a[i] / 3, (a[i] + add[i] - x) / 3);
                add[i - 1] += d;
                add[i - 2] += 2 * d;
            }

            bool ok = true;
            for (int i = 0; i < n; i++) {
                ok &= a[i] + add[i] >= x;
            }
            return ok;
        };

        int lo = 1, hi = (int) 1e9;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (f(mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        cout << lo << '\n';
    }
    return 0;
}