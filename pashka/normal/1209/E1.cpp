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
    vector<int> d(1 << n);
    vector<int> d2(1 << n);
    vector<int> d3(1 << n);
    for (int i = 0; i < m; i++) {
//        cerr << i << endl;
        for (int k = 0; k < n; k++) {
            for (int x = 0; x < (1 << n); x++) {
                d2[x] = d[x];
            }
            for (int j = 0; j < n; j++) {
                int q = a[i][(j + k) % n];
                for (int x = 0; x < (1 << n); x++) {
                    if (x & (1 << j)) continue;
                    d2[x | (1 << j)] = max(d2[x | (1 << j)], d2[x] + q);
                }
            }
            for (int x = 0; x < (1 << n); x++) {
                d3[x] = max(d3[x], d2[x]);
            }
        }
        for (int x = 0; x < (1 << n); x++) {
            d[x] = d3[x];
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