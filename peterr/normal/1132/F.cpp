#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
int n;
string s;
int dp[MAXN][MAXN];

int main()
{
    cin >> n >> s;
    stringstream temp;
    for (int i = 0; i < n; i++)
    {
        temp << s[i];
        while (i + 1 < n && s[i + 1] == s[i])
            i++;
    }
    s = temp.str();
    n = s.length();
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int left = 0; left + i - 1 < n; left++)
        {
            int right = left + i - 1;
            dp[left][right] = 1 + dp[left][right - 1];
            for (int k = right - 2; k >= left; k--)
            {
                if (s[k] == s[right])
                {
                    dp[left][right] = min(dp[left][right], dp[k + 1][right - 1] + dp[left][k]);
                }
            }
        }
    }
    cout << dp[0][n - 1] << endl;

    return 0;
}