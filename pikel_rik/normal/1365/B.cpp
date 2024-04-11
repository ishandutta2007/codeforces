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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first;
        for (int i = 0; i < n; i++) cin >> a[i].second;

        bool flag1 = false, flag2 = false;
        for (int i = 1; i < n; i++) flag1 |= a[i].first < a[i-1].first, flag2 |= a[i].second != a[i-1].second;

        if (flag1 and !flag2) {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";
    }
    return 0;
}