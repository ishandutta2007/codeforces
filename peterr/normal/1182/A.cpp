#include <bits/stdc++.h>

using namespace std;

const int MAXN = 60;
long long dp[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i - 2 >= 0)
            dp[i] += 2 * dp[i-2];
    }
        cout << dp[n];
    return 0;
}