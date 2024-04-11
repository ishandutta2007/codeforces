#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const long long MAXK = 1E18;
long long dp[MAXN + 1];
long long pref[MAXN + 1];
int ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp[0] = pref[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        dp[i] = pref[i - 1];
        pref[i] = dp[i] + pref[i - 1];
        pref[i] = min(pref[i], MAXK);
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;
        k--;
        if (k >= dp[n])
        {
            cout << "-1\n";
            continue;
        }
        int ptr = 0;
        while (ptr < n)
        {
            int old = ptr + 1;
            int num = ptr + 1;
            while (num + 1 <= n && dp[n - num] <= k)
            {
                k -= dp[n - num];
                num++;
            }
            for (int i = num; i >= old; i--)
            {
                ans[ptr++] = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}