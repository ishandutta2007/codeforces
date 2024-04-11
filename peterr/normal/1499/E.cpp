#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int MOD = 998244353;
int dp[MAXN + 1][MAXN + 1][2];
int edgeCase1[26][MAXN + 1];
int edgeCase2[26][MAXN + 1];

void add(int &x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
}

void doEdgeCase(string s, int edgeCase[26][MAXN + 1])
{
    int n = (int) s.length() - 1;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[j] - 'a' == i)
                continue;
            edgeCase[i][j] = 1;
            for (int k = j - 1; k >= 1; k--)
            {
                if (s[k] == s[k + 1])
                {
                    break;
                }
                add(edgeCase[i][j], 1);
            }
            //cout << "edge " << i << " " << j << " " << edgeCase[i][j] << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string x, y;
    cin >> x >> y;
    int n = (int) x.length();
    int m = (int) y.length();
    x = "a" + x;
    y = "a" + y;
    doEdgeCase(x, edgeCase1);
    doEdgeCase(y, edgeCase2);
    if (x[1] != y[1])
        dp[1][1][0] = dp[1][1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                continue;
            if (x[i - 1] != x[i])
                add(dp[i][j][0], dp[i - 1][j][0]);
            if (y[j] != x[i])
                add(dp[i][j][0], dp[i - 1][j][1]);
            add(dp[i][j][0], edgeCase2[x[i] - 'a'][j]);

            if (x[i] != y[j])
                add(dp[i][j][1], dp[i][j - 1][0]);
            if (y[j - 1] != y[j])
                add(dp[i][j][1], dp[i][j - 1][1]);
            add(dp[i][j][1], edgeCase1[y[j] - 'a'][i]);

            //cout << "dp " << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            add(ans, dp[i][j][0]);
            add(ans, dp[i][j][1]);
        }
    }
    cout << ans << "\n";
    return 0;
}