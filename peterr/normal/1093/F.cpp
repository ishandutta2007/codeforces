#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MAXK = 100;
const int MOD = 998244353;
int a[MAXN + 1];
int dp[MAXN + 1][MAXK + 1];
int dpSum[MAXN + 1][MAXK + 1];
int total[MAXN + 1];
int last[MAXK + 1];

void add(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
}

int main()
{
    int n, k, len;
    cin >> n >> k >> len;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (len == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    total[0] = total[1] = 1;
    if (a[1] == -1)
    {
        fill(dp[1] + 1, dp[1] + k + 1, 1);
        fill(dpSum[1] + 1, dpSum[1] + k + 1, 1);
        total[1] += k;
    }
    else
    {
        dp[1][a[1]] = 1;
        dpSum[1][a[1]] = 1;
        total[1]++;
        fill(last + 1, last + k + 1, 1);
        last[a[1]] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            last[j] = max(last[j], i - len + 1);
        }
        if (a[i] == -1)
        {
            for (int j = 1; j <= k; j++)
            {
                add(dp[i][j], total[i - 1]);
                add(dp[i][j], -dpSum[i - 1][j]);
                if (last[j])
                {
                    add(dp[i][j], -total[last[j] - 1]);
                    add(dp[i][j], dpSum[last[j] - 1][j]);
                }
            }
        }
        else
        {
            add(dp[i][a[i]], total[i - 1]);
            add(dp[i][a[i]], -dpSum[i - 1][a[i]]);
            if (last[a[i]])
            {
                add(dp[i][a[i]], -total[last[a[i]] - 1]);
                add(dp[i][a[i]], dpSum[last[a[i]] - 1][a[i]]);
            }
            for (int j = 1; j <= k; j++)
            {
                if (j != a[i])
                    last[j] = i;
            }
        }
        total[i] = total[i - 1];
        for (int j = 1; j <= k; j++)
        {
            dpSum[i][j] = dpSum[i - 1][j];
            add(dpSum[i][j], dp[i][j]);
            add(total[i], dp[i][j]);
        }
    }
    /*
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            cout << i << " " << j << " " << dp[i][j] << endl;
    */
    int ans = total[n];
    add(ans, -total[n - 1]);
    cout << ans << endl;
    return 0;
}