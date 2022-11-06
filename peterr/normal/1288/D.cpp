#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
const int MAXM = 8;
int dp[1 << MAXM];
int nxt[1 << MAXM];
int where[1 << MAXM];
int a[MAXN + 1][MAXM];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    int ans = -1;
    int aa, b;
    aa = b = 0;
    for (int i = 1; i <= n; i++)
    {
        int best = 1E9 + 7;
        for (int j = 0; j < m; j++)
            best = min(best, a[i][j]);
        if (best > ans)
        {
            ans = best;
            aa = b = i;
        }
    }
    //fill(dp, dp + (1 << m), 1E9);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < (1 << m) - 1; j++)
        {
            int best = 1E9;
            for (int k = 0; k < m; k++)
            {
                if (j & (1 << k))
                {
                    best = min(best, a[i][k]);
                }
            }
            nxt[j] = best;
            if (i > 1)
            {
                int t = min(best, dp[((1 << m) - 1) & (~j)]);
                if (t > ans)
                {
                    ans = t;
                    aa = i;
                    b = where[((1 << m) - 1) & (~j)];
                }
            }
        }
        for (int j = 1; j < (1 << m) - 1; j++)
        {
            if (nxt[j] >= dp[j])
            {
                dp[j] = nxt[j];
                where[j] = i;
            }
        }
    }
    cout << aa << " " << b << endl;
    return 0;
}