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
const int N = 2e5 + 5;

int n, a[N], pref[N][201];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        for (int j = 1; j <= 200; j++)
            pref[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 200; j++) {
                pref[i][j] = pref[i - 1][j];
            }
            pref[i][a[i]]++;
        }

        int best = *max_element(pref[n] + 1, pref[n] + 201);
        for (int i = 1; i <= n; i++) {
            if (2 * pref[i][a[i]] > pref[n][a[i]]) continue;
            int lo = 1, hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo + 1) / 2;
                if (pref[n][a[i]] - pref[mid][a[i]] >= pref[i][a[i]])
                    lo = mid;
                else hi = mid - 1;
            }

            for (int j = 1; j <= 200; j++) {
                if (j == a[i]) continue;
                best = max(best, 2 * pref[i][a[i]] + pref[lo][j] - pref[i][j]);
            }
        }

        cout << best << "\n";
    }
    return 0;
}