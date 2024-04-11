#include <bits/stdc++.h>
using namespace std;
const int maxN = 500;
int n, a[maxN + 10], f[maxN + 10][maxN + 10];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = n; i >= 1; --i)
        for (int j = i; j <= n; ++j) {
            if (i == j) f[i][j] = 1;
            else if (j - i == 1) f[i][j] = a[i] == a[j] ? 1 : 2;
            else {
                f[i][j] = a[i] == a[j] ? f[i + 1][j - 1] : 1e9;
                for (int k = i; k < j; ++k)
                    f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
            }
        }
    printf("%d", f[1][n]);
}