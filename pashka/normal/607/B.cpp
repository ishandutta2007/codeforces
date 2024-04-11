#include <bits/stdc++.h>

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> d(n, vector<int>(n));
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            if (r - l + 1 <= 2 && a[l] == a[r]) {
                d[l][r] = 1;
                continue;
            }
            d[l][r] = INT_MAX;
            if (a[l] == a[r]) {
                d[l][r] = d[l + 1][r - 1];
            }
            for (int k = l; k < r; k++) {
                d[l][r] = min(d[l][r], d[l][k] + d[k + 1][r]);
            }
        }
    }
    cout << d[0][n - 1];

    return 0;
}