#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 1;

int n, a[N], cnt[25];

int f(int x) {
    if (x == 0)
        return 0;
    if (x % 2)
        return 1 + f(x / 2);
    return f(x / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cnt[f(a[i])];
        cnt[f(a[i])] += 1;
    }

    cout << ans << "\n";
    return 0;
}