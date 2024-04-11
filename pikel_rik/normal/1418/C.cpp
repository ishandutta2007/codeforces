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

        int length = 0;
        for (int i = 0; i < n && a[i]; i++) { length = i + 1; }

        int ans = (length + 2) / 3;

        int cur = 0;
        for (int i = length + 1; i < n; i++) {
            if (a[i]) {
                cur++;
            } else {
                ans += cur / 3;
                cur = 0;
            }
        }

        ans += cur / 3;
        cout << ans << '\n';
    }
    return 0;
}