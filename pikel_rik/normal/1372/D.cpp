#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, a[N];
ll pref[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
        pref[i] = a[i - 1];

    for (int i = 2; i <= n; i++) {
        pref[i] += pref[i - 2];
    }

    ll best = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            best = max(best, pref[i + 1] + pref[n - 1] - pref[i]);
        else best = max(best, pref[i + 1] + pref[n] - pref[i]);
    }

    cout << best << "\n";
    return 0;
}