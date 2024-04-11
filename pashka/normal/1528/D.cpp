#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = c;
    }
    for (int s = 0; s < n; s++) {
        vector<long> d(n, LLONG_MAX);
        vector<bool> z(n);
        for (int i = 0; i < n; i++) {
            if (g[s][i] == -1) continue;
            d[i] = g[s][i];
        }
        for (int k = 0; k < n; k++) {
            int j = -1;
            for (int i = 0; i < n; i++) {
                if (z[i]) continue;
                if (j == -1 || d[i] < d[j]) j = i;
            }
            z[j] = true;
            for (int i = 0; i < n; i++) {
                if (g[j][i] == -1) continue;
                int ii = (int) ((i + d[j]) % n);
                if (ii == j) {
                    ii = (ii + 1) % n;
                    d[ii] = min(d[ii], d[j] + g[j][i] + 1);
                } else {
                    d[ii] = min(d[ii], d[j] + g[j][i]);
                }
            }
            int jj = (j + 1) % n;
            d[jj] = min(d[jj], d[j] + 1);
        }
        d[s] = 0;
        for (int i = 0; i < n; i++) cout << d[i] << " ";
        cout << "\n";
    }
    return 0;
}