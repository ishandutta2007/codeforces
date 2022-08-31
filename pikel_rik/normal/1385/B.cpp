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

        vector<int> a(2*n), ans;
        for (int i = 0; i < 2*n; i++) cin >> a[i];

        vector<bool> visited(n + 1);
        for (int i = 0; i < 2*n; i++) {
            if (!visited[a[i]])
                ans.push_back(a[i]);
            visited[a[i]] = true;
        }

        for (int i : ans) cout << i << " "; cout << "\n";
    }
    return 0;
}