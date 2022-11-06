#include <iostream>

using namespace std;

const int MAXN = 2E5;
const long long NEG = -1E18;
int a[MAXN + 1];
long long dp[MAXN + 1][3][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << a[1] << "\n";
        return 0;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            dp[0][i][j] = NEG;
        }
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j][0] = dp[i][j][1] = NEG;
            if (i & 1)
            {
                if (dp[i - 1][(j + 2) % 3][1] != NEG)
                    dp[i][j][1] = max(dp[i][j][1], a[i] + dp[i - 1][(j + 2) % 3][1]);
                if (dp[i - 1][(j + 2) % 3][0] != NEG)
                    dp[i][j][0] = max(dp[i][j][0], a[i] + dp[i - 1][(j + 2) % 3][0]);

                if (dp[i - 1][(j + 1) % 3][1] != NEG)
                    dp[i][j][1] = max(dp[i][j][1], -a[i] + dp[i - 1][(j + 1) % 3][1]);
                if (dp[i - 1][(j + 1) % 3][0] != NEG)
                    dp[i][j][1] = max(dp[i][j][1], -a[i] + dp[i - 1][(j + 1) % 3][0]);
            }
            else
            {
                if (dp[i - 1][(j + 2) % 3][1] != NEG)
                    dp[i][j][1] = max(dp[i][j][1], a[i] + dp[i - 1][(j + 2) % 3][1]);
                if (dp[i - 1][(j + 2) % 3][0] != NEG)
                    dp[i][j][1] = max(dp[i][j][1], a[i] + dp[i - 1][(j + 2) % 3][0]);

                if (dp[i - 1][(j + 1) % 3][1] != NEG)
                    dp[i][j][1] = max(dp[i][j][1], -a[i] + dp[i - 1][(j + 1) % 3][1]);
                if (dp[i - 1][(j + 1) % 3][0] != NEG)
                    dp[i][j][0] = max(dp[i][j][0], -a[i] + dp[i - 1][(j + 1) % 3][0]);
            }
        }
    }
    long long ans = dp[n][1][1];
    if (n % 2 == 0)
        ans = max(ans, dp[n][1][0]);
    cout << ans << "\n";
    return 0;
}