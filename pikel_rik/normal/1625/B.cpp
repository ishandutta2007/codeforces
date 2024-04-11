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

        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[a[i]].push_back(i);
        }

        if (mp.size() == n) {
            cout << "-1\n";
            continue;
        }

        int ans = 1;
        for (auto &[x, v] : mp) {
            for (int i = 1; i < (int) v.size(); i++) {
                ans = max(ans, v[i - 1] + n - v[i]);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}