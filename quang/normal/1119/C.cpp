#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m;
int a[N][N];
int b[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
            b[i][j] ^= a[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (b[i][j]) {
                b[i][j] ^= 1;
                b[i + 1][j] ^= 1;
                b[i][j + 1] ^= 1;
                b[i + 1][j + 1] ^= 1;
            }
        }
    }
    int found = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            found |= b[i][j];
        }
    }
    cout << (found ? "No" : "Yes") << endl;
    return 0;
}