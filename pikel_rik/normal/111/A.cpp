#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n, x, y;
    cin >> n >> x >> y;

    if (n > y) {
        cout << "-1\n";
        return 0;
    }

    vector<int> ans(n, 1);

    ll sum = n, sq = n;
    while (sum < y and x > sq) {
        sum += 1;
        sq += 2 * ans[0] + 1;
        ans[0] += 1;
    }

    if (sum <= y and sq >= x) {
        for (int i : ans) cout << i << "\n";
        return 0;
    }
    cout << "-1\n";
    return 0;
}