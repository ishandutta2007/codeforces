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

int n, m;
ll pref[N];
pair<int, int> a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;

        sort(a, a + m, greater<>());
        for (int i = 1; i <= m; i++)
            pref[i] = pref[i - 1] + a[i - 1].first;

        ll best = 0;
        for (int i = 0; i < m; i++) {
            ll now = 0;
            int lo = 0, hi = min(n, m) - 1;

            while (lo < hi) {
                int mid = lo + (hi - lo + 1) / 2;
                if (a[mid].first >= a[i].second)
                    lo = mid;
                else hi = mid - 1;
            }

            if (lo == 0 and a[lo].first < a[i].second)
                now = a[i].first + (n - 1) * (ll)a[i].second;
            else if (i <= lo)
                now = pref[lo + 1] + (n - lo - 1) * (ll)a[i].second;
            else if (lo + 2 > n)
                now = a[i].first + pref[lo] + (n - lo - 1) * (ll)a[i].second;
            else now = a[i].first + pref[lo + 1] + (n - lo - 2) * (ll)a[i].second;
            best = max(best, now);
        }

        cout << best << "\n";
    }
    return 0;
}