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
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

        vector<bool> v1(n), v2(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1)
                    v1[i] = v2[j] = true;
            }
        }

        int c = 0;
        vector<bool> play1(n), play2(m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!v1[i] and !v2[j])
                    c++, v1[i] = v2[j] = true;
            }
        }

        if (c % 2 == 0) cout << "Vivek\n";
        else cout << "Ashish\n";
    }
    return 0;
}