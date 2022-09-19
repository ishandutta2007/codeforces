#include <bits/stdc++.h>

using namespace std;
const int c=1005;

long long n, mod=1e9+7, dp[c][c];
long long solve(int a, int b) {
    if (a>b || b<=0 || a<0) {
        return 0;
    }
    if (!dp[a][b]) {
        dp[a][b]=(1+solve(a-2, b)+solve(a, b-2)+2*solve(a-1, b-1))%mod;
    }
    return dp[a][b];
}
int main()
{
    cin >> n;
    cout << solve(n-1, n) << "\n";
    return 0;
}