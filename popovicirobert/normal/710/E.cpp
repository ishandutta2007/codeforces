#include <bits/stdc++.h>
#define MAXN 20000000

using namespace std;

long long dp[MAXN + 2];

int main() {
  //  fstream cin("A.in");
  //  ofstream cout("A.out");
    int i, n, x, y;
    ios::sync_with_stdio(false);
    cin >> n >> x >> y;
    dp[1] = x;
    for(i = 2; i <= n; i++)
        if(i % 2 == 0)
            dp[i] = min(dp[i - 1] + x, dp[i / 2] + y);
        else
            dp[i] = min(dp[i - 1] + x, min(dp[(i + 1) / 2], dp[(i - 1) / 2]) + x + y);
    cout << dp[n];
    //cin.close();
    //cout.close();
    return 0;
}