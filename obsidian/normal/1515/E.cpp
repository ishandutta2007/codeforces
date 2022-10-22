#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int V = 410;
int C[V][V];

int f[V], dp[V][V];
int n, P;

int main() {
    while (~scanf("%d%d", &n, &P)) {
        for (int i = 0; i <= n; ++i) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
        }
        for (int i = 1; i <= n; ++i) {
            f[i] = 0;
            for (int j = 1; j <= i; ++j) {
                f[i] = (f[i] + C[i - 1][j - 1]) % P;
            }
            //printf("%d %d\n", i, f[i]);
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (dp[i][j] == 0) continue;
                for (int k = i + 1; k <= n; ++k) {
                    int len = k - i - 1;
                    if (i == 0) len++;
                    if (len == 0) continue;
                    dp[k][j + len] += (LL) dp[i][j] * f[len] % P * C[j + len][j] % P;
                    dp[k][j + len] %= P;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; ++i) ans = (ans + dp[n][i]) % P;
        printf("%d\n", ans);
    }
    return 0;
}

/*
3 100000007
4 100000007
400 234567899
*/