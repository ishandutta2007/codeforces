#include <bits/stdc++.h>

using namespace std;

const long long INF = 1E18;
const int MAXN = 2000;
int l[MAXN];
int r[MAXN];
int a[MAXN];
long long dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    bool poss = true;
    long long extra = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i] >> a[i];
        if (i && l[i] > r[i - 1])
            extra = 0;
        long long bullets = extra + a[i];
        if (bullets > (long long) (r[i] - l[i] + 1) * k)
        {
            poss = false;
        }
        extra = max(0LL, bullets - (long long) (r[i] - l[i]) * k);
    }
    if (!poss)
    {
        cout << "-1\n";
        return 0;
    }
    dp[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = INF;
        extra = 0;
        long long totalUsed = 0;
        for (int j = i; j < n; j++)
        {
            totalUsed += a[j];
            long long bullets = extra + a[j];
            if (bullets > (long long) (r[j] - l[j] + 1) * k)
                break;
            extra = bullets % k;
            if (j < n - 1)
            {
                long long last = max(0LL, bullets - (long long) (r[j] - l[j]) * k);
                if (r[j] < l[j + 1] || !last)
                {
                    if (extra)
                        dp[i] = min(dp[i], totalUsed + (k - extra) + dp[j + 1]);
                    else
                        dp[i] = min(dp[i], totalUsed + dp[j + 1]);
                }
            }
            else
            {
                dp[i] = min(dp[i], totalUsed);
            }
        }
        //cout << i << " " << dp[i] << endl;
    }
    cout << dp[0] << "\n";
    return 0;
}