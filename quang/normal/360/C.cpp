#include <bits/stdc++.h>

using namespace std;

const int N = 2020, MOD = 1000000007;

int n, k;
long long a[N][N], b[N][N], c[N][N], suma[N][N];
char s[N];

int main() {
    scanf("%d %d", &n, &k);
    scanf("%s", s + 1);
    a[n + 1][0] = 1;
    suma[n + 1][0] = 1;
    for (int i = n; i; i--) {
        for (int j = 0; j <= k; j++) {
            a[i][j] = (a[i + 1][j] + b[i + 1][j] + c[i + 1][j]) * (s[i] - 'a') % MOD;
        }
        for (int j = 0; j + (n - i + 1) <= k; j++) {
            c[i][j + (n - i + 1)] = (a[i + 1][j] + b[i + 1][j] + c[i + 1][j]) * ('z' - s[i]) % MOD; 
        }                                                                                        
        for (int j = i + 1; j <= n; j++) {
            long long delta = 1ll * (n - j + 1) * (j - i);
            for (int x = 0; delta + x <= k; x++) {
                b[i][delta + x] = (b[i][delta + x] + c[j][x]) % MOD;
            }
        }
        for (int j = 0; j <= k; j++) {
            b[i][j] = (b[i][j] + suma[i + 1][j]) % MOD;
            suma[i][j] = (a[i][j] + suma[i + 1][j]) % MOD;
        }
    }
    printf("%d", (a[1][k] + b[1][k] + c[1][k]) % MOD);
    return 0;   
}