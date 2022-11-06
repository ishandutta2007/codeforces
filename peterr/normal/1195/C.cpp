#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
long long heights[2][MAXN];
long long dp[2][MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> heights[0][i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> heights[1][i];
    }
    dp[0][0] = heights[0][0];
    dp[1][0] = heights[1][0];
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = max(heights[0][i] + dp[1][i - 1], dp[0][i - 1]);
        dp[1][i] = max(heights[1][i] + dp[0][i - 1], dp[1][i - 1]);
    }
    cout << max(dp[1][n - 1], dp[0][n - 1]);
    return 0;
}