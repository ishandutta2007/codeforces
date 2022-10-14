#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<lint> a;
    vector<int> bit(62);
    for (int i = 0; i < n; i++) {
        lint k;
        cin >> k;
        if (k == 0) {
            continue;
        }
        a.emplace_back(k);
        for (int j = 0; j < 62; j++) {
            if (k & (1ll << j)) {
                bit[j]++;
            }
        }
    }

    for (int j = 0; j < 62; j++) {
        if (bit[j] >= 3) {
            cout << 3 << "\n";
            return 0;
        }
    }

    n = a.size();
    int ans = n + 1;
    vector<vector<int>> dist(n, vector<int>(n, n + 1)), sv;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if ((a[i] & a[j]) > 0) {
                dist[i][j] = dist[j][i] = 1;
            }
        }
    }
    sv = dist;
    for (int p1 = 0; p1 < n; p1++) {
        for (int p2 = 0; p2 < n; p2++) {
            if (dist[p1][p2] == 1) {
                dist[p1][p2] = n + 1;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        for (int k = 0; k < n; k++) {
                            if (dist[i][j] > dist[i][k] + dist[k][j]) {
                                dist[i][j] = dist[i][k] + dist[k][j];
                            }
                        }
                    }
                }
                ans = min(ans, 1 + dist[p1][p2]);
                dist = sv;
            }
        }
    }

    if (ans > n) {
        ans = -1;
    }
    cout << ans << "\n";
    return 0;
}