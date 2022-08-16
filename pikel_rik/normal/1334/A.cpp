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

        vector<int> p(n), c(n);
        for (int i = 0; i < n; i++) cin >> p[i] >> c[i];

        bool flag = p[0] >= c[0];
        for (int i = 1; i < n; i++) {
            flag &= (p[i] >= c[i]);
            flag &= (p[i] >= p[i - 1] && c[i] >= c[i - 1]);
            flag &= (c[i] - c[i - 1] <= p[i] - p[i - 1]);
        }

        if (flag)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}