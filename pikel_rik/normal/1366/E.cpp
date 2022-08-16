#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 998244353;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, m, a[N], b[N], pos[N], last[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    int cur = inf, ptr = m;
    ll ans = 1;

    for (int i = n; i >= 1 && ptr; i--) { //12,10,20,20,25,30
        cur = min(cur, a[i]);     // 10,20,30
        if (cur >= b[ptr]) {
            if (cur == b[ptr] and !pos[ptr])
                pos[ptr] = i;
        }
        else {
            ans = ans * (pos[ptr] - i) % mod;
            if (!pos[ptr]) {
                cout << "0\n";
                return 0;
            }
            ptr--;
            if (cur == b[ptr])
                pos[ptr] = i;
        }
    }

    if (ptr != 1 or !pos[1]) {
        cout << "0\n";
        return 0;
    }
    cout << ans << "\n";
    return 0;
}