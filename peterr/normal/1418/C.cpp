#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
bool hard[MAXN + 4];
int dp[MAXN + 4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> hard[i];
        }
        for (int i = 0; i < 4; i++)
        {
            dp[n + i] = 0;
            hard[n + i] = 0;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = hard[i] + dp[i + 2];
            dp[i] = min(dp[i], hard[i] + dp[i + 3]);
            dp[i] = min(dp[i], hard[i] + hard[i + 1] + dp[i + 3]);
            dp[i] = min(dp[i], hard[i] + hard[i + 1] + dp[i + 4]);
        }
        cout << dp[0] << "\n";
    }
    return 0;
}