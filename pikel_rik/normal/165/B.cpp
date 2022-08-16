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

    int n, k;
    cin >> n >> k;

    ll lo = 1, hi = 1e9;

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;

        ll sum = 0, pow = 1, v = mid;
        while (v / pow) {
            sum += (v / pow);
            pow = pow * k;
        }

        if (sum >= n)
            hi = mid;
        else lo = mid + 1;
    }

    cout << lo << "\n";
    return 0;
}