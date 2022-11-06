#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E5;
bool board[3][MAXN];
int dp[MAXN][8];

int getCost(int col, int pat, int rows)
{
    int ans = 0;
    for (int i = 0; i < rows; i++)
    {
        bool has = (pat & (1 << i)) > 0;
        if (has != board[i][col])
            ans++;
    }
    return ans;
}

void readStuff(int n)
{
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    if (min(n, m) >= 4)
    {
        readStuff(n);
        cout << -1 << "\n";
        return 0;
    }
    if (min(n, m) == 1)
    {
        readStuff(n);
        cout << "0\n";
        return 0;
    }
    int bits = 4;
    if (min(n, m) == 3)
        bits = 8;
    bool tr = false;
    if (n > m)
    {
        tr = true;
    }
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++)
        {
            if (tr)
                board[j][i] = line[j] == '1';
            else
                board[i][j] = line[j] == '1';
        }
    }
    if (tr)
        swap(n, m);
    int mn = min(n, m);
    int mx = max(n, m);
    for (int i = 0; i < bits; i++)
    {
        for (int j = 0; j < mn; j++)
        {
            bool has = (i & (1 << j)) > 0;
            if (board[j][0] != has)
                dp[0][i]++;
        }
    }
    for (int i = 1; i < mx; i++)
    {
        for (int j = 0; j < bits; j++)
        {
            if (bits == 8)
            {
                int other = j ^ 2;
                dp[i][j] = dp[i - 1][other] + getCost(i, j, 3);
                other = j ^ 5;
                dp[i][j] = min(dp[i][j], dp[i - 1][other] + getCost(i, j, 3));
            }
            else
            {
                int other = j ^ 2;
                dp[i][j] = dp[i - 1][other] + getCost(i, j, 3);
                other = j ^ 1;
                dp[i][j] = min(dp[i][j], dp[i - 1][other] + getCost(i, j, 3));
            }
        }
    }
    int ans = dp[mx - 1][0];
    for (int i = 1; i < bits; i++)
        ans = min(ans, dp[mx - 1][i]);
    cout << ans << "\n";
    return 0;
}