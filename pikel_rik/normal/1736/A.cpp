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

        vector<int> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        array<int, 2> cnt = {};
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                cnt[a[i]]++;
            }
        }

        if (min(cnt[0], cnt[1]) == 0) {
            cout << max(cnt[0], cnt[1]) << '\n';
        } else {
            cout << 1 + max(cnt[0], cnt[1]) - min(cnt[0], cnt[1]) << '\n';
        }
    }
    return 0;
}