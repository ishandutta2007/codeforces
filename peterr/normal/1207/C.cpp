#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long) 1E18;
const int MAXN = (int) 2E5;
int height[MAXN + 1];
long long dp[MAXN + 1][3];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        for (int i = 0; i <= n; i++)
            height[i] = 1;
        for (int i = 0; i < (int) s.length(); i++)
        {
            if (s[i] == '1')
            {
                height[i] = 2;
                if (i + 1 <= n)
                    height[i + 1] = 2;
            }
        }
        dp[0][1] = b;
        dp[0][2] = INF;
        for (int i = 1; i <= n; i++)
        {
            if (height[i] == 2)
            {
                dp[i][1] = INF;
                dp[i][2] = min(a + dp[i - 1][2] + 2 * b, dp[i - 1][1] + 2 * a + 2 * b);
            }
            else
            {
                dp[i][1] = min(dp[i - 1][1] + a + b, dp[i - 1][2] + 2 * a + b);
                dp[i][2] = min(dp[i - 1][2] + a + 2 * b, dp[i - 1][1] + 2 * a + 2 * b);
            }
            //cout << i << " " << 1 << " " << dp[i][1] << endl;
            //cout << i << " " << 2 << " " << dp[i][2] << endl;
        }
        cout << dp[n][1] << endl;
    }

    return 0;
}