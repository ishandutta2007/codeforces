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

        ll k;
        cin >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (k & 1) {
            int mx = *max_element(a.begin(), a.end());
            for (int i = 0; i < n; i++) a[i] = mx - a[i];
        }
        else {
            int mn = *min_element(a.begin(), a.end());
            for (int i = 0; i < n; i++) a[i] = a[i] - mn;
        }

        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << '\n';
    }
    return 0;
}