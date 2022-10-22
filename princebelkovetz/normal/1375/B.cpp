#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int inf = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(2);
    int t = 0; cin >> t;
    while (t --> 0) {
        int n, m; cin >> n >> m;
        vector <vector <int>> a(n, vector <int>(m));
        bool check = false;
        for (auto& x : a) {
            for (auto& y : x) {
                cin >> y;
                if (y > 4) check = true;
            }
        }
        if (a[0][0] > 2 or a[0][m - 1] > 2 or a[n - 1][0] > 2 or a[n - 1][m - 1] > 2) check = true;
        for (int i = 0; i < m; ++i) if (a[0][i] > 3) check = true;
        for (int i = 0; i < m; ++i) if (a[n - 1][i] > 3) check = true;
        for (int i = 0; i < n; ++i) if (a[i][0] > 3) check = true;
        for (int i = 0; i < n; ++i) if (a[i][m - 1] > 3) check = true;
        if (check) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (i == 0 and j == 0) cout << 2 << " ";
                    else if (i == 0 and j == m - 1) cout << 2 << " ";
                    else if (i == n - 1 and j == 0) cout << 2 << " ";
                    else if (i == n - 1 and j == m - 1) cout << 2 << " ";
                    else if (i == 0 or i == n - 1 or j == 0 or j == m - 1) cout << 3 << " ";
                    else cout << 4 << " ";
                }
                cout << endl;
            }
        }
    }
}