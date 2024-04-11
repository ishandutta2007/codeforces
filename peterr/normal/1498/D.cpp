#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;
const int MAXM = 1E5;
tuple<int, long long, int> a[MAXN];
pair<int, int> dp[MAXM + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(dp, dp + MAXM + 1, make_pair(-1, -1));
    dp[0] = {0, 0};
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int t, y;
        long long x;
        cin >> t >> x >> y;
        for (int j = 0; j <= m; j++)
        {
            int nxt = 0;
            if (t == 1)
                nxt = j + (int) ((x + 99999) / 100000);
            else
                nxt = (int) ((j * x + 99999) / 100000);
            if (nxt > m)
                break;
            if (dp[j].first == -1 || dp[nxt].first != -1)
                continue;
            if (dp[j].first != i)
                dp[nxt] = {i, 1};
            else if (dp[j].second < y)
                dp[nxt] = {i, dp[j].second + 1};
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << dp[i].first << " \n"[i == m];
    }
    return 0;
}