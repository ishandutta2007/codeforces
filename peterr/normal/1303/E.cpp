#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400;
int dp[MAXN + 1][MAXN + 1];

bool check(string s, string x, string y)
{
    int n = (int) x.length();
    int m = (int) y.length();
    for (int i = 1; i <= n; i++)
        dp[0][i] = -1;
    for (int i = 1; i <= (int) s.length(); i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (s[i - 1] == x[j - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            }
            int prev = dp[i - 1][j];
            if (prev != -1 && prev != m)
            {
                if (s[i - 1] == y[prev])
                    dp[i][j] = max(dp[i][j], prev + 1);
            }
        }
    }
    return dp[(int) s.length()][n] == m;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        bool ans = false;
        for (int i = 0; i < (int) t.length(); i++)
        {
            if (check(s, t.substr(0, i), t.substr(i)))
                ans = true;
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}