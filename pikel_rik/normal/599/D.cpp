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

ll x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> x;
    vector<pair<ll, ll>> ans;

    for (ll i = 1; i <= 1.5 * 1e6; i++) {
        ll val1 = 6 * x + i * i * i - i;
        ll val2 = 3 * i * i + 3 * i;

        if (i > val1 / val2)
            break;

        if (val1 % val2 == 0)
            ans.emplace_back(i, val1 / val2);
    }

    int c = 0;
    for (auto p : ans) c += (p.first == p.second);

    cout << ans.size() * 2 - c << "\n";
    for (auto & an : ans) cout << an.first << " " << an.second << "\n";

    for (int i = ans.size() - 1; i >= 0; i--) {
        if (ans[i].first == ans[i].second)
            continue;
        cout << ans[i].second << " " << ans[i].first << "\n";
    }
    return 0;
}