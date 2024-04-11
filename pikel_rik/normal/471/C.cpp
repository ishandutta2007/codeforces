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

ll tri(int n) {
    return (n * (ll)(n + 1)) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n;
    cin >> n;

    int start;
    if (n % 3 == 1)
        start = 2;
    else if (n % 3 == 0)
        start = 3;
    else start = 1;

    int c = 0;
    for (int i = start;; i += 3) {
        ll left = n - (2 * tri(i) - 2) - tri(i - 1);
        if (left > 0)
            c += 1;
        else break;
    }

    cout << c << "\n";
    return 0;
}