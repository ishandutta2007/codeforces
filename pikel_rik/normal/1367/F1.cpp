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

        vector<int> b = a;
        sort(all(b));

        int best = 0;
        for (int i = 0; i < n; i++) {
            int ptr = i;
            for (int j = 0; j < n && ptr < n; j++) {
                if (a[j] == b[ptr])
                    ptr++;
            }
            best = max(best, ptr - i);
        }

        cout << n - best << "\n";
    }
    return 0;
}