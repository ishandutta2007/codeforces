#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 3000;
int dp[MAXN][MAXN + 1];

void add(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int main()
{
    string s, t;
    cin >> s >> t;
    int n = (int) s.length();
    int m = (int) t.length();
    for (int i = 0; i < m; i++)
        dp[0][i] = 2 * (s[0] == t[i]);
    dp[0][m] = 2;
    int two = 4;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i] == t[j])
                add(dp[i][j], dp[i - 1][j + 1]);
            if (j + i < m)
            {
                if (s[i] == t[j + i])
                    add(dp[i][j], dp[i - 1][j]);
            }
            else
                add(dp[i][j], dp[i - 1][j]);
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
        dp[i][m] = two;
        two = (int) (((long long) two * 2) % MOD);
    }
    int ans = 0;
    for (int i = m - 1; i < n; i++)
        add(ans, dp[i][0]);
    cout << ans << endl;
    return 0;
}