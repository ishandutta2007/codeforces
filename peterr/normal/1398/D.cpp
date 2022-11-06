#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;
int dp[MAXN + 1][MAXN + 1][MAXN + 1];
int r[MAXN + 1];
int g[MAXN + 1];
int b[MAXN + 1];

int main()
{
    int R, G, B;
    cin >> R >> G >> B;
    for (int i = 1; i <= R; i++)
    {
        cin >> r[i];
    }
    for (int i = 1; i <= G; i++)
    {
        cin >> g[i];
    }
    for (int i = 1; i <= B; i++)
    {
        cin >> b[i];
    }
    sort(r + 1, r + R + 1);
    sort(g + 1, g + G + 1);
    sort(b + 1, b + B + 1);
    for (int i = 0; i <= R; i++)
    {
        for (int j = 0; j <= G; j++)
        {
            for (int k = 0; k <= B; k++)
            {
                if (i + j + k < 2)
                    continue;
                if (i && j)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + r[i] * g[j]);
                if (i && k)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + r[i] * b[k]);
                if (j && k)
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + g[j] * b[k]);
            }
        }
    }
    cout << dp[R][G][B] << "\n";
    return 0;
}