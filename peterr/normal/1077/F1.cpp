#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
const long long NEG = -1E18;
int pictures[MAXN + 1];
long long dp[MAXN + 1][MAXN + 1];

int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++)
        cin >> pictures[i];
    for (int i = 1; i <= n; i++)
    {
        if (i <= k)
            dp[1][i] = pictures[i];
        else
            dp[1][i] = NEG;
    }
    for (int i = 2; i <= x; i++)
    {
        deque<pair<long long, int>> deq;
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = NEG;
            long long temp = dp[i - 1][j - 1];
            if (temp != NEG)
            {
                while (!deq.empty() && temp > deq.back().first)
                    deq.pop_back();
                deq.push_back({temp, j - 1});
            }
            if (!deq.empty() && j - deq.front().second > k)
                deq.pop_front();
            if (!deq.empty())
                dp[i][j] = deq.front().first + pictures[j];
        }
    }
    long long ans = -1;
    for (int i = 0; i < k; i++)
        ans = max(ans, dp[x][n - i]);
    cout << ans << endl;
    return 0;
}