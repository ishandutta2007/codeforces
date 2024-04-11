#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int d[50][50][50][50];

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            for (int t = n - 1; t >= 0; t--) {
                for (int b = t; b < n; b++) {
                    if (l == r && t == b) {
                        if (a[l][t] == '#') {
                            d[l][r][t][b] = 1;
                        }
                        continue;
                    }
                    if (r - l > b - t) {
                        d[l][r][t][b] = r - l + 1;
                        for (int m = l; m < r; m++) {
                            d[l][r][t][b] = min(d[l][r][t][b],
                                                d[l][m][t][b] + d[m + 1][r][t][b]);
                        }
                    } else {
                        d[l][r][t][b] = b - t + 1;
                        for (int m = t; m < b; m++) {
                            d[l][r][t][b] = min(d[l][r][t][b],
                                                d[l][r][t][m] + d[l][r][m + 1][b]);
                        }
                    }
                }
            }
        }
    }
    cout << d[0][n - 1][0][n - 1];
    return 0;
}