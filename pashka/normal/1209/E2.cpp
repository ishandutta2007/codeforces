#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

void solve_test() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[j][i];
        }
    }
    vector<int> g(1 << n);
    for (int x = 0; x < (1 << n); x++) {
        int xx = x;
        for (int i = 0; i < n; i++) {
            g[x] = max(g[x], xx);
            if (xx & 1) {
                xx |= (1 << n);
            }
            xx >>= 1;
        }
    }

    vector<int> d(1 << n);
    vector<int> d2(1 << n);
    vector<int> d3(1 << n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int q = a[i][j];
            int jj = (1 << j);
            int w = (1 << n) - 1 - jj;
            for (int x = w; ; x = (x - 1) & w) {
                d[x | jj] = max(d[x | jj], d[x] + q);
                if (x == 0) break;
            }
        }
        for (int x = 0; x < (1 << n); x++) {
            d[g[x]] = max(d[g[x]], d[x]);
        }
        for (int x = 0; x < (1 << n); x++) {
            d[x] = d[g[x]];
        }
    }
    cout << d[(1 << n) - 1] << "\n";
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}