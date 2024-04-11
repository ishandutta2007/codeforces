#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXM = 2E5;
int dp[10][MAXM + 1];

void add(int &x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 10; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= MAXM; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 9)
            {
                add(dp[j][i], dp[0][i - 1]);
                add(dp[j][i], dp[1][i - 1]);
            }
            else
            {
                add(dp[j][i], dp[j + 1][i - 1]);
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        string n;
        int m;
        cin >> n >> m;
        int ans = 0;
        for (char ch : n)
        {
            int dig = ch - '0';
            add(ans, dp[dig][m]);
        }
        cout << ans << "\n";
    }
    return 0;
}