#include <cstdio>
#include <cstring>

using namespace std;

const int N = 405;
const int MOD = 1e9 + 7;

int n, m, l;

int main(){
    scanf("%d%d%d", &n, &m, &l);
    if(n > m) {printf("0\n");return 0;}
    int dp[n + 10][n + 10][m + 10];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for(int k = 1;k<=m;k++){
        for(int i = 0;i<=n;i++){
            for(int j = 0;i + j<=n && m - k >= i;j++){
                if(i)
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k-1]) % MOD;
                if(j)
                    dp[i][j][k] = (dp[i][j][k] + dp[i][j - 1][k-1]) % MOD;
                if(k != l){
                    if(j)
                        dp[i][j][k] = (dp[i][j][k] + dp[i + 1][j - 1][k-1]) % MOD;
                    dp[i][j][k] = (dp[i][j][k] + dp[i][j][k-1]) % MOD;
                }
            }
        }
    }
    long long sol = dp[0][n][m];
    for(long long i = 2;i<=n;i++) sol = (sol * i) % MOD;
    printf("%d\n", (int)sol);
    return 0;
}