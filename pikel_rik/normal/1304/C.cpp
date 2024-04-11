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

    int q;
    cin >> q;

    while (q--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, pair<int, int>>> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second.first >> a[i].second.second;

        int extra = 0, ll = m, rr = m, last = 0;

        bool ok = true;
        for (int i = 0; i < n; i++) {
            int t = a[i].first, l = a[i].second.first, h = a[i].second.second;
            int available = t - last;
            last = t;

            ll -= available;
            rr += available;

            if (rr < l or ll > h) {
                ok = false;
                break;
            }

            if (ll < l)
                ll = l;
            if (rr > h)
                rr = h;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}