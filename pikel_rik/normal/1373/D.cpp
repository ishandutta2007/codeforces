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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> temp1, temp2;
        for (int i = 1; i < n; i += 2) {
            temp1.push_back(a[i] - a[i - 1]);
        }
        for (int i = 2; i < n; i += 2) {
            temp2.push_back(a[i] - a[i - 1]);
        }

        ll sum = 0, best = 0;

        for (int i = 0; i < temp1.size(); i++) {
            sum = max(sum + temp1[i], (ll)temp1[i]);
            best = max(best, sum);
        }

        ll best1 = best;

        sum = 0; best = 0;
        for (int i = 0; i < temp2.size(); i++) {
            sum = min(sum + temp2[i], (ll)temp2[i]);
            best = min(best, sum);
        }

        ll best2 = -best;

        sum = 0;
        for (int i = 0; i < n; i += 2)
            sum += a[i];

        cout << max(sum + best1, sum + best2) << "\n";
    }
    return 0;
}