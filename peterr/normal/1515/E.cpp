#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400;
int dp[MAXN + 1][MAXN + 1];
int choose[MAXN + 1][MAXN + 1];
int ways[MAXN + 1];

void add(int &x, int y, int m)
{
    x += y;
    if (x >= m)
        x -= m;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= MAXN; i++)
    {
        choose[i][0] = 1;
    }
    for (int i = 1; i <= MAXN; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            add(choose[i][j], choose[i - 1][j], m);
            add(choose[i][j], choose[i - 1][j - 1], m);
        }
    }
    ways[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            add(ways[i], choose[i - 1][j], m);
        }
    }
    //cout << ways[3] << endl;
    //cout << choose[5][2] << endl;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            for (int k = 1; k <= j; k++)
            {
                if (k == i)
                    add(dp[i][j], ways[k], m);
                else if (i - k - 1 >= 1)
                {
                    int temp = (int) ((long long) ways[k] * choose[j][k] % m);
                    temp = (int) ((long long) temp * dp[i - k - 1][j - k] % m);
                    add(dp[i][j], temp, m);
                }

            }
            //cout << "dp " << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        add(ans, dp[n][i], m);
    cout << ans << "\n";
    return 0;
}