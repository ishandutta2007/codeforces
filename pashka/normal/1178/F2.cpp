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
        a[i]--;
    }
    vector<int> aa;
    for (int i = 0; i < m; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            aa.push_back(a[i]);
        }
    }
    a = aa;
    m = a.size();

    if (m > n * 2) {
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<long>> d(m + 1, vector<long>(m + 1));

    long MOD = 998244353;

    vector<int> ll(n, -1);
    vector<int> rr(n);

    for (int i = 0; i < m; i++) {
        if (ll[a[i]] == -1) {
            ll[a[i]] = i;
        }
        rr[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = ll[i]; j <= rr[i]; j++) {
            if (a[j] < i) {
                cout << 0;
                return 0;
            }
        }
    }

    for (int l = m; l >= 0; l--) {
        for (int r = l; r <= m; r++) {
            if (r - l == 0) {
                d[l][r] = 1;
                continue;
            }
            int x = a[l];
            for (int i = l; i < r; i++) {
                if (a[i] < x) {
                    x = a[i];
                }
            }
            if (ll[x] < l || rr[x] >= r) {
                d[l][r] = 0;
                continue;
            }

            long sl = 0;
            for (int l1 = l; l1 <= ll[x]; l1++) {
                    sl += d[l][l1] * d[l1][ll[x]];
                    sl %= MOD;
            }
            long sr = 0;
            for (int r1 = rr[x] + 1; r1 <= r; r1++) {
                    sr += d[rr[x] + 1][r1] * d[r1][r];
                    sr %= MOD;
            }
            d[l][r] = sl * sr % MOD;
            int last = -1;
            for (int i = ll[x]; i <= rr[x]; i++) {
                if (a[i] == x) {
                    if (last != -1) {
                        d[l][r] *= d[last + 1][i];
                        d[l][r] %= MOD;
                    }
                    last = i;
                }
            }
        }
    }
    cout << d[0][m] << "\n";

    return 0;
}