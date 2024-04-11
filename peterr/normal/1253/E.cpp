#include <bits/stdc++.h>

using namespace std;

const int MAXN = 80;
const int MAXM = 100000;
int nextPos[MAXM + 1];
pair<int, int> ant[MAXN];
int dp[MAXM + 2];
bool covered[MAXM + 1];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> ant[i].first >> ant[i].second;
        for (int j = max(1, ant[i].first - ant[i].second); j <= min(m, ant[i].first + ant[i].second); j++)
        {
            covered[j] = true;
        }
    }
    nextPos[m] = covered[m] ? m + 1 : m;
    for (int i = m - 1; i >= 1; i--)
    {
        if (!covered[i])
        {
            nextPos[i] = i;
        }
        else
        {
            nextPos[i] = nextPos[i + 1];
        }
    }

    for (int i = m; i >= 1; i--)
    {
        if (covered[i])
        {
            dp[i] = dp[nextPos[i]];
        }
        else
        {
            dp[i] = m - i + 1;
            for (int j = 0; j < n; j++)
            {
                if (ant[j].first > i)
                {
                    int lft = ant[j].first - ant[j].second;
                    int cost = lft - i;
                    int right = ant[j].first + ant[j].second + cost;
                    if (right + 1 <= m)
                        dp[i] = min(dp[i], cost + dp[nextPos[right + 1]]);
                    else
                        dp[i] = min(dp[i], cost);
                    //dp[i] = min(dp[i], cost + dp[nextPos[min(right + 1, m)]]);
                }
            }
        }
    }
    cout << dp[1] << endl;

    return 0;
}