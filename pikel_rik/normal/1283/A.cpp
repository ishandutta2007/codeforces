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
        int h, m;
        cin >> h >> m;

        int ans = 0;
        if (m) {
            h++;
            ans += 60 - m;
            m = 0;
        }

        ans += (24 - h) * 60;
        cout << ans << '\n';
    }
    return 0;
}