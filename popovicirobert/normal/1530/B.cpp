#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";
 
using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> mat(n + 2, vector<int>(m + 2));

        auto ok = [&](int l, int c) {
            for (int dl : {-1, 0, 1}) {
                for (int dc : {-1, 0, 1}) {
                    if (mat[l + dl][c + dc] == 1) {
                        return false;
                    }
                }
            }
            return true;
        };

        
        for (int i = 1; i <= m; i++) {
            if (ok(1, i)) {
                mat[1][i] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (ok(i, m)) {
                mat[i][m] = 1;
            }
        }

        for (int i = m; i >= 1; i--) {
            if (ok(n, i)) {
                mat[n][i] = 1;
            }
        }

        for (int i = n; i >= 1; i--) {
            if (ok(i, 1)) {
                mat[i][1] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << mat[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}