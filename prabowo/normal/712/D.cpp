#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int a, b, k, t;

int dp[200][400005];
int f(int x, int sum) {
    if (x == t * 2) return sum >= 200000;
    if (sum < 0) return 0;
    if (sum > 400000) return f(x, 400000);
    if (~dp[x][sum]) return dp[x][sum];
    
    return dp[x][sum] = (1LL * f(x+1, sum + k) - f(x+1, sum - k - 1) + f(x, sum-1) + MOD) % MOD;
}

int main() {
    scanf ("%d %d %d %d", &a, &b, &k, &t);
    memset (dp, -1, sizeof dp);
        
    for (int i=t*2-1; i; i--) for (int j=0; j<400000; j++) f(i, j);
        
    printf ("%d\n", (f(0, 400000) - f(0, b - a + 200000) + MOD) % MOD );
    return 0;
}