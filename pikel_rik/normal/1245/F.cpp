#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int l, r;
ll dp[30][2][2][2][2];

ll recurse(int pos = 29, int fl1 = 0, int fr1 = 0, int fl2 = 0, int fr2 = 0) {
    if (pos == -1)
        return 1;
    if (dp[pos][fl1][fr1][fl2][fr2] != -1)
        return dp[pos][fl1][fr1][fl2][fr2];

    int l1 = 0, r1 = 1, l2 = 0, r2 = 1;
    if (!fl1) l1 = (bool)(l & (1 << pos));
    if (!fr1) r1 = (bool)(r & (1 << pos));
    if (!fl2) l2 = (bool)(l & (1 << pos));
    if (!fr2) r2 = (bool)(r & (1 << pos));

    ll ans = 0;
    for (int i = l1; i <= r1; i++) {
        for (int j = l2; j <= r2; j++) {
            if (i & j) continue;
            ans += recurse(pos - 1,
                           i > (bool)(l & (1 << pos)) ? 1 : fl1, i < (bool)(r & (1 << pos)) ? 1 : fr1,
                           j > (bool)(l & (1 << pos)) ? 1 : fl2, j < (bool)(r & (1 << pos)) ? 1 : fr2);
        }
    }

    return dp[pos][fl1][fr1][fl2][fr2] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> l >> r;

        memset(dp, -1, sizeof(dp));
        cout << recurse() << "\n";
    }
    return 0;
}