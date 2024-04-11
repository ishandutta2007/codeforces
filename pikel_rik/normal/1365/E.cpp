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
const int N = 500 + 5;

int n;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll best = 0;
    for (int i = 0; i < n; i++) {
        best = max(best, a[i]);
        for (int j = i + 1; j < n; j++) {
            best = max(best, a[i] | a[j]);
            for (int k = j + 1; k < n; k++) {
                best = max(best, a[i] | a[j] | a[k]);
            }
        }
    }

    cout << best << "\n";
    return 0;
}