#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int k, b, n, t;
    cin >> k >> b >> n >> t;

    int time = 0;
    ll cur = 1;

    while (cur < t) {
        cur = k * cur + b;
        time++;
    }

    if (cur == t) {
        cout << max(0, n - time) << "\n";
        return 0;
    }
    cout << max(0, n - time + 1) << "\n";
    return 0;
}