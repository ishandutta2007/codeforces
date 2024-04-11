#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, l;
        cin >> n >> l;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        int ans = 0;
        for (int j = 0; j < l; j++) {
            array<int, 2> cnt = {};
            for (auto x : a) {
                cnt[x >> j & 1] += 1;
            }
            if (cnt[0] < cnt[1]) {
                ans |= 1 << j;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}