#include <bits/stdc++.h>

using namespace std;

int dp[40];
int pre[40];
int twoPow[35];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int d, m;
        cin >> d >> m;
        if (m == 1)
        {
            cout << "0\n";
            continue;
        }
        twoPow[0] = 1;
        for (int i = 1; i < 35; i++)
            twoPow[i] = (int) (((long long) twoPow[i - 1] * 2) % m);
        int bits = 32 - __builtin_clz(d);
        int msb = (1 << (bits - 1));
        dp[0] = pre[0] = 1;
        for (int i = 1; i < bits; i++)
        {
            if (i == bits - 1)
            {
                int nums = d - (1 << i) + 1;
                nums %= m;
                int temp = (int) (((long long) nums * pre[i - 1]) % m);
                dp[i] = temp;
                dp[i] += nums;
                if (dp[i] >= m)
                    dp[i] -= m;
            }
            else
            {
                int temp = (int) (((long long) twoPow[i] * pre[i - 1]) % m);
                dp[i] = temp;
                dp[i] += twoPow[i];
                if (dp[i] >= m)
                    dp[i] -= m;
            }
            pre[i] = pre[i - 1] + dp[i];
            if (pre[i] >= m)
                pre[i] -= m;
            //cout << i << " " << dp[i] << endl;
        }
        int ans = 0;
        for (int i = 0; i < bits; i++)
        {
            ans += dp[i];
            if (ans >= m)
                ans -= m;
        }
        cout << ans << endl;
    }
    return 0;
}