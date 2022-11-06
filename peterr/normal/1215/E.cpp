#include <bits/stdc++.h>

using namespace std;

const long long INF = 2E11;
const int MAXN = 4E5;
const int MAXA = 20;
vector<int> pos[MAXA + 1];
long long cost[MAXA + 1][MAXA + 1];
long long dp[1 << MAXA];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }
    for (int i = 1; i <= MAXA; i++)
    {
        for (int j = 1; j <= MAXA; j++)
        {
            if (i == j)
                continue;
            int cnt = 0;
            int x, y;
            x = y = 0;
            int s1 = (int) pos[i].size();
            int s2 = (int) pos[j].size();
            while (x < s1 && y < s2)
            {
                if (pos[i][x] < pos[j][y])
                {
                    cost[i][j] += cnt;
                    x++;
                }
                else
                {
                    cnt++;
                    y++;
                }
            }
            while (x < s1)
            {
                x++;
                cost[i][j] += cnt;
            }
            //cout << i << " " << j << " " << cost[i][j] << endl;
        }
    }
    for (int mask = 1; mask < (1 << MAXA); mask++)
    {
        dp[mask] = INF;
        for (int i = 0; i < MAXA; i++)
        {
            if (mask & (1 << i))
            {
                long long ans = 0;
                for (int j = 0; j < MAXA; j++)
                {
                    if (i == j)
                        continue;
                    if (mask & (1 << j))
                    {
                        ans += cost[i + 1][j + 1];
                    }
                }
                dp[mask] = min(dp[mask], ans + dp[mask ^ (1 << i)]);
            }
        }
        //cout << mask << " " << dp[mask] << endl;
    }
    cout << dp[(1 << MAXA) - 1] << endl;
    return 0;
}