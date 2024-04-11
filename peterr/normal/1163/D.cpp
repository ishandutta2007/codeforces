#include <bits/stdc++.h>

using namespace std;

const int NEG = -1E8;
const int MAXN = 1000;
const int MAXS = 50;
int pi1[MAXS];
int pi2[MAXS];
int dp[MAXN][MAXS + 1][MAXS + 1];

void build(int pi[MAXS], string &s)
{
    for (int i = 1; i < (int) s.length(); i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        pi[i] = j;
        if (s[i] == s[j])
            pi[i]++;
    }
}

void pushDP(string &s, string &t, int i, int j, int k, char nextCh)
{
    int x = j;
    if (x == (int) s.length())
        x = pi1[x - 1];
    while (x > 0 && s[x] != nextCh)
        x = pi1[x - 1];
    int y = k;
    if (y == (int) t.length())
        y = pi2[y - 1];
    while (y > 0 && t[y] != nextCh)
        y = pi2[y - 1];
    if (s[x] == nextCh)
        x++;
    if (t[y] == nextCh)
        y++;
    dp[i + 1][x][y] = max(dp[i + 1][x][y], dp[i][j][k] + (x == (int) s.length()) - (y == (int) t.length()));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string c, s, t;
    cin >> c >> s >> t;
    build(pi1, s);
    build(pi2, t);
    for (int i = 0; i < (int) c.length(); i++)
    {
        for (int j = 0; j <= (int) s.length(); j++)
        {
            for (int k = 0; k <= (int) t.length(); k++)
            {
                dp[i][j][k] = NEG;
            }
        }
    }
    if (c[0] == '*')
    {
        dp[0][0][0] = 0;
        if (s[0] == t[0])
        {
            dp[0][1][1] = ((int) s.length() == 1) - ((int) t.length() == 1);
        }
        else
        {
            dp[0][1][0] = (int) s.length() == 1;
            dp[0][0][1] = - ((int) t.length() == 1);
        }
    }
    else
    {
        dp[0][c[0] == s[0]][c[0] == t[0]] = ((int) s.length() == 1) * (s[0] == c[0]) - ((int) t.length() == 1) * (t[0] == c[0]);
    }
    for (int i = 0; i + 1 < (int) c.length(); i++)
    {
        for (int j = 0; j <= (int) s.length(); j++)
        {
            for (int k = 0; k <= (int) t.length(); k++)
            {
                if (dp[i][j][k] == NEG)
                    continue;
                if (c[i + 1] != '*')
                    pushDP(s, t, i, j, k, c[i + 1]);
                else
                {
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        pushDP(s, t, i, j, k, ch);
                    }
                }
                /*
                if (c[i + 1] != '*')
                {
                    int x = j;
                    if (x == (int) s.length())
                        x = pi1[x - 1];
                    while (x > 0 && s[x] != c[i + 1])
                        x = pi1[x - 1];
                    int y = k;
                    if (y == (int) t.length())
                        y = pi2[y - 1];
                    while (y > 0 && t[y] != c[i + 1])
                        y = pi2[y - 1];
                    if (s[x] == c[i + 1])
                        x++;
                    if (t[y] == c[i + 1])
                        y++;
                    dp[i + 1][x][y] = max(dp[i + 1][x][y], dp[i][j][k] + (x == (int) s.length()) - (y == (int) t.length()));
                }
                else
                {
                    dp[i + 1][0][0] = max(dp[i + 1][0][0], dp[i][j][k]);
                    if (j < (int) s.length())
                    {
                        if (k < (int) t.length() && s[j] == t[k])
                            dp[i + 1][j + 1][] = max()
                        else
                            dp[i + 1][j + 1][]
                    }
                    int x = pi1[j - 1];
                    while (x > 0)
                    {

                    }

                }
                */
                //cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
            }
        }
    }
    int ans = NEG;
    for (int i = 0; i <= (int) s.length(); i++)
    {
        for (int j = 0; j <= (int) t.length(); j++)
        {
            ans = max(ans, dp[(int) c.length() - 1][i][j]);
            /*
            if (dp[(int) c.length() - 1][i][j] != NEG)
                cout << (int) c.length() - 1 << " " << i << " " << j << " " << dp[(int) c.length() - 1][i][j] << endl;
            */
        }
    }
    cout << ans << endl;
    return 0;
}