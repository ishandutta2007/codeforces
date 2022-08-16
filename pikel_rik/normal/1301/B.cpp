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

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int mx = INT_MIN, mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                if (i > 0 and a[i - 1] != -1) {
                    mx = max(mx, a[i - 1]);
                    mn = min(mn, a[i - 1]);
                }
                if (i + 1 < n and a[i + 1] != -1) {
                    mx = max(mx, a[i + 1]);
                    mn = min(mn, a[i + 1]);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] != -1 and a[i - 1] != -1) {
                ans = max(ans, abs(a[i] - a[i - 1]));
            }
        }

        if (mx == INT_MIN) {
            if (a[0] == -1) {
                cout << "0 0\n";
            } else {
                cout << ans << 0 << '\n';
            }
        } else {
            ans = max(ans, (mx - mn + 1) / 2);
            cout << ans << ' ' << (mx + mn) / 2 << '\n';
        }
    }
    return 0;
}