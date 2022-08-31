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
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

        if (a[0][0] > 2 or a[n - 1][0] > 2 or a[0][m - 1] > 2 or a[n - 1][m - 1] > 2) {
            cout << "NO\n";
            continue;
        }

        bool bad = false;
        for (int i = 1; i < n - 1; i++) {
            if (a[i][0] > 3 or a[i][m - 1] > 3)
                bad = true;
            a[i][0] = a[i][m - 1] = 3;
        }

        for (int j = 1; j < m - 1; j++) {
            if (a[0][j] > 3 or a[n - 1][j] > 3)
                bad = true;
            a[0][j] = a[n - 1][j] = 3;
        }

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (a[i][j] > 4)
                    bad = true;
                a[i][j] = 4;
            }
        }

        if (bad) {
            cout << "NO\n";
            continue;
        }

        a[0][0] = a[n-1][0] = a[0][m-1] = a[n-1][m-1] = 2;

        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}