#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 1000;
const int MAXA = 1E5;
int a[MAXN];
int cnt[MAXA + 2];
int dp[MAXN + 1][MAXN + 1];

int add(int x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
    if (x < 0)
        x += MOD;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 1; i <= MAXA; i++)
    {
        if (i * (k - 1) > MAXA)
            break;
        int p = n - 1;
        int q = n;
        dp[n][0] = 1;
        while (p >= 0)
        {
            while (q - 1 > p && a[q - 1] - a[p] >= i)
                q--;
            for (int num = 0; num <= k; num++)
            {
                dp[p][num] = dp[p + 1][num];
                if (num)
                    dp[p][num] = add(dp[p][num], dp[q][num - 1]);
            }
            p--;
        }
        cnt[i] = dp[0][k];
    }
    int ans = 0;
    for (int i = 1; i <= MAXA; i++)
    {
        int num = add(cnt[i], -cnt[i + 1]);
        num = (int) ((long long) num * i % MOD);
        ans = add(ans, num);
    }
    cout << ans << "\n";
    return 0;
}