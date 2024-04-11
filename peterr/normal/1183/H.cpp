#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 100;
const ll MAXK = 1E12;
ll dp[MAXN + 1][MAXN];

int main()
{
    int n;
    ll k;
    string s;
    cin >> n >> k >> s;
    fill(dp[1], dp[1] + n, 1);
    for (int i = 2; i <= n; i++)
    {
        for (int j = i - 1; j < n; j++)
        {
            int visited = 0;
            for (int k = j - 1; k >= 0; k--)
            {
                int key = s[k] - 'a';
                if ((visited & (1 << key)) == 0)
                {
                    dp[i][j] += dp[i - 1][k];
                    visited |= (1 << key);
                }
            }
            dp[i][j] = min(dp[i][j], MAXK);
        }
    }
    ll ans = 0;
    int curLen = n;
    while (k > 0)
    {
        int price = n - curLen;
        if (curLen == 0)
        {
            ans += price;
            k--;
            break;
        }
        int visited = 0;
        for (int i = n - 1; i + 1 >= curLen; i--)
        {
            int key = s[i] - 'a';
            if ((visited & (1 << key)) == 0)
            {
                ans += min(k, dp[curLen][i]) * price;
                k -= min(k, dp[curLen][i]);
                visited |= (1 << key);
            }
        }
        curLen--;
    }
    if (k == 0)
        cout << ans;
    else
        cout << -1;
    return 0;
}