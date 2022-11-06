#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int dp[MAXN + 1];
string ways[4] = {"RL", "RLL", "RRL", "RRLL"};

int solve(int n, string& s)
{
    dp[1] = n;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = n;
        for (string way : ways)
        {
            if ((int) way.length() > i)
                continue;
            int cost = 0;
            int m = (int) way.length();
            for (int j = 0; j < m; j++)
            {
                cost += s[i - j] != way[m - j - 1];
            }
            dp[i] = min(dp[i], dp[i - m] + cost);
        }
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        s = "*" + s;
        int ans = n;
        for (int i = 0; i < 4; i++)
        {
            ans = min(ans, solve(n, s));
            if (i < 3)
            {
                s = "*" + s.substr(2) + s.substr(1, 1);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}