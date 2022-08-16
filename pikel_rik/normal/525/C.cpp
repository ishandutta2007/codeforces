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
const int N = 1e5 + 5;

int n, a[N];

bool cnt(int i) {
    int c = 1;
    if (i > 0 and a[i-1] == a[i]) c += 1;
    if (i + 1 < n and a[i+1] == a[i]) c += 1;

    return (c >= 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    for (int i = n - 1; i >= 0; i--) {
        if (i > 0 and a[i-1] == a[i]) {
            i -= 1;
            continue;
        }

        if (i > 0 and a[i-1] == a[i] - 1) {
            a[i] -= 1;
            i -= 1;
        }
    }

    ll ans = 0;
    int best = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i > 0 and a[i-1] == a[i] and best == 0) {
            best = a[i];
            i -= 1;
        }
        else if (i > 0 and a[i-1] == a[i] and best > 0) {
            ans += best * (ll)a[i];
            i -= 1;
            best = 0;
        }
    }

    cout << ans << "\n";
    return 0;
}