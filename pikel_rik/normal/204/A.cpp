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

vector<int> num;
ll dp[19][2][2][10][10];

ll recurse(int pos, int f1, int f2, int first, int last) {
    if (pos == num.size())
        return first == last and f2;

    if (dp[pos][f1][f2][first][last] != -1)
        return dp[pos][f1][f2][first][last];

    int limit = 9;
    if (!f1) limit = num[pos];

    ll ans = 0;
    for (int i = 0; i <= limit; i++) {
        if (!f2 and !i)
            ans += recurse(pos + 1, (i < num[pos] ? 1 : f1), f2, first, last);
        if (!f2 and i)
            ans += recurse(pos + 1, (i < num[pos] ? 1 : f1), 1, i, (pos == num.size() - 1 ? i : last));
        if (f2)
            ans += recurse(pos + 1, (i < num[pos] ? 1 : f1), 1, first, (pos == num.size() - 1 ? i : last));

    }
    return dp[pos][f1][f2][first][last] = ans;
}

ll solve(ll x) {
    num.clear();

    while (x) {
        num.push_back(x % 10);
        x /= 10;
    }

    reverse(all(num));

    memset(dp, -1, sizeof(dp));
    return recurse(0, 0, 0, 0, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll a, b;
    cin >> a >> b;

    cout << solve(b) - solve(a - 1) << "\n";
    return 0;
}