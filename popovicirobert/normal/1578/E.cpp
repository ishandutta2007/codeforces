#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";
 
 
using namespace std;

constexpr int MAXN = 100;

int comb[MAXN + 1][MAXN + 1];

ll dp[MAXN + 1][MAXN + 1][MAXN + 1];
// dp[len][i][j] = avem i numere cu exact j maxime
// dp[len][i][j] = dp[l][x][j - 1] * dp[len - l - 1][y][j - 1] * comb(len - 1, l);
// j == 1  ==>  x + y + 1 = i
// j != 1  ==>  x + y = i


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m, k, p;
    cin >> n >> m >> k >> p;

    for (int i = 0; i <= n; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % p;
        }
    }


    for (int j = 2; j <= n; j++) {
        dp[j][1][0] = 1;
    }

    int fact = 1;
    for (int len = 1; len <= n; len++) {
        fact = (1LL * fact * len) % p;
        dp[1][len][1] = fact;
    }

    int j;
    int l1;
    int l2;
    int i1;
    int i2;
    int i;
    int len;

    for (j = 1; j < m; j++) {
        for (l1 = 1; l1 < n; l1++) {
            for (i1 = 0; i1 <= k; i1++) {
                if (dp[j][l1][i1] == 0) continue;

                dp[j + 1][l1 + 1][i1] = (dp[j + 1][l1 + 1][i1] + 2LL * dp[j][l1][i1]) % p;

                for (l2 = 1; l1 + l2 < n; l2++) {
                    len = l1 + l2 + 1;
                    for (i2 = 0; i1 + i2 <= k; i2++) {
                        i = i1 + i2;
                        if (dp[j][l2][i2] == 0) continue;

                        dp[j + 1][len][i] = (dp[j + 1][len][i] + (dp[j][l1][i1] * dp[j][l2][i2]) % p * comb[len - 1][l1]) % p;
                    }
                }
            }
        }
    }

    cout << dp[m][n][k];

    
    return 0;
}