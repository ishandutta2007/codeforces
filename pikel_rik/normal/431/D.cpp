#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

ll m, k;
ll dp[65][65][2];

vector<int> num;

ll recurse(int pos = 0, int ones = 0, int f = 0) {
    if (pos == num.size()) {
        if (ones == k)
            return 1;
        return 0;
    }

    if (dp[pos][ones][f] != -1)
        return dp[pos][ones][f];

    int limit;
    if (!f) limit = num[pos];
    else limit = 1;

    ll ans = 0;
    for (int i = 0; i <= limit; i++) {
        if (i == 0)
            ans += recurse(pos + 1, ones, (i < num[pos] ? 1 : f));
        else ans += recurse(pos + 1, ones + 1, f);
    }

    return dp[pos][ones][f] = ans;
}

void init() {
    for (int i = 0; i < 65; i++) {
        for (int j = 0; j < 65; j++) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
}

ll f(ll n) {
    num.clear();
    while (n) {
        num.push_back(n % 2);
        n /= 2;
    }

    reverse(all(num));

    init();

    ll ans = recurse();
    num.push_back(0);

    init();
    ans = recurse() - ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> m >> k;

    ll lo = 1, hi = 1e18;

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (f(mid) < m)
            lo = mid + 1;
        else hi = mid;
    }

    cout << lo << "\n";
    return 0;
}