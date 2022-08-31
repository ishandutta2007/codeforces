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

        vector<pair<int, int>> a(n);
        for (auto &[l, r] : a) {
            cin >> l >> r;
        }

        sort(a.begin(), a.end());

        for (auto [l, r] : a) {
            int ans = -1;
            for (int d = l; d <= r; d++) {
                bool yes = true;
                yes &= d - 1 < l || binary_search(a.begin(), a.end(), make_pair(l, d - 1));
                yes &= d + 1 > r || binary_search(a.begin(), a.end(), make_pair(d + 1, r));
                if (yes) {
                    ans = d;
                }
            }
            assert(ans != -1);
            cout << l << ' ' << r << ' ' << ans << '\n';
        }
    }
    return 0;
}