#include <bits/stdc++.h>
using namespace std;

const int MAXN = 600;
int a[MAXN][MAXN], b[MAXN][MAXN];
int n, m;

void make(int i, int j) {
    a[i][j] ^= 1;
    a[i + 1][j] ^= 1;
    a[i][j + 1] ^= 1;
    a[i + 1][j + 1] ^= 1;
}

bool check() {
    bool res = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res &= (a[i][j] == b[i][j]);
        }
    }
    return res;
}

main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            if (a[i][j] != b[i][j]) {
                make(i, j);
            }
        }
    }
    if (check()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}