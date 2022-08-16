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

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 2; j++) {
                if (a[j] > a[j + 1]) {
                    tie(a[j], a[j + 1], a[j + 2]) = make_tuple(a[j + 2], a[j], a[j + 1]);
                    tie(a[j], a[j + 1], a[j + 2]) = make_tuple(a[j + 2], a[j], a[j + 1]);
                    ans.push_back(j);
                    ans.push_back(j);
                }
                else if (a[j + 1] > a[j + 2]) {
                    tie(a[j], a[j + 1], a[j + 2]) = make_tuple(a[j + 2], a[j], a[j + 1]);
                    ans.push_back(j);
                }
            }
        }

        if (is_sorted(all(a))) {
            cout << ans.size() << "\n";
            for (int i : ans) cout << i + 1 << " "; cout << "\n";
        } else cout << "-1\n";
    }
    return 0;
}