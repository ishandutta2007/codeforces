#include <cstdio>

using namespace std;

const int N = 1e5 + 500;
const int MOD = 998244353;

int dp[N][205][2], a[N], pref[N], suf[N];

int n, sol = 0;

int main(){
    scanf("%d", &n);

    for(int i = 1;i<=n;i++)
        scanf("%d", a + i);
    if(a[1] != -1)
        for(int x = a[1];x<=200;x++) dp[1][x][0]++;
    else
        for(int x = 1;x<=200;x++) dp[1][x][0]+=x;

    for(int i = 2;i<=n;i++){
        for(int j = 1;j<=200;j++){
            if(a[i] != -1 && a[i] != j) continue;
            if(i != 2 && i != n){
                dp[i][j][0] = (dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0]) % MOD;
                dp[i][j][1] = ((dp[i - 1][j][0] - dp[i - 1][j - 1][0] + MOD) % MOD + (dp[i - 1][200][1] - dp[i - 1][j - 1][1] + MOD) % MOD) % MOD;
            }
            else if(i == 2 && i == n){
                dp[i][j][1] = (dp[i - 1][j][0] - dp[i - 1][j - 1][0] + MOD) % MOD;
            }
            else if(i == 2){
                dp[i][j][0] = dp[i - 1][j - 1][0] % MOD;
                dp[i][j][1] = (dp[i - 1][j][0] - dp[i - 1][j - 1][0] + MOD) % MOD;
            }
            else if(i == n){
                dp[i][j][1] =  ((dp[i - 1][200][1] - dp[i - 1][j - 1][1] + MOD) % MOD + (dp[i - 1][j][0] - dp[i - 1][j - 1][0] + MOD) % MOD) % MOD;
            }
            if(i == n)
                sol = (sol + dp[i][j][1]) % MOD;
        }
        for(int j = 1;j<=200;j++)
            dp[i][j][0] = (dp[i][j][0] + dp[i][j - 1][0]) % MOD;
        for(int j = 1;j<=200;j++)
            dp[i][j][1] = (dp[i][j][1] + dp[i][j - 1][1]) % MOD;
    }
    printf("%d\n", sol);
    return 0;
}