#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

ll pref[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pref[1] = 1;
    for (ll i = 2, j = 3; i <= 31; i++, j = 2 * j + 1) {
        pref[i] = (j * j + j) / 2 + pref[i - 1];
    }

    int t;
    cin >> t;

    while (t--) {
        ll x;
        cin >> x;

        int i;
        for (i = 1; i <= 31; i++) {
            if (pref[i + 1] > x) {
                break;
            }
        }
        cout << i << '\n';
    }
    return 0;
}