#include <bits/stdc++.h>

using namespace std;

const int LOGN = 19;
const int MAXN = 3E5;
int dp[MAXN + 2][LOGN + 1];
int a[MAXN + 1];
int nxt[LOGN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    fill(nxt, nxt + LOGN + 1, n + 1);
    for (int i = n; i >= 1; i--)
    {
        fill(dp[i], dp[i] + LOGN + 1, n + 1);
        for (int j = 0; j <= LOGN; j++)
        {
            if (a[i] & (1 << j))
            {
                dp[i][j] = nxt[j];
                if (dp[i][j] < n + 1)
                {
                    for (int k = 0; k <= LOGN; k++)
                    {
                        dp[i][k] = min(dp[i][k], dp[nxt[j]][k]);
                    }
                }
            }
        }
        for (int j = 0; j <= LOGN; j++)
        {
            if (a[i] & (1 << j))
                nxt[j] = i;
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        bool ans = false;
        for (int i = 0; i <= LOGN; i++)
        {
            if ((a[y] & (1 << i)) && dp[x][i] <= y)
                ans = true;
        }
        if (ans)
            cout << "Shi\n";
        else
            cout << "Fou\n";
    }
    return 0;
}