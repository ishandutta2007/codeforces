
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int dp[MAXN][MAXN];
char blanket[MAXN][MAXN];

int lengthUp(int &i, int j)
{
    if (i < 0)
        return -1;
    int count = 1;
    char c = blanket[i][j];
    while (i - 1 >= 0 && blanket[i - 1][j] == c)
    {
        i--;
        count++;
    }
    return count;
}

bool sameLeft(int rowBot, int rowTop, int col)
{
    for (int r = rowBot; r <= rowTop; r++)
    {
        if (blanket[r][col] != blanket[r][col-1])
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> blanket[i][j];
    long long ans = 0;
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int k = i;
            int L1 = lengthUp(k, j);
            k--;
            int L2 = lengthUp(k, j);
            k--;
            int L3 = lengthUp(k, j);
            if (L1 == L2 && L2 <= L3)
            {
                dp[i][j] = 1;
                if (j >= 1 && dp[i][j-1] > 0 && sameLeft(i - 3 * L1 + 1, i, j))
                {
                    dp[i][j] += dp[i][j-1];
                }
                ans += dp[i][j];
            }
        }
    }
    cout << ans;
    return 0;
}