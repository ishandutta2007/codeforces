#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    vector<vector<long>> d(n + 1, vector<long>(n + 1));

    long MOD = 998244353;

    for (int l = n; l >= 0; l--) {
        for (int r = l; r <= n; r++) {
            if (r - l <= 1) {
                d[l][r] = 1;
                continue;
            }
            int x = l;
            for (int i = l; i < r; i++) {
                if (a[i] < a[x]) {
                    x = i;
                }
            }
            long sl = 0;
            for (int ll = l; ll <= x; ll++) {
                sl += d[l][ll] * d[ll][x];
                sl %= MOD;
            }
            long sr = 0;
            for (int rr = x + 1; rr <= r; rr++) {
                sr += d[x + 1][rr] * d[rr][r];
                sr %= MOD;
            }
            d[l][r] = sl * sr % MOD;
        }
    }
    cout << d[0][m] << "\n";

    return 0;
}