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
const int N = 1e5 + 5;

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (i > 1 and i + 1 <= n) {
                if (a[i] < a[i-1] and a[i] > a[i + 1])
                    continue;
                if (a[i] > a[i-1] and a[i] < a[i+1])
                    continue;
            }

            ans.push_back(a[i]);
        }

        cout << ans.size() << "\n";
        for (int i : ans) cout << i << " "; cout << "\n";
    }
    return 0;
}