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
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int m = min_element(a.begin(), a.end()) - a.begin(), ans = 0;
        for (int i = 0; i < n; i++) {
            if (i != m) {
                ans += (k - a[i]) / a[m];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}