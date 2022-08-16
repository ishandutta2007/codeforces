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

int n, k, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int j = 0; j < k; j++) cin >> b[j];

        sort(a, a + n);
        sort(b, b + k);
        int ptr = n - 1;

        ll sum = 0;
        for (int i = 0; i < k; i++) {
            if (b[i] == 1)
                sum += 2 * a[ptr--];
            else sum += a[ptr--];
            b[i]--;
        }

        ptr = 0;
        for (int i = k - 1; i >= 0; i--) {
            if (b[i] == 0)
                break;

            sum += a[ptr];
            ptr += b[i];
        }

        cout << sum << "\n";
    }
    return 0;
}