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
        int s;
        cin >> s;

        ll ans = 0;
        while (s >= 10) {
            ans += (s - s % 10);
            s = s % 10 + (s - s % 10) / 10;
        }
        ans += s;
        cout << ans << "\n";
    }
    return 0;
}