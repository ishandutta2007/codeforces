#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

        sort(a.begin(), a.end(), [&] (const pair<int, int>& x, const pair<int, int>& y) {
            return x.first + x.second < y.first + y.second;
        });

        string ans;
        int curx = 0, cury = 0;

        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (curx > a[i].first or cury > a[i].second) {
                ok = false;
                break;
            }
            while (curx != a[i].first) {
                ans += 'R';
                curx++;
            }

            while (cury != a[i].second) {
                ans += 'U';
                cury++;
            }
        }

        if (ok)
            cout << "YES\n" << ans << "\n";
        else cout << "NO\n";
    }
    return 0;
}