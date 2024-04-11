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
        for (int& i : a) cin >> i;

        ll total = accumulate(a.begin(), a.end(), 0ll);

        ll sum = INT_MIN, best = LLONG_MIN;
        for (int i = 0; i < n - 1; i++) {
            sum = max(sum + a[i], (ll)a[i]);
            best = max(best, sum);
        }

        sum = total - a[0];
        for (int i = 1; i < n; i++) {
            best = max(best, sum);
            sum -= a[i];
        }

        if (best < total) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
    return 0;
}