#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int MOD = 1E9 + 7;
int dp[MAXN + 1][MAXN];

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
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        fill(dp[1], dp[1] + n, 0);
        for (int i = 2; i <= k; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                dp[i][j] = 1;
                if (j < n - 1)
                    add(dp[i][j], dp[i][j + 1]);
                if (j)
                    add(dp[i][j], dp[i - 1][n - (j - 1) - 1]);
            }
        }
        cout << 1 + dp[k][0] << "\n";
    }
    return 0;
}