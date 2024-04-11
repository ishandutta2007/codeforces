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
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k, z;
        cin >> n >> k >> z;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int best = 0;
        for (int j = 0; j <= z; j++) {
            int left = j, right = k - j;

            if (left > right)
                continue;

            int cur = accumulate(a.begin(), a.begin() + right - left + 1, 0), temp = 0;

            for (int i = 1; i <= right - left; i++)
                temp = max(temp, a[i] + a[i - 1]);

            if (right - left + 1 < n)
                temp = max(temp, a[right - left] + a[right - left + 1]);

            best = max(best, cur + left * temp);
        }
        cout << best << "\n";
    }
    return 0;
}