#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 100;


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, m;
    cin >> m >> n;
    vector<vector<char>> s(m, vector<char>(n + 1));
    for (int i = 0; i < m; ++i) {
        int len;
        cin >> len;
        for (int j = 0; j < len; ++j) {
            int x;
            cin >> x;
            s[i][x] = true;
        }
    }
    
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            bool ok = false;
            for (int k = 1; k <= n; ++k) {
                if (s[i][k] && s[j][k]) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cout << "impossible\n";
                return 0;
            }
        }
    }
    cout << "possible\n";
}