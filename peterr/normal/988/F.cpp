#include <bits/stdc++.h>

using namespace std;

const int INF = 3E8;
const int MAXA = 2000;
int dp[MAXA + 1];
int pre[MAXA + 1];
pair<int, int> umb[MAXA];

int main()
{
    int a, n, m;
    cin >> a >> n >> m;
    fill(pre, pre + a + 1, -1);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        for (int j = l + 1; j <= r; j++)
            pre[j] = j;
        for (int j = r + 1; j <= a; j++)
            pre[j] = max(pre[j], r);
    }
    bool poss = false;
    for (int i = 0; i < m; i++)
    {
        cin >> umb[i].first >> umb[i].second;
        if (pre[umb[i].first] == -1)
            poss = true;
    }
    if (poss)
    {
        for (int i = 1; i <= a; i++)
        {
            if (pre[i] == -1)
                continue;
            dp[i] = INF;
            int target = pre[i];
            for (int j = 0; j < m; j++)
            {
                if (umb[j].first >= target)
                    continue;
                int cost = umb[j].second * (target - umb[j].first);
                dp[i] = min(dp[i], cost + dp[umb[j].first]);
            }
        }
        cout << dp[a] << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}