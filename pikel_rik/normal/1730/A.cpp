#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        map<int, int> mp;
        for (auto &x : a) {
            mp[x] += 1;
        }

        int ans = 0;
        for (auto &[x, cnt] : mp) {
            if (cnt <= c) {
                ans += cnt;
            } else {
                ans += c;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}