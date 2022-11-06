#include <bits/stdc++.h>

using namespace std;

const int INF = 250000000;
const int MAXN = 5000;
int dp[MAXN + 1][MAXN + 1];

int main()
{
    int n;
    cin >> n;
    vector<int> ppl;
    vector<int> chairs;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x)
            ppl.push_back(i);
        else
            chairs.push_back(i);
    }
    fill(dp[0], dp[0] + MAXN + 1, INF);
    dp[0][0] = 0;
    for (int i = 1; i <= (int) chairs.size(); i++)
    {
        for (int j = 0; j <= (int) ppl.size(); j++)
        {
            dp[i][j] = INF;
            if (j > i)
                continue;
            if (j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(ppl[j - 1] - chairs[i - 1]));
        }
    }
    cout << dp[(int) chairs.size()][(int) ppl.size()] << "\n";
    return 0;
}