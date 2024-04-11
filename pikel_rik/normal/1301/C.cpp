#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

ll choose(int n) {
    return ((ll)n * n + n) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        ll ans = choose(n);
        n -= m;
        int len = n / (m + 1), rem = n % (m + 1);
        ans -= rem * choose(len + 1) + (m + 1 - rem) * choose(len);
        cout << ans << '\n';
    }
    return 0;
}