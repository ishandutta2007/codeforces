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
const int N = 1e5 + 5;

int n, a[N], cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;

        int mx = 0, dist = 0, c = 0;
        for (int i = 1; i <= n; i++) {
            mx = max(mx, cnt[i]);
            dist += (cnt[i] > 0);
        }

        for (int i = 1; i <= n; i++) {
            c += (cnt[i] == mx);
        }

        int lo = 0, hi = dist - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (mid * (ll)(mx - 1) + mx + c - 1 <= n)
                lo = mid;
            else hi = mid - 1;
        }

        cout << lo << "\n";
    }
    return 0;
}